#include "GameServerTest.h"

int flag = 1;

GameServerTest::GameServerTest()
{
	this->mainAssert = new Assert();

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		this->gameClient[i] = new GameClient();

		this->context[i] = new TestApplicationContext();
		this->assert[i] = new Assert();
		this->assert[i]->setApplicationContext(context[i]);
	}

	for (int i = 0; i<10; i++)
	{
		char imsi[1024];
		this->user[i].setSock(0);
		sprintf(imsi, "abcd%d", i);
		this->user[i].setName(imsi);
		sprintf(imsi, "abc%d", i);
		this->user[i].setPassword(imsi);
		this->user[i].setXpos(10 + i);
		this->user[i].setYpos(12 + i);
		sprintf(imsi, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor%d.tmx", i);
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
	map1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	map1->setMonster1("다람쥐");
	map1->setMonster2("사슴");
	map1->setMonster3("호랑이");
	map1->setMonster1Count(10);
	map1->setMonster2Count(5);
	map1->setMonster3Count(3);

	this->map2 = new Map();
	map2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	map2->setMonster1("토끼");
	map2->setMonster2("너구리");
	map2->setMonster3("쥐");
	map2->setMonster1Count(11);
	map2->setMonster2Count(15);
	map2->setMonster3Count(17);

	this->map3 = new Map();
	map3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
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

	mapInfo1.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	mapInfo1.setObjectCode(1);
	mapInfo1.setName("다람쥐");
	mapInfo1.setType("MONSTER");
	mapInfo1.setXpos(4);
	mapInfo1.setYpos(6);
	mapInfo1.setZOrder(1);
	mapInfo1.setFileDir("Resources/monster/다람쥐.jpg");
	mapInfo1.setCount(1);
	mapInfo1.setHp(10);

	mapInfo2.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	mapInfo2.setObjectCode(2);
	mapInfo2.setName("사슴");
	mapInfo2.setType("MONSTER");
	mapInfo2.setXpos(4);
	mapInfo2.setYpos(6);
	mapInfo2.setZOrder(1);
	mapInfo2.setFileDir("Resources/monster/사슴.jpg");
	mapInfo2.setCount(1);
	mapInfo2.setHp(10);

	mapInfo3.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	mapInfo3.setObjectCode(3);
	mapInfo3.setName("호랑이");
	mapInfo3.setType("MONSTER");
	mapInfo3.setXpos(4);
	mapInfo3.setYpos(6);
	mapInfo3.setZOrder(1);
	mapInfo3.setFileDir("Resources/monster/호랑이.jpg");
	mapInfo3.setCount(1);
	mapInfo3.setHp(10);

	for (int i = 0; i < 8; i++)
	{
		objectInfo[i].setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
		objectInfo[i].setObjectCode(14);
		objectInfo[i].setName("가로등");
		objectInfo[i].setType("OBJECT");
		objectInfo[i].setXpos(51 + i);
		objectInfo[i].setYpos(81 + i);
		objectInfo[i].setZOrder(3 + i);
		objectInfo[i].setFileDir("Images/가로등.jpg");
		objectInfo[i].setCount(3 + i);
		objectInfo[i].setHp(150);
	}

	for (int i = 8; i < 15; i++)
	{
		objectInfo[i].setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
		objectInfo[i].setObjectCode(15);
		objectInfo[i].setName("신호등");
		objectInfo[i].setType("OBJECT");
		objectInfo[i].setXpos(51 + i);
		objectInfo[i].setYpos(81 + i);
		objectInfo[i].setZOrder(3 + i);
		objectInfo[i].setFileDir("Images/신호등.jpg");
		objectInfo[i].setCount(3 + i);
		objectInfo[i].setHp(150);
	}

	for (int i = 15; i < 20; i++)
	{
		objectInfo[i].setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
		objectInfo[i].setObjectCode(16);
		objectInfo[i].setName("자동차");
		objectInfo[i].setType("OBJECT");
		objectInfo[i].setXpos(51 + i);
		objectInfo[i].setYpos(81 + i);
		objectInfo[i].setZOrder(3 + i);
		objectInfo[i].setFileDir("Images/자동차.jpg");
		objectInfo[i].setCount(3 + i);
		objectInfo[i].setHp(150);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char message[100];
			sprintf(message, "토마토_%d", j);
			item[i][j].setItemName(message);
			sprintf(message, "abcd%d", i);
			item[i][j].setUserName(message);
			item[i][j].setType("ITEM");

			if (j < 5)
			{
				item[i][j].setXpos(0);
				item[i][j].setYpos(j);
			}
			else
			{
				item[i][j].setXpos(1);
				item[i][j].setYpos(j - 5);
			}

			sprintf(message, "Resources/items/토마토_%d.jpg", j);
			item[i][j].setFileDir(message);
			item[i][j].setCount(1 + j);
		}
	}
}

