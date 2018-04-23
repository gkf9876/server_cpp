#include "GameServer.h"

GameServer::GameServer(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->userService = new UserService(dataSource);
	this->chattingService = new ChattingService(dataSource);
	this->mapManageService = new MapManageService(dataSource);
}

GameServer::~GameServer()
{
	delete this->userService;
	delete this->chattingService;
	delete this->mapManageService;
}

void GameServer::ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void GameServer::openServer(int port)
{
#ifdef _WIN32
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = port;

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	FD_ZERO(&reads);
	FD_SET(hServSock, &reads);
#elif __linux__
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = port;

	if(bind(hServSock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("bind() error");
	if(listen(hServSock, 5) == -1)
		ErrorHandling("listen() error");

	epfd = epoll_create(EPOLL_SIZE);
	ep_events = (struct epoll_event*)malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

	event.events = EPOLLIN;
	event.data.fd = hServSock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, hServSock, &event);

	clientCount = 0;
#endif
}

void GameServer::closeServer()
{
#ifdef _WIN32
	closesocket(hServSock);
	WSACleanup();
#elif __linux__
	close(hServSock);
	close(epfd);
#endif
}

#ifdef _WIN32
void GameServer::accept_win()
{
	int code;
	int size;

	cpyReads = reads;
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;

	if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
		return;

	for (int i = 0; i < reads.fd_count; i++)
	{
		if (FD_ISSET(reads.fd_array[i], &cpyReads))
		{
			if (reads.fd_array[i] == hServSock)
			{
				adrSz = sizeof(clntAddr);
				hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &adrSz);
				FD_SET(hClntSock, &reads);
			}
			else
			{
				strLen = recvRequest(reads.fd_array[i], &code, buffer);
				size = strLen - 8;
				if (strLen == 0)
				{
					updateLogout(cpyReads.fd_array[i]);
					printf("closed client : %d\n", cpyReads.fd_array[i]);

					FD_CLR(reads.fd_array[i], &reads);
					closesocket(cpyReads.fd_array[i]);
				}
				else
				{
					try
					{
						switch (code)
						{
						case REQUEST_USER_INFO:
							getUserInfo(reads.fd_array[i], buffer);
							break;
						case CHATTING_PROCESS:
							chatting(reads.fd_array[i], buffer);
							break;
						case REQUEST_LOGIN:
							updateLogin(reads.fd_array[i], buffer);
							break;
						case USER_MOVE_UPDATE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case OTHER_USER_MAP_MOVE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_JOIN:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case UPDATE_LOGIN_TIME:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_TILED_MAP:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_IMAGE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case DELETE_FIELD_ITEM:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_FIELD_OBJECT_INFO:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_FIELD_MONSTER_INFO:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_INVENTORY_ITEM_INFO:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case MOVE_INVENTORY_ITEM:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case THROW_ITEM:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case ATTACK_FILED_OBJECT:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_LOGOUT:
							{
								updateLogout(cpyReads.fd_array[i]);
								printf("closed client : %d\n", cpyReads.fd_array[i]);

								FD_CLR(reads.fd_array[i], &reads);
								closesocket(cpyReads.fd_array[i]);
								printf("recv requestLogout : %s\n", buffer);
							}
							break;
						default:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						}
					}
					catch (const runtime_error& error)
					{
						std::cout << '\t' << error.what() << std::endl;
					}
				}
			}
		}
	}
}

void GameServer::sends(SOCKET sock, const char* data, int size)
{
	send(sock, data, size, 0);
}

int GameServer::recvs(SOCKET sock, char* data, int size)
{
	return recv(sock, data, size, 0);
}

void GameServer::sendRequest(SOCKET sock, int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	send(sock, buffer, size + 8, 0);
	delete buffer;
}

int GameServer::recvRequest(SOCKET sock, int* code, char* data)
{
	int size;
	int readLen1, readLen2, readLen3;
	char buffer[BUF_SIZE];

	if ((readLen1 = recv(sock, buffer, 4, 0)) == 0)
		return 0;
	memcpy(&size, buffer, sizeof(int));

	if ((readLen2 = recv(sock, buffer, 4, 0)) == 0)
		return 0;
	memcpy(code, buffer, sizeof(int));

	if ((readLen3 = recv(sock, data, size, 0)) == size)
		return (readLen1 + readLen2 + readLen3);
	else
		return 0;
}

