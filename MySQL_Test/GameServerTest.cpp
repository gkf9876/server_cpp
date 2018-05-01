﻿#include "GameServerTest.h"

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
	this->inventoryInfoDao = new InventoryInfoDao(this->dataSource);
	this->mapManageService = new MapManageService(this->dataSource);
	
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
	delete this->gameServer;
	delete this->userDao;
	delete this->dataSource;
	delete this->mapDao;
	delete this->mapInfoDao;
	delete this->monsterDao;
	delete this->chattingDao;
	delete this->inventoryInfoDao;
	delete this->mapManageService;

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

void GameServerTest::assertThatLog(int clientNum, char* value, const char* compValue)
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

void GameServerTest::checkSameChatLog(int clientNum, Chatting chat1, Chatting chat2)
{
	assertThatLog(clientNum, chat1.getName(), chat2.getName());
	assertThatLog(clientNum, chat1.getContent(), chat2.getContent());
	assertThatLog(clientNum, chat1.getField(), chat2.getField());
}

void GameServerTest::checkSameMapInfoLog(int clientNum, MapInfo mapInfo1, MapInfo mapInfo2)
{
	assertThatLog(clientNum, mapInfo1.getField(), mapInfo2.getField());
	assertThatLog(clientNum, mapInfo1.getObjectCode(), mapInfo2.getObjectCode());
	assertThatLog(clientNum, mapInfo1.getName(), mapInfo2.getName());
	assertThatLog(clientNum, mapInfo1.getType(), mapInfo2.getType());
	assertThatLog(clientNum, mapInfo1.getXpos(), mapInfo2.getXpos());
	assertThatLog(clientNum, mapInfo1.getYpos(), mapInfo2.getYpos());
	assertThatLog(clientNum, mapInfo1.getZOrder(), mapInfo2.getZOrder());
	assertThatLog(clientNum, mapInfo1.getFileDir(), mapInfo2.getFileDir());
	assertThatLog(clientNum, mapInfo1.getCount(), mapInfo2.getCount());
	assertThatLog(clientNum, mapInfo1.getHp(), mapInfo2.getHp());
}

