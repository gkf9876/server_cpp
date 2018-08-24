#include "GameClient.h"

GameClient::GameClient()
{
	mainUser.setLogin(0);

	usersInfo = new vector<User*>();								//현재 맵의 다른 유저들
	objectInfo = new vector<MapInfo*>();							//현재 맵의 오브젝트
	monsterInfo = new vector<MapInfo*>();							//현재 맵의 몬스터
	itemInfo = new vector<MapInfo*>();
	chattingInfo = new vector<Chatting*>();							//현재 맵의 채팅

	for (int i = 0; i < INVENTORY_X_SIZE; i++)
	{
		for (int j = 0; j < INVENTORY_Y_SIZE; j++)
		{
			inventory_items_Info[i][j] = NULL;
		}
	}

	log = new vector<string>();
}

GameClient::~GameClient()
{
	delete usersInfo;
	delete objectInfo;
	delete monsterInfo;
	delete itemInfo;
	delete chattingInfo;

	for (int i = 0; i < INVENTORY_X_SIZE; i++)
	{
		for (int j = 0; j < INVENTORY_Y_SIZE; j++)
		{
			if (inventory_items_Info[i][j] != NULL)
				delete inventory_items_Info[i][j];
		}
	}

	delete log;
}

void GameClient::recvRun()
{
	char message[1024];
	int code;

	try
	{
		while (logout != true)
		{
			recvRequest(&code, message);

			switch (code)
			{
			case REQUEST_USER_INFO:
				if (!strcmp(message, "unknown_id_send_fail"))
					isGetUserInfo = true;
				else
				{
					User user;
					memcpy(&user, message, sizeof(User));
					setMainUser(user);
					isGetUserInfo = true;
				}
				break;
			case REQUEST_LOGIN:
				if (!strcmp(message, "login okey"))
				{
					isLogin = true;
					isRequestLoginFinish = true;
				}
				else
				{
					isLogin = false;
					popupLoginFail = true;
					isRequestLoginFinish = true;
				}
				break;
			case CHATTING_PROCESS:
			{
				Chatting mainChatting;
				memcpy(&mainChatting, message, sizeof(Chatting));
				this->mainChatting = mainChatting;

				Chatting* chatting = new Chatting();
				memcpy(chatting, &mainChatting, sizeof(Chatting));
				addChattingInfo(chatting);
			}
			break;
			case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
					this->usersInfo->push_back(user);
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					removeUsersInfo(user->getName());
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					moveOtherUser(user->getName(), user->getXpos(), user->getYpos(), user->getSeeDirection());
					delete user;
				}
			}
			break;
			case REQUEST_JOIN:
				if (!strcmp(message, "join_user_success"))
					isJoinUserSeccess = true;
				else
					isJoinUserSeccess = false;
				break;
			case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				removeItemInfo(itemInfo.getIdx());
			}
			break;
			case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				this->objectInfo->push_back(objectInfo);
			}
			break;
			case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				this->monsterInfo->push_back(monsterInfo);
			}
			break;
			case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				this->inventory_items_Info[inventoryInfo->getXpos()][inventoryInfo->getYpos()] = inventoryInfo;
			}
			break;
			case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				this->itemInfo->push_back(itemInfo);
			}
			break;
			case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				this->inventory_items_Info[inventoryInfo->getXpos()][inventoryInfo->getYpos()] = inventoryInfo;
			}
			break;
			case REQUEST_LOGOUT:
				if (!strcmp(message, "logout okey"))
				{
					closeClient();
					logout = true;
				}
				break;
			case REQUEST_MAP_MOVE:
			{
				User userInfo;
				memcpy(&userInfo, message, sizeof(User));
				mainUser = userInfo;

				if (userInfo.getAction() == ACTION_MAP_MOVE)
				{

				}
				else if (userInfo.getAction() == ACTION_MAP_POTAL)
				{
					usersInfo->clear();
					objectInfo->clear();
					monsterInfo->clear();
					itemInfo->clear();
				}
			}
			break;
			case REQUEST_MAP_POTAL_FINISH:
				if (!strcmp(message, "map_potal_finish"))
				{
					mainUser.setAction(ACTION_MAP_IN);
					isMapPotalFinish = true;
				}
				break;
			case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				isThrowItemFinish = true;
				removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
			case REQUEST_GET_ITEM_FINISH:
				if (!strcmp(message, "get_item_finish"))
					isGetItemFinish = true;
				break;
			case REQUEST_CHATTING_FINISH:
				if (!strcmp(message, "chatting_finish"))
					isChattingFinish = true;
				break;
			case REQUEST_MAP_MOVE_FINISH:
				if (!strcmp(message, "map_move_finish"))
					isMapMoveFinish = true;
				break;
			case UPDATE_USER_INFO:
			{
				User userInfo;
				memcpy(&userInfo, message, sizeof(User));

				updateUserInfo(userInfo);
			}
			break;
			case UPDATE_USER_INFO_FINISH:
				if (!strcmp(message, "update_user_finish"))
					isUpdateUserInfoFinish = true;
				break;
			case REQUEST_JOIN_FINISH:
				if (!strcmp(message, "join_user_finish"))
					isJoinUserFinish = true;
				break;
			case OTHER_USER_CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				addChattingInfo(chatting);
			}
			break;
			case MOVE_INVENTORY_ITEM:
				{
					int xpos, ypos;
					InventoryInfo* inventoryInfo = new InventoryInfo();
					memcpy(inventoryInfo, message, sizeof(InventoryInfo));

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							if (inventory_items_Info[i][j] != NULL
								&& !strcmp(inventoryInfo->getItemName(), inventory_items_Info[i][j]->getItemName())
								&& !strcmp(inventoryInfo->getUserName(), inventory_items_Info[i][j]->getUserName()))
							{
								xpos = i;
								ypos = j;
							}
						}
					}

					moveInventoryInfo(xpos, ypos, inventoryInfo->getXpos(), inventoryInfo->getYpos());
				}
				break;
			case MOVE_INVENTORY_ITEM_FINISH:
				if (!strcmp(message, "move_inventory_item_finish"))
					isMoveItemFinish = true;
				break;
			case TEST:
				break;
			default:
				break;
			}
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient : " << error.what() << std::endl;
	}
}

