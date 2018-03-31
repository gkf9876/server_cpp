#include "GameServerTest.h"

int flag;

GameServerTest::GameServerTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->userDao = new UserDao(this->dataSource);
	this->gameServer = new GameServer(this->dataSource);
	
	for (int i = 0; i < 10; i++)
	{
		this->gameClient[i] = new GameClient();
	}

	for(int i=0; i<10; i++)
	{
		char imsi[1024];
		this->user[i].setSock(0);
		sprintf(imsi, "abcd%d", i);
		this->user[i].setName(imsi);
		sprintf(imsi, "abc%d", i);
		this->user[i].setPassword(imsi);
		this->user[i].setXpos(10 + i);
		this->user[i].setYpos(12 + i);
		sprintf(imsi, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx%d", i);
		this->user[i].setField(imsi);
		this->user[i].setSeeDirection(29 + i);
		this->user[i].setAction(50 + i);
		this->user[i].setLogin(0);
		sprintf(imsi, "2018-03-17 00:42:%02d", i);
		this->user[i].setLastLogin(imsi);
		sprintf(imsi, "2018-03-17 00:43:%02d", i);
		this->user[i].setLastLogout(imsi);
		sprintf(imsi, "2018-01-01 00:00:%02d", i);
		this->user[i].setJoinDate(imsi);
	}
}

GameServerTest::~GameServerTest()
{
	delete this->gameServer;
	delete this->userDao;
	delete this->dataSource;

	for (int i = 0; i < 10; i++)
	{
		delete this->gameClient[i];
	}
}

void GameServerTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void GameServerTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void GameServerTest::checkSameUser(User user1, User user2)
{
	assertThat(user1.getSock(), user2.getSock());
	assertThat(user1.getName(), user2.getName());
	assertThat(user1.getPassword(), user2.getPassword());
	assertThat(user1.getXpos(), user2.getXpos());
	assertThat(user1.getYpos(), user2.getYpos());
	assertThat(user1.getField(), user2.getField());
	assertThat(user1.getSeeDirection(), user2.getSeeDirection());
	assertThat(user1.getAction(), user2.getAction());
	assertThat(user1.getLogin(), user2.getLogin());
	assertThat(user1.getLastLogin(), user2.getLastLogin());
	assertThat(user1.getLastLogout(), user2.getLastLogout());
	assertThat(user1.getJoinDate(), user2.getJoinDate());
}

void GameServerTest::run()
{
	userDao->deleteAll();

	user[1].setField(user[0].getField());
	user[2].setField(user[0].getField());

	for(int i=0; i<10; i++)
	{
		userDao->add(user[i]);
	}
#ifdef _WIN32
	flag = 1;
	hServerThread = (HANDLE)_beginthreadex(NULL, 0, ServerThreadFunc, this, 0, NULL);
	WaitForSingleObject(hServerThread, 5);

	hClientThread[0] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc0, this, 0, NULL);
	hClientThread[1] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc1, this, 0, NULL);
	hClientThread[2] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc2, this, 0, NULL);
	hClientThread[3] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc3, this, 0, NULL);
	hClientThread[4] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc4, this, 0, NULL);
	hClientThread[5] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc5, this, 0, NULL);
	hClientThread[6] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc6, this, 0, NULL);
	hClientThread[7] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc7, this, 0, NULL);
	hClientThread[8] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc8, this, 0, NULL);
	hClientThread[9] = (HANDLE)_beginthreadex(NULL, 0, ClientThreadFunc9, this, 0, NULL);

	//connectAndClose();
	//connectCount10();
	//protocolComunication();
	//getUserInfo();
	//updateLogin();

	WaitForSingleObject(hClientThread[0], INFINITE);
	WaitForSingleObject(hClientThread[1], INFINITE);
	WaitForSingleObject(hClientThread[2], INFINITE);
	WaitForSingleObject(hClientThread[3], INFINITE);
	WaitForSingleObject(hClientThread[4], INFINITE);
	WaitForSingleObject(hClientThread[5], INFINITE);
	WaitForSingleObject(hClientThread[6], INFINITE);
	WaitForSingleObject(hClientThread[7], INFINITE);
	WaitForSingleObject(hClientThread[8], INFINITE);
	WaitForSingleObject(hClientThread[9], INFINITE);
	printf("Hello World\n");
	flag = 0;

	WaitForSingleObject(hServerThread, INFINITE);
