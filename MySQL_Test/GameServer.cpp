#include "GameServer.h"

GameServer::GameServer(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->userService = new UserService(dataSource);
}

GameServer::~GameServer()
{
	delete this->userService;
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
					FD_CLR(reads.fd_array[i], &reads);
					//updateLogout(cpyReads.fd_array[i]);
					closesocket(cpyReads.fd_array[i]);
				}
				else
				{
					try
					{
						switch (code)
						{
						case REQUEST_USER_INFO:			//\C0\AF\C0\FA \C1\A4\BA\B8 \BF\E4û\BD\C3
							getUserInfo(reads.fd_array[i], buffer);
							break;
						case CHATTING_PROCESS:			//ä\C6ý\C3
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_LOGIN:				//\B7α\D7\C0\CE \BD\C2\C0ν\C3
							updateLogin(reads.fd_array[i], buffer);
							break;
						case USER_MOVE_UPDATE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case OTHER_USER_MAP_MOVE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case REQUEST_JOIN:			//\C0\AF\C0\FA ȸ\BF\F8\B0\A1\C0Խ\C3
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
						case UPDATE_LOGIN_TIME:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
							//\BF\EC\C0\FA\B0\A1 Ÿ\C0ϸ\CA \C0ڷ\E1 \BF\E4û\BD\C3
						case REQUEST_TILED_MAP:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
							//\C0\AF\C0\FA\B0\A1 \C0̹\CC\C1\F6 \C0ڷ\E1 \BF\E4û\BD\C3
						case REQUEST_IMAGE:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
							//\C0\AF\C0\FA\B0\A1 \B6\A5\BF\A1 \B6\B3\BE\EE\C1\F8 \BE\C6\C0\CC\C5\DB\C0\BB \B8\D4\C0\BB\BD\C3
						case DELETE_FIELD_ITEM:
							sendRequest(reads.fd_array[i], code, buffer, size);
							break;
							//\B8\CA\C1\A4\BA\B8\B8\A6 \BAҷ\AF\BFö\A7
						case REQUEST_FIELD_ITEM_INFO:
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
		sendRequest(sock, REQUEST_ERROR, error.what(), strlen(error.what()));
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogin(SOCKET sock, const char* name)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User loginUser;

	try
	{
		loginUser = userService->getUserInfo(name);
		userService->updateLogin(sock, name);

		loginUserList = userService->getFieldLoginUserAll(loginUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			loginUser.setAction(ACTION_MAP_IN);

			memcpy(message, &loginUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogout(const char* name)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User logoutUser;

	try
	{
		logoutUser = userService->getUserInfo(name);
		userService->updateLogout(name);

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
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

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
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
			printf("connected client : %d\n", hClntSock);
			clientCount++;
		}
		else
		{
			strLen = recvRequest(ep_events[i].data.fd, &code, buffer);
			size = strLen - 8;
			if(strLen == 0)
			{
				epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
				close(ep_events[i].data.fd);
				printf("closed client : %d\n", ep_events[i].data.fd);
				clientCount--;
			}
			else
			{
				try
				{
					switch (code)
					{
					case REQUEST_USER_INFO:			//\C0\AF\C0\FA \C1\A4\BA\B8 \BF\E4û\BD\C3
						getUserInfo(ep_events[i].data.fd, buffer);
						break;
					case CHATTING_PROCESS:			//ä\C6ý\C3
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_LOGIN:				//\B7α\D7\C0\CE \BD\C2\C0ν\C3
						updateLogin(ep_events[i].data.fd, buffer);
						break;
					case USER_MOVE_UPDATE:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case OTHER_USER_MAP_MOVE:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case REQUEST_JOIN:			//\C0\AF\C0\FA ȸ\BF\F8\B0\A1\C0Խ\C3
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
					case UPDATE_LOGIN_TIME:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
						//\BF\EC\C0\FA\B0\A1 Ÿ\C0ϸ\CA \C0ڷ\E1 \BF\E4û\BD\C3
					case REQUEST_TILED_MAP:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
						//\C0\AF\C0\FA\B0\A1 \C0̹\CC\C1\F6 \C0ڷ\E1 \BF\E4û\BD\C3
					case REQUEST_IMAGE:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
						//\C0\AF\C0\FA\B0\A1 \B6\A5\BF\A1 \B6\B3\BE\EE\C1\F8 \BE\C6\C0\CC\C5\DB\C0\BB \B8\D4\C0\BB\BD\C3
					case DELETE_FIELD_ITEM:
						sendRequest(ep_events[i].data.fd, code, buffer, size);
						break;
						//\B8\CA\C1\A4\BA\B8\B8\A6 \BAҷ\AF\BFö\A7
					case REQUEST_FIELD_ITEM_INFO:
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

	try
	{
		loginUser = userService->getUserInfo(name);
		userService->updateLogin(sock, name);

		loginUserList = userService->getFieldLoginUserAll(loginUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if(iter->getSock() == sock)
				continue;

			loginUser.setAction(ACTION_MAP_IN);

			memcpy(message, &loginUser, sizeof(User));
			sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void GameServer::updateLogout(const char* name)
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User logoutUser;

	try
	{
		logoutUser = userService->getUserInfo(name);
		userService->updateLogout(name);

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
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

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
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

#endif