void GameClient::setMainUser(User user)
{
	this->mainUser = user;
}

User GameClient::getMainUser()
{
	return this->mainUser;
}

void GameClient::setMainUserAction(int value)
{
	mainUser.setAction(value);
}

int GameClient::getMainUserAction()
{
	return mainUser.getAction();
}

void GameClient::setMainChatting(Chatting chatting)
{
	this->mainChatting = chatting;
}

Chatting GameClient::getMainChatting()
{
	return this->mainChatting;
}

void GameClient::addUsersInfo(User* user)
{
	this->usersInfo->push_back(user);
}

void GameClient::removeUsersInfo(const char* userName)
{
	for (int i = 0; i < this->usersInfo->size(); i++)
	{
		User* userInfo = this->usersInfo->at(i);

		if (!strcmp(userInfo->getName(), userName))
		{
			this->usersInfo->erase(this->usersInfo->begin() + i);
			return;
		}
	}
}

int GameClient::sizeUserInfo()
{
	return this->usersInfo->size();
}

User GameClient::getUsersInfo(int idx)
{
	return *(this->usersInfo->at(idx));
}

void GameClient::moveOtherUser(const char* userName, int xpos, int ypos, int seeDirection)
{
	for (int i = 0; i < this->usersInfo->size(); i++)
	{
		if (!strcmp(this->usersInfo->at(i)->getName(), userName))
		{
			User* otherUser = this->usersInfo->at(i);
			otherUser->setXpos(xpos);
			otherUser->setYpos(ypos);
			otherUser->setSeeDirection(seeDirection);
			otherUser->setAction(ACTION_MAP_MOVE);
			return;
		}
	}
}

