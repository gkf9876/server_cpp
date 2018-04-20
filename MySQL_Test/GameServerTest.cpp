#include "GameServerTest.h"

int flag = 1;

GameServerTest::GameServerTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->userDao = new UserDao(this->dataSource);
	this->gameServer = new GameServer(this->dataSource);
	this->mapDao = new MapDao(this->dataSource);
	this->mapInfoDao = new MapInfoDao(this->dataSource);
	this->monsterDao = new MonsterDao(this->dataSource);
	this->chattingDao = new ChattingDao(this->dataSource);
	
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

#ifdef _WIN32
	InitializeCriticalSection(&cs);
#elif __linux__
	pthread_mutex_init(&mutex, NULL);
#endif

	this->map1 = new Map();
	map1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	map1->setMonster1("다람쥐");
	map1->setMonster2("사슴");
	map1->setMonster3("호랑이");
	map1->setMonster1Count(10);
	map1->setMonster2Count(5);
	map1->setMonster3Count(3);

	this->map2 = new Map();
	map2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx");
	map2->setMonster1("토끼");
	map2->setMonster2("너구리");
	map2->setMonster3("쥐");
	map2->setMonster1Count(11);
	map2->setMonster2Count(15);
	map2->setMonster3Count(17);

	this->map3 = new Map();
	map3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx");
	map3->setMonster1("들개");
	map3->setMonster2("사냥꾼");
	map3->setMonster3("고라니");
	map3->setMonster1Count(2);
	map3->setMonster2Count(20);
	map3->setMonster3Count(6);

	monster1.setName("다람쥐");
	monster1.setType("MONSTER");
	monster1.setFileDir("Resources/monster/다람쥐.jpg");
	monster1.setHp(10);

	monster2.setName("사슴");
	monster2.setType("MONSTER");
	monster2.setFileDir("Resources/monster/사슴.jpg");
	monster2.setHp(12);

	monster3.setName("호랑이");
	monster3.setType("MONSTER");
	monster3.setFileDir("Resources/monster/호랑이.jpg");
	monster3.setHp(20);

	monster4.setName("토끼");
	monster4.setType("MONSTER");
	monster4.setFileDir("Resources/monster/토끼.jpg");
	monster4.setHp(25);

	monster5.setName("너구리");
	monster5.setType("MONSTER");
	monster5.setFileDir("Resources/monster/너구리.jpg");
	monster5.setHp(28);

	monster6.setName("쥐");
	monster6.setType("MONSTER");
	monster6.setFileDir("Resources/monster/쥐.jpg");
	monster6.setHp(15);

	monster7.setName("들개");
	monster7.setType("MONSTER");
	monster7.setFileDir("Resources/monster/들개.jpg");
	monster7.setHp(30);

	monster8.setName("사냥꾼");
	monster8.setType("MONSTER");
	monster8.setFileDir("Resources/monster/사냥꾼.jpg");
	monster8.setHp(50);

	monster9.setName("고라니");
	monster9.setType("MONSTER");
	monster9.setFileDir("Resources/monster/고라니.jpg");
	monster9.setHp(27);

	mapInfo1.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo1.setObjectCode(1);
	mapInfo1.setName("다람쥐");
	mapInfo1.setType("MONSTER");
	mapInfo1.setXpos(4);
	mapInfo1.setYpos(6);
	mapInfo1.setZOrder(1);
	mapInfo1.setFileDir("Resources/monster/다람쥐.jpg");
	mapInfo1.setCount(1);
	mapInfo1.setHp(10);

	mapInfo2.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo2.setObjectCode(2);
	mapInfo2.setName("사슴");
	mapInfo2.setType("MONSTER");
	mapInfo2.setXpos(4);
	mapInfo2.setYpos(6);
	mapInfo2.setZOrder(1);
	mapInfo2.setFileDir("Resources/monster/사슴.jpg");
	mapInfo2.setCount(1);
	mapInfo2.setHp(10);

	mapInfo3.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo3.setObjectCode(3);
	mapInfo3.setName("호랑이");
	mapInfo3.setType("MONSTER");
	mapInfo3.setXpos(4);
	mapInfo3.setYpos(6);
	mapInfo3.setZOrder(1);
	mapInfo3.setFileDir("Resources/monster/호랑이.jpg");
	mapInfo3.setCount(1);
	mapInfo3.setHp(10);
}

GameServerTest::~GameServerTest()
{
	delete this->gameServer;
	delete this->userDao;
	delete this->dataSource;
	delete this->mapDao;
	delete this->mapInfoDao;
	delete this->monsterDao;
	delete this->chattingDao;

	for (int i = 0; i < 10; i++)
	{
		delete this->gameClient[i];
	}

	delete this->map1;
	delete this->map2;
	delete this->map3;
}

void GameServerTest::assertThatLog(int clientNum, int value, int compValue)
{
	if (value != compValue)
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		this->gameClient[clientNum]->addLog(o.str());
	}
}

void GameServerTest::assertThatLog(int clientNum, char* value, char* compValue)
{
	if (strcmp(value, compValue))
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		this->gameClient[clientNum]->addLog(o.str());
	}
}

void GameServerTest::assertThatLog(int clientNum, string value, string compValue)
{
	if (value.compare(compValue) != 0)
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		this->gameClient[clientNum]->addLog(o.str());
	}
}