GameServerTest::~GameServerTest()
{
	delete mainAssert;

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		delete this->gameClient[i];
		delete this->assert[i];
		delete this->context[i];
	}

	delete this->map1;
	delete this->map2;
	delete this->map3;
}

void GameServerTest::setApplicationContext(ApplicationContext* context)
{
	this->mainAssert->setApplicationContext(context);

	this->userDao = context->userDao();
	this->gameServer = context->gameServer();
	this->mapDao = context->mapDao();
	this->mapInfoDao = context->mapInfoDao();
	this->monsterDao = context->monsterDao();
	this->chattingDao = context->chattingDao();
	this->inventoryInfoDao = context->inventoryInfoDao();
	this->mapManageService = context->mapManageService();
}

void GameServerTest::run()
{
	userDao->deleteAll();
	chattingDao->deleteAll();

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
	mapManageService->regenMonster();

	for (int i = 0; i < 20; i++)
	{
		mapInfoDao->add(objectInfo[i]);
	}

	inventoryInfoDao->deleteAll();

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			inventoryInfoDao->add(item[i][j]);
		}
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

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d\n", i);
		gameClient[i]->printAllLog();
		printf("\n");
	}

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d user info count : %d\n", i, gameClient[i]->sizeUserInfo());
	}
	printf("\n");

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d monster info count : %d\n", i, gameClient[i]->sizeMonsterInfo());
	}
	printf("\n");

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d object info count : %d\n", i, gameClient[i]->sizeObjectInfo());
	}
	printf("\n");

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d item info count : %d\n", i, gameClient[i]->sizeItemInfo());
	}
	printf("\n");

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		printf("GameServerTest: GameClient %d inventory info count : %d\n", i, gameClient[i]->sizeInventoryInfo());
	}
	printf("\n");
}

GameServer* GameServerTest::getGameServer()
{
	return this->gameServer;
}

GameClient* GameServerTest::getGameClient(int idx)
{
	return this->gameClient[idx];
}

vector<GameClient*> GameServerTest::getGameClientList()
{
	vector<GameClient*> gameClientList;

	for (int i = 0; i < GAME_CLIENT_COUNT; i++)
	{
		gameClientList.push_back(gameClient[i]);
	}

	return gameClientList;
}