User GameClient::getUsersInfo(const char* name)
{
	for (int i = 0; i < this->usersInfo->size(); i++)
	{
		if (!strcmp(this->usersInfo->at(i)->getName(), name))
			return *this->usersInfo->at(i);
	}

	User unknownUser;
	unknownUser.setName("unknown_id");
	unknownUser.setField("unknown_field");

	return unknownUser;
}

void GameClient::clearUsersInfo()
{
	this->usersInfo->clear();
}

void GameClient::updateUserInfo(User user)
{
	for (int i = 0; i < this->usersInfo->size(); i++)
	{
		if (!strcmp(this->usersInfo->at(i)->getName(), user.getName()))
		{
			this->usersInfo->at(i)->setSock(user.getSock());
			this->usersInfo->at(i)->setName(user.getName());
			this->usersInfo->at(i)->setPassword(user.getPassword());
			this->usersInfo->at(i)->setXpos(user.getXpos());
			this->usersInfo->at(i)->setYpos(user.getYpos());
			this->usersInfo->at(i)->setField(user.getField());
			this->usersInfo->at(i)->setSeeDirection(user.getSeeDirection());
			this->usersInfo->at(i)->setAction(user.getAction());
			this->usersInfo->at(i)->setLogin(user.getLogin());
			this->usersInfo->at(i)->setLastLogin(user.getLastLogin());
			this->usersInfo->at(i)->setLastLogout(user.getLastLogout());
			this->usersInfo->at(i)->setJoinDate(user.getJoinDate());
			return;
		}
	}
}

void GameClient::addObjectInfo(MapInfo* object)
{
	this->objectInfo->push_back(object);
}

int GameClient::sizeObjectInfo()
{
	return this->objectInfo->size();
}

MapInfo GameClient::getObjectInfo(int idx)
{
	return *(this->objectInfo->at(idx));
}

void GameClient::clearObjectInfo()
{
	this->objectInfo->clear();
}

void GameClient::addMonsterInfo(MapInfo* monster)
{
	this->monsterInfo->push_back(monster);
}

int GameClient::sizeMonsterInfo()
{
	return this->monsterInfo->size();
}

MapInfo GameClient::getMonsterInfo(int idx)
{
	return *(this->monsterInfo->at(idx));
}

void GameClient::clearMonsterInfo()
{
	this->monsterInfo->clear();
}

void GameClient::addItemInfo(MapInfo* itemInfo)
{
	this->itemInfo->push_back(itemInfo);
}

int GameClient::sizeItemInfo()
{
	return this->itemInfo->size();
}

MapInfo GameClient::getItemInfo(int idx)
{
	return *(this->itemInfo->at(idx));
}

void GameClient::clearItemInfo()
{
	this->itemInfo->clear();
}

void GameClient::removeItemInfo(int idx)
{
	for (int i = 0; i < this->itemInfo->size(); i++)
	{
		MapInfo* mapInfo = this->itemInfo->at(i);

		if (mapInfo->getIdx() == idx)
		{
			this->itemInfo->erase(this->itemInfo->begin() + i);
			return;
		}
	}
}

void GameClient::addChattingInfo(Chatting* chatting)
{
	this->chattingInfo->push_back(chatting);
}

int GameClient::sizeChattingInfo()
{
	return this->chattingInfo->size();
}

Chatting GameClient::getChattingInfo(int idx)
{
	return *(this->chattingInfo->at(idx));
}

vector<Chatting> GameClient::getChattingInfo()
{
	vector<Chatting> chattingInfo;

	for (int i = 0; i < this->chattingInfo->size(); i++)
	{
		chattingInfo.push_back(*this->chattingInfo->at(i));
	}

	return chattingInfo;
}

void GameClient::addInventoryInfo(InventoryInfo* inventoryInfo)
{
	this->inventory_items_Info[inventoryInfo->getXpos()][inventoryInfo->getYpos()] = inventoryInfo;
}