void GameServerTest::checkSameUserLog(int clientNum, User user1, User user2)
{
	assertThatLog(clientNum, user1.getSock(), user2.getSock());
	assertThatLog(clientNum, user1.getName(), user2.getName());
	assertThatLog(clientNum, user1.getPassword(), user2.getPassword());
	assertThatLog(clientNum, user1.getXpos(), user2.getXpos());
	assertThatLog(clientNum, user1.getYpos(), user2.getYpos());
	assertThatLog(clientNum, user1.getField(), user2.getField());
	assertThatLog(clientNum, user1.getSeeDirection(), user2.getSeeDirection());
	assertThatLog(clientNum, user1.getAction(), user2.getAction());
	assertThatLog(clientNum, user1.getLogin(), user2.getLogin());
	assertThatLog(clientNum, user1.getLastLogin(), user2.getLastLogin());
	assertThatLog(clientNum, user1.getLastLogout(), user2.getLastLogout());
	assertThatLog(clientNum, user1.getJoinDate(), user2.getJoinDate());
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

void GameServerTest::checkSameChat(Chatting chat1, Chatting chat2)
{
	assertThat(chat1.getIdx(), chat2.getIdx());
	assertThat(chat1.getInputdate(), chat2.getInputdate());
	assertThat(chat1.getName(), chat2.getName());
	assertThat(chat1.getContent(), chat2.getContent());
	assertThat(chat1.getField(), chat2.getField());
}

void GameServerTest::run()
{
	userDao->deleteAll();
	chattingDao->deleteAll();

	user[1].setField(user[0].getField());
	user[2].setField(user[0].getField());

	user[4].setField(user[3].getField());
	user[5].setField(user[3].getField());
	user[6].setField(user[3].getField());

	user[8].setField(user[7].getField());
	user[9].setField(user[7].getField());

	for(int i=0; i<10; i++)
	{
		userDao->add(user[i]);
	}

#ifdef _WIN32
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
	flag = 0;

	WaitForSingleObject(hServerThread, INFINITE);
#elif __linux__
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
	flag = 0;

	pthread_join(hServerThread, &thr_ret);
#endif

	for (int i = 0; i < 10; i++)
	{
		printf("GameServerTest: GameClient %d\n", i);
		gameClient[i]->printAllLog();
		printf("\n");
	}

	for (int i = 0; i < 10; i++)
	{
		printf("GameServerTest: GameClient %d user info count : %d\n", i, gameClient[i]->sizeUserInfo());
	}
	printf("\n");

	regenMonster();
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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(0);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc0, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc0, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN->client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(0).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(0).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(0);

	while(logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch(code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(0, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(0, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(1);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc1, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc1, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(1).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(1).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(1);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(1, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(1, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(2);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc2, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc2, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(2).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(2).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(2);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(2, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(2, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(3);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc3, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc3, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(3).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(3).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(3);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(3, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 12)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(3, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 3)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(4);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc4, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc4, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(4).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(4).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(4);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(4, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 12)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(4, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 3)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(5);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc5, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc5, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(5).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(5).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(5);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(5, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 12)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(5, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 3)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(6);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc6, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc6, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(6).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(6).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(6);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(6, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 12)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(6, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 3)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(7);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc7, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc7, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(7).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(7).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(7);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(7, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(7, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(8);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc8, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc8, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(8).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(8).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(8);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(8, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(8, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

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
	HANDLE recvThread;
#elif __linux__
	pthread_t recvThread;
#endif
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(9);
	gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
	recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc9, arg, 0, NULL);
#elif __linux__
	pthread_create(&recvThread, NULL, ClientRecvThreadFunc9, arg);
#endif

	gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
	gameClient->requestLogin("unknown_id");
	gameClient->requestLogin(gameServerTest->getUser(9).getName());

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(9).getName());

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestLogout();

#ifdef _WIN32
	WaitForSingleObject(recvThread, INFINITE);
#elif __linux__
	pthread_join(recvThread, NULL);
#endif

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
	bool logout = false;
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	DataSource * dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	UserDao* userDao = new UserDao(dataSource);
	GameClient* gameClient = gameServerTest->getGameClient(9);

	while (logout != true)
	{
		gameClient->recvRequest(&code, message);
		switch (code)
		{
		case REQUEST_USER_INFO:
			{
				User user;
				memcpy(&user, message, sizeof(User));
				gameClient->setMainUser(user);
				gameClient->setGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(9, user, getUser);
			}
			break;
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);

				if (gameClient->sizeChattingInfo() >= 9)
					gameClient->addLog("GameServerTest: Chatting");
			}
			break;
		case REQUEST_LOGIN:
			if (!strcmp(message, "login okey"))
				gameClient->setIsLogin(true);
			else
			{
				gameClient->setIsLogin(false);
				gameClient->setPopupLoginFail(true);
			}
			gameServerTest->assertThatLog(9, message, "login okey");
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);
					if (gameClient->sizeUserInfo() >= 2)
						gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE -> client");
				}
				else if (user->getAction() == ACTION_MAP_OUT)
					gameClient->removeUsersInfo(user->getName());
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete dataSource;

#ifdef _WIN32
	return 0;
#endif
}

void GameServerTest::regenMonster()
{
	std::cout << "GameServerTest : regenMonster()" << std::endl;

	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);
	mapDao->add(*map3);

	monsterDao->deleteAll();
	monsterDao->add(monster1);
	monsterDao->add(monster2);
	monsterDao->add(monster3);
	monsterDao->add(monster4);
	monsterDao->add(monster5);
	monsterDao->add(monster6);
	monsterDao->add(monster7);
	monsterDao->add(monster8);
	monsterDao->add(monster9);

	mapInfoDao->deleteAll();
	gameServer->regenMonster();

	list<Map> mapList = this->mapDao->getAll();
	list<Map>::iterator iter;

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
	}

	mapInfoDao->deleteAll();
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo3);
	mapInfoDao->add(mapInfo3);
	mapInfoDao->add(mapInfo3);

	gameServer->regenMonster();

	mapList = this->mapDao->getAll();

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
	}
}