void GameServerTest::checkSameInventoryInfo(int clientNum, InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2)
{
	assertThatLog(clientNum, inventoryInfo1.getItemName(), inventoryInfo2.getItemName());
	assertThatLog(clientNum, inventoryInfo1.getUserName(), inventoryInfo2.getUserName());
	assertThatLog(clientNum, inventoryInfo1.getType(), inventoryInfo2.getType());
	assertThatLog(clientNum, inventoryInfo1.getXpos(), inventoryInfo2.getXpos());
	assertThatLog(clientNum, inventoryInfo1.getYpos(), inventoryInfo2.getYpos());
	assertThatLog(clientNum, inventoryInfo1.getFileDir(), inventoryInfo2.getFileDir());
	assertThatLog(clientNum, inventoryInfo1.getCount(), inventoryInfo2.getCount());
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

	for (int i = 0; i < 10; i++)
	{
		printf("GameServerTest: GameClient %d monster info count : %d\n", i, gameClient[i]->sizeMonsterInfo());
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("GameServerTest: GameClient %d object info count : %d\n", i, gameClient[i]->sizeObjectInfo());
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("GameServerTest: GameClient %d item info count : %d\n", i, gameClient[i]->sizeItemInfo());
	}
	printf("\n");

	for (int i = 0; i < 10; i++)
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(0).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(10, 11, gameClient->getMainUser().getField());
	gameClient->requestMapMove(10, 12, gameClient->getMainUser().getField());
	gameClient->requestMapMove(11, 12, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(20, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(20, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 3);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(20, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(1, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(20, 10, gameClient->getMainUser().getField());

	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(0, 3);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(0, 4);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(1, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(1, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestThrowItem(1, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	for (int i = 0; i < 8; i++)
	{
		gameClient->requestGetItem();
		while (gameClient->getIsGetItemFinish() != true);
		gameClient->setIsGetItemFinish(false);
	}

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(0, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(0, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(0, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(1).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(20, 11, gameClient->getMainUser().getField());
	gameClient->requestMapMove(20, 12, gameClient->getMainUser().getField());
	gameClient->requestMapMove(21, 12, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(3, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(13, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(3, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(1, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(1, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(1, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(2).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(12, 11, gameClient->getMainUser().getField());
	gameClient->requestMapMove(12, 12, gameClient->getMainUser().getField());
	gameClient->requestMapMove(13, 12, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);


	gameClient->requestMapMove(5, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(5, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(5, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(2, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(2, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(2, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(3).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(1, 11, gameClient->getMainUser().getField());
	gameClient->requestMapMove(1, 12, gameClient->getMainUser().getField());
	gameClient->requestMapMove(2, 12, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(10, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(10, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(3, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(3, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(3, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(4).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField());
	gameClient->requestMapMove(10, 1, gameClient->getMainUser().getField());
	gameClient->requestMapMove(11, 1, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(11, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(11, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(11, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(4, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(4, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(4, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(5).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(10, 5, gameClient->getMainUser().getField());
	gameClient->requestMapMove(10, 6, gameClient->getMainUser().getField());
	gameClient->requestMapMove(11, 6, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(18, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(18, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(18, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(5, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(5, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(5, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(6).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(10, 2, gameClient->getMainUser().getField());
	gameClient->requestMapMove(10, 3, gameClient->getMainUser().getField());
	gameClient->requestMapMove(11, 3, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(201, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(201, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(201, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(6, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(6, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(6, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(7).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(5, 5, gameClient->getMainUser().getField());
	gameClient->requestMapMove(5, 6, gameClient->getMainUser().getField());
	gameClient->requestMapMove(6, 6, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(40, 1, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 3);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(40, 2, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 4);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(40, 3, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(7, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(7, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(7, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(8).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(2, 8, gameClient->getMainUser().getField());
	gameClient->requestMapMove(2, 9, gameClient->getMainUser().getField());
	gameClient->requestMapMove(3, 9, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(50, 5, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 2);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(50, 6, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 1);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(50, 7, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 4);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(8, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(8, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(8, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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

	while (gameClient->getIsLogin() != true);

	gameClient->addLog("GameServerTest: REQUEST_USER_INFO->client");
	gameClient->getUserInfo("unknown_id");
	gameClient->getUserInfo(gameServerTest->getUser(9).getName());

	while (gameClient->getIsGetUserInfo() != true);

	gameClient->chatting("Hello World1");
	gameClient->chatting("Hello World2");
	gameClient->chatting("Hello World3");

#ifdef _WIN32
	Sleep(2000);
#elif __linux__
	sleep(2);
#endif

	gameClient->requestMapMove(101, 11, gameClient->getMainUser().getField());
	gameClient->requestMapMove(101, 12, gameClient->getMainUser().getField());
	gameClient->requestMapMove(102, 12, gameClient->getMainUser().getField());

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(111, 122, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(51, 22, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx");
	while (gameClient->getIsMapPotalFinish() != true);
	gameClient->setIsMapPotalFinish(false);

	gameClient->requestMapMove(20, 11, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(20, 12, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(0, 4);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

	gameClient->requestMapMove(20, 13, gameClient->getMainUser().getField());
	gameClient->requestThrowItem(1, 0);
	while (gameClient->getIsThrowItemFinish() != true);
	gameClient->setIsThrowItemFinish(false);

	gameClient->requestGetItem();
	while (gameClient->getIsGetItemFinish() != true);
	gameClient->setIsGetItemFinish(false);

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
	ChattingDao* chattingDao = new ChattingDao(dataSource);
	MapInfoDao* mapInfoDao = new MapInfoDao(dataSource);
	UserService* userService = new UserService(dataSource);
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
				gameClient->setIsGetUserInfo(true);

				User getUser = userDao->get(user.getName());
				gameServerTest->checkSameUserLog(9, user, getUser);
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
		case CHATTING_PROCESS:
			{
				Chatting* chatting = new Chatting();
				memcpy(chatting, message, sizeof(Chatting));
				gameClient->addChattingInfo(chatting);
			}
			break;
		case OTHER_USER_MAP_MOVE:
			{
				User* user = new User();
				memcpy(user, message, sizeof(User));

				if (user->getAction() == ACTION_MAP_IN)
				{
					gameClient->addUsersInfo(user);

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_IN -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
				}
				else if (user->getAction() == ACTION_MAP_OUT)
				{
					gameClient->removeUsersInfo(user->getName());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_OUT -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);
					delete user;
				}
				else if (user->getAction() == ACTION_MAP_MOVE)
				{
					gameClient->moveOtherUser(user->getName(), user->getXpos(), user->getYpos());

					gameClient->addLog("GameServerTest : OTHER_USER_MAP_MOVE, ACTION_MAP_MOVE -> client");
					User otherUser = gameClient->getUsersInfo(user->getName());

					char message[1024];
					sprintf(message, "\tname(%s), pos(%d, %d)", user->getName(), user->getXpos(), user->getYpos());
					gameClient->addLog(message);

					delete user;
				}
			}
			break;
		case DELETE_FIELD_ITEM:
			{
				MapInfo itemInfo;
				memcpy(&itemInfo, message, sizeof(MapInfo));

				gameClient->removeItemInfo(itemInfo.getIdx());
			}
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			{
				MapInfo* objectInfo = new MapInfo();
				memcpy(objectInfo, message, sizeof(MapInfo));

				gameClient->addObjectInfo(objectInfo);
			}
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			{
				MapInfo* monsterInfo = new MapInfo();
				memcpy(monsterInfo, message, sizeof(MapInfo));

				gameClient->addMonsterInfo(monsterInfo);
			}
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_FIELD_ITEM_INFO:
			{
				MapInfo* itemInfo = new MapInfo();
				memcpy(itemInfo, message, sizeof(MapInfo));

				gameClient->addItemInfo(itemInfo);
			}
			break;
		case REQUEST_EAT_ITEM:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->addInventoryInfo(inventoryInfo);
			}
			break;
		case REQUEST_LOGOUT:
			if (!strcmp(message, "logout okey"))
			{
				gameClient->closeClient();
				logout = true;
			}
			break;
		case REQUEST_MAP_MOVE:
			if (!strcmp(message, "map_potal_success"))
			{
				gameClient->clearUsersInfo();
				gameClient->clearObjectInfo();
				gameClient->clearMonsterInfo();
				gameClient->clearItemInfo();
				gameServerTest->assertThatLog(9, message, "map_potal_success");
			}
			else if (!strcmp(message, "map_move_success"))
				gameServerTest->assertThatLog(9, message, "map_move_success");
			break;
		case REQUEST_MAP_POTAL_FINISH:
			if (!strcmp(message, "map_potal_finish"))
				gameClient->setIsMapPotalFinish(true);
			break;
		case REQUEST_THROW_ITEM_FINISH:
			{
				InventoryInfo* inventoryInfo = new InventoryInfo();
				memcpy(inventoryInfo, message, sizeof(InventoryInfo));

				gameClient->setIsThrowItemFinish(true);
				gameClient->removeInventoryInfo(inventoryInfo->getXpos(), inventoryInfo->getYpos());
			}
			break;
		case REQUEST_GET_ITEM_FINISH:
			if (!strcmp(message, "get_item_finish"))
				gameClient->setIsGetItemFinish(true);
			break;
		default:
			break;
		}
	}

	delete userDao;
	delete chattingDao;
	delete mapInfoDao;
	delete userService;
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