int GameClient::sizeInventoryInfo()
{
	int size = 0;

	for (int i = 0; i < INVENTORY_X_SIZE; i++)
	{
		for (int j = 0; j < INVENTORY_Y_SIZE; j++)
		{
			if (inventory_items_Info[i][j] != NULL)
				size++;
		}
	}

	return size;
}

InventoryInfo* GameClient::getInventoryInfo(int xpos, int ypos)
{
	if (xpos >= INVENTORY_X_SIZE || ypos >= INVENTORY_Y_SIZE || xpos < 0 || ypos < 0)
		return NULL;
	else
		return this->inventory_items_Info[xpos][ypos];
}

void GameClient::getItem(MapInfo mapInfo)
{
	if (strcmp(mapInfo.getType(), "ITEM"))
		return;

	for (int i = 0; i < INVENTORY_X_SIZE; i++)
	{
		for (int j = 0; j < INVENTORY_Y_SIZE; j++)
		{
			if (this->inventory_items_Info[i][j] != NULL && !strcmp(mapInfo.getName(), this->inventory_items_Info[i][j]->getItemName()))
			{
				this->inventory_items_Info[i][j]->setCount(this->inventory_items_Info[i][j]->getCount() + mapInfo.getCount());
				return;
			}
		}
	}

	for (int i = 0; i < INVENTORY_X_SIZE; i++)
	{
		for (int j = 0; j < INVENTORY_Y_SIZE; j++)
		{
			if (this->inventory_items_Info[i][j] != NULL)
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				inventoryInfo->setItemName(mapInfo.getName());
				inventoryInfo->setUserName(mainUser.getName());
				inventoryInfo->setType(mapInfo.getType());
				inventoryInfo->setXpos(i);
				inventoryInfo->setYpos(j);
				inventoryInfo->setFileDir(mapInfo.getFileDir());
				inventoryInfo->setCount(mapInfo.getCount());
				this->inventory_items_Info[i][j] = inventoryInfo;
				return;
			}
		}
	}
}

void GameClient::removeInventoryInfo(int xpos, int ypos)
{
	if (xpos >= INVENTORY_X_SIZE || ypos >= INVENTORY_Y_SIZE || xpos < 0 || ypos < 0)
		return;
	else if (inventory_items_Info[xpos][ypos] != NULL)
	{
		delete inventory_items_Info[xpos][ypos];
		inventory_items_Info[xpos][ypos] = NULL;
	}
}

void GameClient::moveInventoryInfo(int xpos, int ypos, int to_xpos, int to_ypos)
{
	InventoryInfo* temp = inventory_items_Info[xpos][ypos];
	inventory_items_Info[xpos][ypos] = inventory_items_Info[to_xpos][to_ypos];
	inventory_items_Info[to_xpos][to_ypos] = temp;
}

void GameClient::setIsLogin(bool value)
{
	this->isLogin = value;
}

bool GameClient::getIsLogin()
{
	return this->isLogin;
}

void GameClient::setIsGetUserInfo(bool value)
{
	this->isGetUserInfo = value;
}

bool GameClient::getIsGetUserInfo()
{
	return this->isGetUserInfo;
}

void GameClient::setPopupLoginFail(bool value)
{
	this->popupLoginFail = value;
}

bool GameClient::getPopupLoginFail()
{
	return this->popupLoginFail;
}

void GameClient::setIsRequestLoginFinish(bool value)
{
	this->isRequestLoginFinish = value;
}

bool GameClient::getIsRequestLoginFinish()
{
	return this->isRequestLoginFinish;
}

void GameClient::setIsGetObjectInfo(bool value)
{
	this->isGetObjectInfo = value;
}

bool GameClient::getIsGetObjectInfo()
{
	return this->isGetObjectInfo;
}

void GameClient::setIsGetMonsterInfo(bool value)
{
	this->isGetMonsterInfo = value;
}

bool GameClient::getIsGetMonsterInfo()
{
	return this->isGetMonsterInfo;
}

void GameClient::setIsGetItemInfo(bool value)
{
	this->isGetItemInfo = value;
}