Assert* GameServerTest::getAssert(int idx)
{
	return this->assert[idx];
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
	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(0);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc0, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc0, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(0));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN->client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(0)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(0).getName());
		gameServerTest->getAssert(0)->assertThatLog(gameClient, 1, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(0).getName());
		gameServerTest->getAssert(0)->assertThatLog(gameClient, 0, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(0).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(0)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(0)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(0)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(10, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(10, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(11, 12, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 29);
		gameServerTest->getAssert(0)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 28);
		gameServerTest->getAssert(0)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(0)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 26);
		gameServerTest->getAssert(0)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(20, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);
		gameClient->requestGetItem();

		gameClient->requestMapMove(20, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 3);
		gameClient->requestGetItem();

		gameClient->requestMapMove(20, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(1, 0);
		gameClient->requestGetItem();

		gameClient->requestMapMove(20, 10, gameClient->getMainUser().getField(), 26);
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);
		gameClient->requestThrowItem(0, 1);
		gameClient->requestThrowItem(0, 2);
		gameClient->requestThrowItem(0, 3);
		gameClient->requestThrowItem(0, 4);
		gameClient->requestThrowItem(1, 0);
		gameClient->requestThrowItem(1, 1);
		gameClient->requestThrowItem(1, 2);

		for (int i = 0; i < 8; i++)
		{
			gameClient->requestGetItem();
		}

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(4);
		user.setXpos(4);
		user.setYpos(4);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(5);
		user.setXpos(5);
		user.setYpos(5);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(6);
		user.setXpos(6);
		user.setYpos(6);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(0)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 0 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(0);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(1);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc1, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc1, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(1));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(1)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(1).getName());
		gameServerTest->getAssert(1)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(1).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(1)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(1)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(1)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(20, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(20, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(21, 12, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 29);
		gameServerTest->getAssert(1)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 28);
		gameServerTest->getAssert(1)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(1)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 26);
		gameServerTest->getAssert(1)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(3, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(13, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(3, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(7);
		user.setXpos(7);
		user.setYpos(7);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(8);
		user.setXpos(8);
		user.setYpos(8);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(9);
		user.setXpos(9);
		user.setYpos(9);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(1)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 1 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(1);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(2);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc2, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc2, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(2));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(2)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(2).getName());
		gameServerTest->getAssert(2)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(2).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(2)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(2)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(2)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(12, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(12, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(13, 12, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 29);
		gameServerTest->getAssert(2)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 28);
		gameServerTest->getAssert(2)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(2)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 26);
		gameServerTest->getAssert(2)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(5, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(5, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(5, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(0);
		user.setXpos(0);
		user.setYpos(0);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(123);
		user.setXpos(123);
		user.setYpos(123);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(456);
		user.setXpos(456);
		user.setYpos(456);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(2)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 2 : " << error.what() << std::endl;
	}
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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(2);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(3);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc3, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc3, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(3));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(3)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(3).getName());
		gameServerTest->getAssert(3)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(3).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(3)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(3)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(3)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(1, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(1, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(2, 12, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(3)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 28);
		gameServerTest->getAssert(3)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(3)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 26);
		gameServerTest->getAssert(3)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(10, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(10, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(111);
		user.setXpos(111);
		user.setYpos(111);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(222);
		user.setXpos(222);
		user.setYpos(222);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(333);
		user.setXpos(333);
		user.setYpos(333);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(3)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());
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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 3 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(3);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(4);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc4, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc4, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(4));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(4)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(4).getName());
		gameServerTest->getAssert(4)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(4).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(4)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(4)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(4)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(11, 1, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(4)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 28);
		gameServerTest->getAssert(4)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(4)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 26);
		gameServerTest->getAssert(4)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(11, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(11, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(11, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(444);
		user.setXpos(444);
		user.setYpos(444);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(555);
		user.setXpos(555);
		user.setYpos(555);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(666);
		user.setXpos(666);
		user.setYpos(666);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(4)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 4 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(4);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(5);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc5, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc5, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(5));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(5)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(5).getName());
		gameServerTest->getAssert(5)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(5).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(5)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(5)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(5)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(10, 5, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(10, 6, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(11, 6, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(5)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 28);
		gameServerTest->getAssert(5)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(5)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 26);
		gameServerTest->getAssert(5)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(18, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(18, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(18, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(777);
		user.setXpos(777);
		user.setYpos(777);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(888);
		user.setXpos(888);
		user.setYpos(888);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(999);
		user.setXpos(999);
		user.setYpos(999);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(5)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 5 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(5);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(6);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc6, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc6, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(6));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(6)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(6).getName());
		gameServerTest->getAssert(6)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(6).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(6)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(6)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(6)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(10, 2, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(10, 3, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(11, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(6)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 28);
		gameServerTest->getAssert(6)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 27);
		gameServerTest->getAssert(6)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 26);
		gameServerTest->getAssert(6)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(201, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(201, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(201, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(11);
		user.setXpos(11);
		user.setYpos(11);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(22);
		user.setXpos(22);
		user.setYpos(22);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(33);
		user.setXpos(33);
		user.setYpos(33);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(6)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 6 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(6);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(7);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc7, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc7, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(7));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(7)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(7).getName());
		gameServerTest->getAssert(7)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(7).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(7)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(7)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(7)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(5, 5, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(5, 6, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(6, 6, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(7)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 28);
		gameServerTest->getAssert(7)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 27);
		gameServerTest->getAssert(7)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 26);
		gameServerTest->getAssert(7)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(40, 1, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 3);

		gameClient->requestGetItem();

		gameClient->requestMapMove(40, 2, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 4);

		gameClient->requestGetItem();

		gameClient->requestMapMove(40, 3, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(44);
		user.setXpos(44);
		user.setYpos(44);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(55);
		user.setXpos(55);
		user.setYpos(55);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(66);
		user.setXpos(66);
		user.setYpos(66);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(7)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 7 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(7);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(8);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc8, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc8, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(8));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(8)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(8).getName());
		gameServerTest->getAssert(8)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(8).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(8)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(8)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(8)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(2, 8, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(2, 9, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(3, 9, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(8)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 28);
		gameServerTest->getAssert(8)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 27);
		gameServerTest->getAssert(8)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 26);
		gameServerTest->getAssert(8)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(50, 5, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 2);

		gameClient->requestGetItem();

		gameClient->requestMapMove(50, 6, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 1);

		gameClient->requestGetItem();

		gameClient->requestMapMove(50, 7, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 4);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(77);
		user.setXpos(77);
		user.setYpos(77);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(88);
		user.setXpos(88);
		user.setYpos(88);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(99);
		user.setXpos(99);
		user.setYpos(99);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(8)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 8 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(8);

	gameClient->recvRun();

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

	try
	{
		GameServerTest* gameServerTest = (GameServerTest*)arg;
		GameClient* gameClient = gameServerTest->getGameClient(9);
		gameClient->openClient("127.0.0.1", 9190);

#ifdef _WIN32
		recvThread = (HANDLE)_beginthreadex(NULL, 0, ClientRecvThreadFunc9, arg, 0, NULL);
#elif __linux__
		pthread_create(&recvThread, NULL, ClientRecvThreadFunc9, arg);
#endif
		gameClient->requestJoinUser(gameServerTest->getUser(9));

		gameClient->addLog("GameServerTest: REQUEST_LOGIN -> client");
		gameClient->requestLogin("unknown_id");
		gameServerTest->getAssert(9)->assertThatLog(gameClient, 0, gameClient->getIsLogin());
		gameClient->requestLogin(gameServerTest->getUser(9).getName());
		gameServerTest->getAssert(9)->assertThatLog(gameClient, 1, gameClient->getIsLogin());

		gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
		gameClient->getUserInfo("unknown_id");
		gameClient->getUserInfo(gameServerTest->getUser(9).getName());

		while (gameClient->getIsGetUserInfo() != true);
		gameClient->setIsGetUserInfo(false);

		gameClient->addLog("GameServerTest: CHATTING_PROCESS->client");
		gameClient->chatting("Hello World1");
		gameServerTest->getAssert(9)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World2");
		gameServerTest->getAssert(9)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->chatting("Hello World3");
		gameServerTest->getAssert(9)->checkSameDatabaseChattingListLog(gameClient, gameServerTest->getGameClientList(), gameClient->getChattingInfo(gameClient->sizeChattingInfo() - 1));

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_MOVE->client");
		gameClient->requestMapMove(101, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(101, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(102, 12, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->addLog("GameServerTest: USER_MOVE_UPDATE, ACTION_MAP_POTAL->client");
		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx", 29);
		gameServerTest->getAssert(9)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 28);
		gameServerTest->getAssert(9)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx", 27);
		gameServerTest->getAssert(9)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx", 26);
		gameServerTest->getAssert(9)->checkSameDatabaseMapUserInfoLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestMapMove(20, 11, gameClient->getMainUser().getField(), 29);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 0);

		gameClient->requestGetItem();

		gameClient->requestMapMove(20, 12, gameClient->getMainUser().getField(), 28);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(0, 4);

		gameClient->requestGetItem();

		gameClient->requestMapMove(20, 13, gameClient->getMainUser().getField(), 27);
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		gameClient->requestThrowItem(1, 0);

		gameClient->requestGetItem();

		gameClient->addLog("GameServerTest: UPDATE_USER_INFO");

		User user = gameClient->getMainUser();
		user.setAction(1);
		user.setXpos(1);
		user.setYpos(1);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(2);
		user.setXpos(2);
		user.setYpos(2);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

		user.setAction(3);
		user.setXpos(3);
		user.setYpos(3);

		gameClient->setMainUser(user);
		gameClient->requestUpdateUserInfo();
		gameServerTest->getAssert(9)->checkSameDatabaseUserListLog(gameClient, gameServerTest->getGameClientList());

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

	}
	catch (const runtime_error& error)
	{
		std::cout << "\tClient 9 : " << error.what() << std::endl;
	}

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
	GameServerTest* gameServerTest = (GameServerTest*)arg;
	GameClient* gameClient = gameServerTest->getGameClient(9);

	gameClient->recvRun();

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
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
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
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		this->mainAssert->assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
	}
}