#elif __linux__
	flag = 1;
	pthread_create(&hServerThread, NULL, ServerThreadFunc, this);
	sleep(0.005);

	pthread_create(&hClientThread[0], NULL, ClientThreadFunc0, this);
	pthread_create(&hClientThread[1], NULL, ClientThreadFunc1, this);
	pthread_create(&hClientThread[2], NULL, ClientThreadFunc2, this);
	pthread_create(&hClientThread[3], NULL, ClientThreadFunc3, this);
	pthread_create(&hClientThread[4], NULL, ClientThreadFunc4, this);
	pthread_create(&hClientThread[5], NULL, ClientThreadFunc5, this);
	pthread_create(&hClientThread[6], NULL, ClientThreadFunc6, this);
	pthread_create(&hClientThread[7], NULL, ClientThreadFunc7, this);
	pthread_create(&hClientThread[8], NULL, ClientThreadFunc8, this);
	pthread_create(&hClientThread[9], NULL, ClientThreadFunc9, this);

	pthread_join(hClientThread[0], &thr_ret);
	pthread_join(hClientThread[1], &thr_ret);
	pthread_join(hClientThread[2], &thr_ret);
	pthread_join(hClientThread[3], &thr_ret);
	pthread_join(hClientThread[4], &thr_ret);
	pthread_join(hClientThread[5], &thr_ret);
	pthread_join(hClientThread[6], &thr_ret);
	pthread_join(hClientThread[7], &thr_ret);
	pthread_join(hClientThread[8], &thr_ret);
	pthread_join(hClientThread[9], &thr_ret);
	//flag = 0;

	pthread_join(hServerThread, &thr_ret);
#endif
}

GameServer* GameServerTest::getGameServer()
{
	return this->gameServer;
}

GameClient* GameServerTest::getGameClient(int idx)
{
	return this->gameClient[idx];
}

UserDao* GameServerTest::getUserDao()
{
	return this->userDao;
}

User GameServerTest::getUser(int idx)
{
	return this->user[idx];
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ServerThreadFunc(void* arg)
#elif __linux__
void* GameServerTest::ServerThreadFunc(void* arg)
#endif
{
	GameServer * gameServer = ((GameServerTest*)arg)->getGameServer();
	char message[1024];

	gameServer->openServer(9190);

	while (flag != 0)
	{
#ifdef _WIN32
		gameServer->accept_win();
#elif __linux__
		gameServer->accept_linux();
#endif
	}

	gameServer->closeServer();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc0(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc0(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(0);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc0, arg);
#endif

	gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(0).getName(), strlen(gameServerTest->getUser(0).getName()) + 1);
#ifdef _WIN32
	Sleep(5);
#elif __linux__
	sleep(0.005);
#endif

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc0(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc0(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(0);

	while(1)
	{
		gameClient->recvRequest(&code, message);
		switch(code)
		{
		case OTHER_USER_MAP_MOVE:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				printf("code : %d, name : %s\n", code, user.getName());
			}
			break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc1(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc1(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(1);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc1, arg);
#endif

	gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(1).getName(), strlen(gameServerTest->getUser(1).getName()) + 1);
#ifdef _WIN32
	Sleep(5);
#elif __linux__
	sleep(0.005);
#endif

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc1(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc1(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(1);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				printf("code : %d, name : %s\n", code, user.getName());
			}
			break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc2(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc2(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(2);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc2, arg);
#endif

	gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(2).getName(), strlen(gameServerTest->getUser(2).getName()) + 1);
#ifdef _WIN32
	Sleep(5);
#elif __linux__
	sleep(0.005);
#endif

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc2(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc2(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(2);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				printf("code : %d, name : %s\n", code, user.getName());
			}
			break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc3(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc3(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(3);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc3, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(3).getName(), strlen(gameServerTest->getUser(3).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc3(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc3(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(3);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc4(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc4(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(4);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc4, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(4).getName(), strlen(gameServerTest->getUser(4).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc4(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc4(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(4);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc5(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc5(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(5);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc5, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(5).getName(), strlen(gameServerTest->getUser(5).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc5(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc5(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(5);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc6(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc6(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(6);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc6, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(6).getName(), strlen(gameServerTest->getUser(6).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc6(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc6(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(6);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc7(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc7(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(7);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc7, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(7).getName(), strlen(gameServerTest->getUser(7).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc7(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc7(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(7);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc8(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc8(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(8);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc8, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(8).getName(), strlen(gameServerTest->getUser(8).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc8(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc8(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(8);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientThreadFunc9(void* arg)
#elif __linux__
void* GameServerTest::ClientThreadFunc9(void* arg)
#endif
{
	char message[1024];
	int code;
	int count = 0;
#ifdef _WIN32
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(9);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc9, arg);
#endif

	{
		gameClient->sendRequest(REQUEST_LOGIN, gameServerTest->getUser(9).getName(), strlen(gameServerTest->getUser(9).getName()) + 1);
#ifdef _WIN32
		Sleep(5);
#elif __linux__
		sleep(0.005);
#endif
	}

	while (flag != 0);
#ifdef _WIN32
#elif __linux__
	pthread_cancel(recvThread);
#endif
	gameClient->closeClient();
#ifdef _WIN32
	return 0;
#endif
}

#ifdef _WIN32
unsigned WINAPI GameServerTest::ClientRecvThreadFunc9(void* arg)
#elif __linux__
void* GameServerTest::ClientRecvThreadFunc9(void* arg)
#endif
{
	char message[1024];
	int code;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	UserDao* userDao = gameServerTest->getUserDao();
	GameClient* gameClient = gameServerTest->getGameClient(9);

	while (1)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case OTHER_USER_MAP_MOVE:
		{
			User user;
			memcpy(&user, message, sizeof(User));
			printf("code : %d, name : %s\n", code, user.getName());
		}
		break;
		default:
			printf("code : %d, message : %s\n", code, message);
			break;
		}
	}

#ifdef _WIN32
	return 0;
#endif
}