bool GameClient::getIsGetItemInfo()
{
	return this->isGetItemInfo;
}

void GameClient::setIsGetInventoryInfo(bool value)
{
	this->isGetInventoryInfo = value;
}

bool GameClient::getIsGetInventoryInfo()
{
	return this->isGetInventoryInfo;
}

void GameClient::setIsMapPotalFinish(bool value)
{
	this->isMapPotalFinish = value;
}

bool GameClient::getIsMapPotalFinish()
{
	return this->isMapPotalFinish;
}

void GameClient::setIsThrowItemFinish(bool value)
{
	this->isThrowItemFinish = value;
}

bool GameClient::getIsThrowItemFinish()
{
	return this->isThrowItemFinish;
}

void GameClient::setIsGetItemFinish(bool value)
{
	this->isGetItemFinish = value;
}

bool GameClient::getIsGetItemFinish()
{
	return this->isGetItemFinish;
}

void GameClient::setIsMoveItemFinish(bool value)
{
	this->isMoveItemFinish = value;
}

bool GameClient::getIsMoveItemFinish()
{
	return this->isMoveItemFinish;
}

void GameClient::setIsChattingFinish(bool value)
{
	this->isChattingFinish = value;
}

bool GameClient::getIsChattingFinish()
{
	return this->isChattingFinish;
}

void GameClient::setIsMapMoveFinish(bool value)
{
	this->isMapMoveFinish = value;
}

bool GameClient::getIsMapMoveFinish()
{
	return this->isMapMoveFinish;
}

void GameClient::setIsUpdateUserInfoFinish(bool value)
{
	this->isUpdateUserInfoFinish = value;
}

bool GameClient::getIsUpdateUserInfoFinish()
{
	return this->isUpdateUserInfoFinish;
}

void GameClient::setIsJoinUserFinish(bool value)
{
	this->isJoinUserFinish = value;
}

bool GameClient::getIsJoinUserFinish()
{
	return this->isJoinUserFinish;
}

void GameClient::setIsJoinUserSeccess(bool value)
{
	this->isJoinUserSeccess = value;
}

bool GameClient::getIsJoinUserSeccess()
{
	return this->isJoinUserSeccess;
}

void GameClient::setLogout(bool value)
{
	this->logout = value;
}

bool GameClient::getLogout()
{
	return this->logout;
}

void GameClient::addLog(string message)
{
	log->push_back(message);
}

void GameClient::printAllLog()
{
	string message;

	for (int i = 0; i < log->size(); i++)
	{
		message = log->at(i);
		cout << message.c_str() << endl;
	}
}

void GameClient::ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void GameClient::openClient(const char* addr, int port)
{
#ifdef _WIN32
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");
#elif __linux__
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("connect() error!");
#elif __APPLE__
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("connect() error!");
#endif
}

void GameClient::closeClient()
{
#ifdef _WIN32
	closesocket(hSocket);
	WSACleanup();
#elif __linux__
	close(hSocket);
#elif __APPLE__
	close(hSocket);
#endif
}

void GameClient::sendc(const char* data, int size)
{
#ifdef _WIN32
	send(hSocket, data, size, 0);
#elif __linux__
	write(hSocket, data, size);
#elif __APPLE__
	write(hSocket, data, size);
#endif
}

int GameClient::recvc(char* data, int size)
{
#ifdef _WIN32
	return recv(hSocket, data, size, 0);
#elif __linux__
	return read(hSocket, data, size);
#elif __APPLE__
	return read(hSocket, data, size);
#endif
}

void GameClient::sendRequest(int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	sendc(buffer, size + 8);
	free(buffer);
}

int GameClient::recvRequest(int* code, char* data)
{
	int size;
	int readLen;
	char buffer[BUF_SIZE];

	readLen = recvc(buffer, 4);
	memcpy(&size, buffer, sizeof(int));

	readLen += recvc(buffer, 4);
	memcpy(code, buffer, sizeof(int));

	readLen += recvc(data, size);

	return readLen;
}

