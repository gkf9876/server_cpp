#include "GameClient.h"

GameClient::GameClient()
{
	usersInfo = new vector<User*>();								//현재 맵의 다른 유저들
	objectInfo = new vector<MapInfo*>();							//현재 맵의 오브젝트
	monsterInfo = new vector<MapInfo*>();							//현재 맵의 몬스터
	chattingInfo = new vector<Chatting*>();							//현재 맵의 채팅

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
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
	delete chattingInfo;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (inventory_items_Info[i][j] != NULL)
				delete inventory_items_Info[i][j];
		}
	}

	delete log;
}

void GameClient::setMainUser(User user)
{
	this->mainUser = user;
}

User GameClient::getMainUser()
{
	return this->mainUser;
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

void GameClient::moveOtherUser(const char* userName, int xpos, int ypos)
{
	for (int i = 0; i < this->usersInfo->size(); i++)
	{
		if (!strcmp(this->usersInfo->at(i)->getName(), userName))
		{
			User* otherUser = this->usersInfo->at(i);
			otherUser->setXpos(xpos);
			otherUser->setYpos(ypos);
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

void GameClient::addInventoryInfo(InventoryInfo* inventoryInfo)
{
	this->inventory_items_Info[inventoryInfo->getXpos()][inventoryInfo->getYpos()] = inventoryInfo;
}

int GameClient::sizeInventoryInfo()
{
	int size = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (inventory_items_Info[i][j] != NULL)
				size++;
		}
	}

	return size;
}

InventoryInfo GameClient::getInventoryInfo(int xpos, int ypos)
{
	return *this->inventory_items_Info[xpos][ypos];
}

void GameClient::getItem(MapInfo mapInfo)
{
	if (strcmp(mapInfo.getType(), "ITEM"))
		return;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (this->inventory_items_Info[i][j] != NULL && !strcmp(mapInfo.getName(), this->inventory_items_Info[i][j]->getItemName()))
			{
				this->inventory_items_Info[i][j]->setCount(this->inventory_items_Info[i][j]->getCount() + mapInfo.getCount());
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
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

void GameClient::setIsLogin(bool value)
{
	this->isLogin = value;
}

bool GameClient::getIsLogin()
{
	return this->isLogin;
}

void GameClient::setGetUserInfo(bool value)
{
	this->isGetUserInfo = value;
}

bool GameClient::getGetUserInfo()
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
	if(hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if(connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
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
#endif
}

void GameClient::sendc(const char* data, int size)
{
#ifdef _WIN32
	send(hSocket, data, size, 0);
#elif __linux__
	write(hSocket, data, size);
#endif
}

int GameClient::recvc(char* data, int size)
{
#ifdef _WIN32
	return recv(hSocket, data, size, 0);
#elif __linux__
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
}

void GameClient::getUserInfo(const char* userName)
{
	sendRequest(REQUEST_USER_INFO, userName, strlen(userName) + 1);
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
}

void GameClient::requestMapMove(int xpos, int ypos, const char* field)
{
	char message[BUF_SIZE];

	mainUser.setXpos(xpos);
	mainUser.setYpos(ypos);

	if (!strcmp(mainUser.getField(), field))
		mainUser.setAction(ACTION_MAP_MOVE);
	else
	{
		mainUser.setAction(ACTION_MAP_POTAL);
		mainUser.setField(field);
	}

	memcpy(message, &mainUser, sizeof(User));
	sendRequest(USER_MOVE_UPDATE, message, sizeof(User));
}