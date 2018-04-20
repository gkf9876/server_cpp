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
			break;
		}
	}
}

int GameClient::sizeUserInfo()
{
	return this->usersInfo->size();
}

void GameClient::addChattingInfo(Chatting* chatting)
{
	this->chattingInfo->push_back(chatting);
}

int GameClient::sizeChattingInfo()
{
	return this->chattingInfo->size();
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
	chatting.setInputdate("sysdate()");
	chatting.setName(mainUser.getName());
	chatting.setContent(chattingInfo);
	chatting.setField(mainUser.getField());

	memcpy(message, &chatting, sizeof(Chatting));
	sendRequest(CHATTING_PROCESS, message, sizeof(Chatting));
}