void GameClient::requestLogin(const char * userName)
{
	sendRequest(REQUEST_LOGIN, userName, strlen(userName) + 1);

	while (this->isRequestLoginFinish != true);
	this->isRequestLoginFinish = false;
}

void GameClient::getUserInfo(const char* userName)
{
	sendRequest(REQUEST_USER_INFO, userName, strlen(userName) + 1);

	while (isGetUserInfo != true);
	isGetUserInfo = false;
}

void GameClient::requestLogout()
{
	sendRequest(REQUEST_LOGOUT, mainUser.getName(), strlen(mainUser.getName()) + 1);
}

void GameClient::chatting(const char* chattingInfo)
{
	char message[BUF_SIZE];
	Chatting chatting;
	chatting.setName(mainUser.getName());
	chatting.setContent(chattingInfo);
	chatting.setField(mainUser.getField());

	memcpy(message, &chatting, sizeof(Chatting));
	sendRequest(CHATTING_PROCESS, message, sizeof(Chatting));

	while (isChattingFinish != true);
	isChattingFinish = false;
}

void GameClient::requestMapMove(int xpos, int ypos, const char* field, int seeDirection)
{
	char message[BUF_SIZE];
	User sendUserInfo = mainUser;

	sendUserInfo.setXpos(xpos);
	sendUserInfo.setYpos(ypos);
	sendUserInfo.setSeeDirection(seeDirection);

	if (!strcmp(mainUser.getField(), field))
	{
		sendUserInfo.setAction(ACTION_MAP_MOVE);

		memcpy(message, &sendUserInfo, sizeof(User));
		sendRequest(USER_MOVE_UPDATE, message, sizeof(User));

		while (isMapMoveFinish != true);
		isMapMoveFinish = false;
	}
	else
	{
		sendUserInfo.setAction(ACTION_MAP_POTAL);
		sendUserInfo.setField(field);

		memcpy(message, &sendUserInfo, sizeof(User));
		sendRequest(USER_MOVE_UPDATE, message, sizeof(User));

		while (isMapPotalFinish != true);
		isMapPotalFinish = false;
	}
}

void GameClient::requestThrowItem(int xpos, int ypos)
{
	char message[BUF_SIZE];
	memcpy(message, inventory_items_Info[xpos][ypos], sizeof(InventoryInfo));

	sendRequest(REQUEST_THROW_ITEM, message, sizeof(InventoryInfo));

	while (isThrowItemFinish != true);
	isThrowItemFinish = false;
}

void GameClient::requestGetItem()
{
	char message[BUF_SIZE];
	memcpy(message, &mainUser, sizeof(User));

	sendRequest(REQUEST_EAT_ITEM, message, sizeof(User));

	while (isGetItemFinish != true);
	isGetItemFinish = false;
}

void GameClient::requestMoveItem(int xpos, int ypos, int to_xpos, int to_ypos)
{
	char message[BUF_SIZE];

	inventory_items_Info[xpos][ypos]->setXpos(to_xpos);
	inventory_items_Info[xpos][ypos]->setYpos(to_ypos);
	memcpy(message, inventory_items_Info[xpos][ypos], sizeof(InventoryInfo));

	sendRequest(MOVE_INVENTORY_ITEM, message, sizeof(InventoryInfo));

	while (isMoveItemFinish != true);
	isMoveItemFinish = false;
}

void GameClient::requestUpdateUserInfo()
{
	char message[BUF_SIZE];
	memcpy(message, &mainUser, sizeof(User));

	sendRequest(UPDATE_USER_INFO, message, sizeof(User));

	while (isUpdateUserInfoFinish != true);
	isUpdateUserInfoFinish = false;
}

void GameClient::requestJoinUser(User userInfo)
{
	char message[BUF_SIZE];
	memcpy(message, &userInfo, sizeof(User));

	sendRequest(REQUEST_JOIN, message, sizeof(User));

	while (isJoinUserFinish != true);
	isJoinUserFinish = false;
}