int GameServer::getClientCount()
{
	return reads.fd_count;
}

void GameServer::getUserInfo(SOCKET sock, const char* name)
{
	char message[BUF_SIZE];

	try
	{
		User getUser = userService->getUserInfo(name);
		memcpy(message, &getUser, sizeof(User));

		sendRequest(sock, REQUEST_USER_INFO, message, sizeof(User));
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_ERROR, error.what(), strlen(error.what()) + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogin(SOCKET sock, const char* name)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User loginUser;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	list<InventoryInfo> inventoryList;
	list<InventoryInfo>::iterator inventoryIter;

	try
	{
		userService->updateLogin(sock, name);
		loginUser = userService->getUserInfo(name);
		sendRequest(sock, REQUEST_LOGIN, "login okey", strlen("login okey") + 1);

		loginUserList = userService->getFieldLoginUserAll(loginUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			memcpy(message, &loginUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

			iter->setAction(ACTION_MAP_IN);
			memcpy(message, &(*iter), sizeof(User));
			sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
		}

		mapMonsterList = mapManageService->getFieldMonster(loginUser.getField());

		for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
		{
			memcpy(message, &(*monsterIter), sizeof(MapInfo));
			sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
		}

		mapObjectList = mapManageService->getFieldObject(loginUser.getField());

		for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
		{
			memcpy(message, &(*objectIter), sizeof(MapInfo));
			sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
		}

		inventoryList = userService->getUserInventoryInfo(loginUser.getName());

		for (inventoryIter = inventoryList.begin(); inventoryIter != inventoryList.end(); inventoryIter++)
		{
			memcpy(message, &(*inventoryIter), sizeof(InventoryInfo));
			sendRequest(sock, REQUEST_INVENTORY_ITEM_INFO, message, sizeof(InventoryInfo));
		}
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_LOGIN, "login fail", strlen("login fail"));
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogout(SOCKET sock)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User logoutUser;

	try
	{
		logoutUser = userService->getUserInfo(sock);
		userService->updateLogout(logoutUser.getName());
		sendRequest(sock, REQUEST_LOGOUT, "logout okey", strlen("logout okey") + 1);

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			logoutUser.setAction(ACTION_MAP_OUT);
			memcpy(message, &logoutUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
		sendRequest(sock, REQUEST_LOGOUT, "logout fail", strlen("logout fail") + 1);
	}
}


void GameServer::chatting(SOCKET sock, const char* chatting)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User chattingUser;
	Chatting chattingInfo;

	try
	{
		chattingUser = userService->getUserInfo(sock);
		loginUserList = userService->getFieldLoginUserAll(chattingUser.getField());

		memcpy(&chattingInfo, chatting, sizeof(Chatting));
		chattingService->add(chattingInfo);

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			memcpy(message, &chatting, sizeof(Chatting));
			sendRequest(iter->getSock(), CHATTING_PROCESS, message, sizeof(Chatting));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateMoveInfo(SOCKET sock, const char* userInfo)
{
	char message[BUF_SIZE];
	User moveUser;
	list<User> fieldUserList, regionFieldUserList;
	list<User>::iterator iter;
	User user;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	try
	{
		memcpy(&user, userInfo, sizeof(User));

		if (user.getAction() == ACTION_MAP_MOVE)
		{
			sendRequest(sock, REQUEST_MAP_MOVE, "map_move_success", strlen("map_move_success") + 1);

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, userInfo, sizeof(User));
			}

		}
		else if (user.getAction() == ACTION_MAP_POTAL)
		{
			sendRequest(sock, REQUEST_MAP_MOVE, "map_potal_success", strlen("map_potal_success") + 1);

			moveUser = userService->getUserInfo(user.getName());
			regionFieldUserList = userService->getFieldLoginUserAll(userService->getUserInfo(user.getName()).getField());
			moveUser.setAction(ACTION_MAP_OUT);

			for (iter = regionFieldUserList.begin(); iter != regionFieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &moveUser, sizeof(User));
				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			user.setAction(ACTION_MAP_IN);
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &user, sizeof(User));
				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

				iter->setAction(ACTION_MAP_IN);
				memcpy(message, &(*iter), sizeof(User));
				sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			mapMonsterList = mapManageService->getFieldMonster(user.getField());

			for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
			{
				memcpy(message, &(*monsterIter), sizeof(MapInfo));
				sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
			}

			mapObjectList = mapManageService->getFieldObject(user.getField());

			for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
			{
				memcpy(message, &(*objectIter), sizeof(MapInfo));
				sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
			}
		}
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_MAP_MOVE, "map_move_fail", strlen("map_move_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#elif __linux__
void GameServer::accept_linux()
{
	int code;
	int size;

	event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
	if(event_cnt == -1)
	{
		puts("epoll_wait() error");
		return;
	}

	for(int i=0; i<event_cnt; i++)
	{
		if(ep_events[i].data.fd == hServSock)
		{
			adr_sz = sizeof(clntAddr);
			hClntSock = accept(hServSock, (struct sockaddr*)&clntAddr, &adr_sz);
			event.events = EPOLLIN;
			event.data.fd = hClntSock;
			epoll_ctl(epfd, EPOLL_CTL_ADD, hClntSock, &event);
			clientCount++;
		}
		else
		{
			strLen = recvRequest(ep_events[i].data.fd, &code, buffer);
			size = strLen - 8;
			if(strLen == 0)
			{
				updateLogout(ep_events[i].data.fd);
				clientCount--;

				epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
				close(ep_events[i].data.fd);
			}
			else
			{
				try
				{
					switch (code)
					{
					case REQUEST_USER_INFO:
						getUserInfo(ep_events[i].data.fd, buffer);
						break;
					case CHATTING_PROCESS:
						chatting(ep_events[i].data.fd, buffer);
						break;
					case REQUEST_LOGIN:
						updateLogin(ep_events[i].data.fd, buffer);
						break;
					case USER_MOVE_UPDATE:
						updateMoveInfo(ep_events[i].data.fd, buffer);
						break;
					case OTHER_USER_MAP_MOVE:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_JOIN:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case UPDATE_LOGIN_TIME:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_TILED_MAP:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_IMAGE:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case DELETE_FIELD_ITEM:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_FIELD_OBJECT_INFO:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_FIELD_MONSTER_INFO:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_INVENTORY_ITEM_INFO:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case MOVE_INVENTORY_ITEM:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case THROW_ITEM:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case ATTACK_FILED_OBJECT:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_LOGOUT:
						{
							updateLogout(ep_events[i].data.fd);
							clientCount--;

							epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
							close(ep_events[i].data.fd);
						}
						break;
					default:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					}
				}
				catch (const runtime_error& error)
				{
					std::cout << '\t' << error.what() << std::endl;
				}
			}
		}
	}
}

void GameServer::sends(int sock, const char* data, int size)
{
	write(sock, data, size);
}

int GameServer::recvs(int sock, char* data, int size)
{
	return read(sock, data, size);
}

void GameServer::sendRequest(int sock, int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	write(sock, buffer, size + 8);
	delete buffer;
}

int GameServer::recvRequest(int sock, int* code, char* data)
{
	int size;
	int readLen1, readLen2, readLen3;
	char buffer[BUF_SIZE];

	if ((readLen1 = read(sock, buffer, 4)) == 0)
		return 0;
	memcpy(&size, buffer, sizeof(int));

	if ((readLen2 = read(sock, buffer, 4)) == 0)
		return 0;
	memcpy(code, buffer, sizeof(int));

	if ((readLen3 = read(sock, data, size)) == size)
		return (readLen1 + readLen2 + readLen3);
	else
		return 0;
}

int GameServer::getClientCount()
{
	return clientCount;
}

void GameServer::getUserInfo(int sock, const char* name)
{
	char message[BUF_SIZE];

	try
	{
		User getUser = userService->getUserInfo(name);
		memcpy(message, &getUser, sizeof(User));

		sendRequest(sock, REQUEST_USER_INFO, message, sizeof(User));
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_ERROR, error.what(), strlen(error.what()));
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogin(int sock, const char* name)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User loginUser;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	list<InventoryInfo> inventoryList;
	list<InventoryInfo>::iterator inventoryIter;

	try
	{
		userService->updateLogin(sock, name);
		loginUser = userService->getUserInfo(name);
		sendRequest(sock, REQUEST_LOGIN, "login okey", strlen("login okey") + 1);

		loginUserList = userService->getFieldLoginUserAll(loginUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			memcpy(message, &loginUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

			iter->setAction(ACTION_MAP_IN);
			memcpy(message, &(*iter), sizeof(User));
			sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
		}

		mapMonsterList = mapManageService->getFieldMonster(loginUser.getField());

		for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
		{
			memcpy(message, &(*monsterIter), sizeof(MapInfo));
			sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
		}

		mapObjectList = mapManageService->getFieldObject(loginUser.getField());

		for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
		{
			memcpy(message, &(*objectIter), sizeof(MapInfo));
			sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
		}

		inventoryList = userService->getUserInventoryInfo(loginUser.getName());

		for (inventoryIter = inventoryList.begin(); inventoryIter != inventoryList.end(); inventoryIter++)
		{
			memcpy(message, &(*inventoryIter), sizeof(InventoryInfo));
			sendRequest(sock, REQUEST_INVENTORY_ITEM_INFO, message, sizeof(InventoryInfo));
		}
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_LOGIN, "login fail", strlen("login fail"));
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogout(int sock)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User logoutUser;

	try
	{
		logoutUser = userService->getUserInfo(sock);
		userService->updateLogout(logoutUser.getName());
		sendRequest(sock, REQUEST_LOGOUT, "logout okey", strlen("logout okey") + 1);

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			logoutUser.setAction(ACTION_MAP_OUT);
			memcpy(message, &logoutUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::chatting(int sock, const char* chatting)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User chattingUser;
	Chatting chattingInfo;

	try
	{
		chattingUser = userService->getUserInfo(sock);
		loginUserList = userService->getFieldLoginUserAll(chattingUser.getField());

		memcpy(&chattingInfo, chatting, sizeof(Chatting));
		chattingService->add(chattingInfo);

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			memcpy(message, chatting, sizeof(Chatting));
			sendRequest(iter->getSock(), CHATTING_PROCESS, message, sizeof(Chatting));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateMoveInfo(int sock, const char* userInfo)
{
	char message[BUF_SIZE];
	User moveUser;
	list<User> fieldUserList, regionFieldUserList;
	list<User>::iterator iter;
	User user;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	try
	{
		memcpy(&user, userInfo, sizeof(User));

		if (user.getAction() == ACTION_MAP_MOVE)
		{
			sendRequest(sock, REQUEST_MAP_MOVE, "map_move_success", strlen("map_move_success") + 1);

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, userInfo, sizeof(User));
			}

		}
		else if (user.getAction() == ACTION_MAP_POTAL)
		{
			sendRequest(sock, REQUEST_MAP_MOVE, "map_potal_success", strlen("map_potal_success") + 1);

			moveUser = userService->getUserInfo(user.getName());
			regionFieldUserList = userService->getFieldLoginUserAll(userService->getUserInfo(user.getName()).getField());
			moveUser.setAction(ACTION_MAP_OUT);

			for (iter = regionFieldUserList.begin(); iter != regionFieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &moveUser, sizeof(User));
				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			user.setAction(ACTION_MAP_IN);
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &user, sizeof(User));
				sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

				iter->setAction(ACTION_MAP_IN);
				memcpy(message, &(*iter), sizeof(User));
				sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			mapMonsterList = mapManageService->getFieldMonster(user.getField());

			for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
			{
				memcpy(message, &(*monsterIter), sizeof(MapInfo));
				sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
			}

			mapObjectList = mapManageService->getFieldObject(user.getField());

			for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
			{
				memcpy(message, &(*objectIter), sizeof(MapInfo));
				sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
			}
		}
	}
	catch (const runtime_error& error)
	{
		sendRequest(sock, REQUEST_MAP_MOVE, "map_move_fail", strlen("map_move_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#endif

void GameServer::regenMonster()
{
	this->mapManageService->regenMonster();
}