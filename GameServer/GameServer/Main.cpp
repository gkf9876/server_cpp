#include <iostream>
#include "GameServerTest.h"

#include "factory/ApplicationContext.h"
#include "factory/TestApplicationContext.h"

#include "dao/UserDaoTest.h"
#include "dao/ChattingDaoTest.h"
#include "dao/InventoryInfoDaoTest.h"
#include "dao/MapDaoTest.h"
#include "dao/MapInfoDaoTest.h"
#include "dao/MonsterDaoTest.h"
#include "dao/LoadingScreenDaoTest.h"

#include "service/MapManageServiceTest.h"
#include "service/UserServiceTest.h"
#include "service/ChattingServiceTest.h"
#include "service/LoadingScreenServiceTest.h"

int main()
{
	TestApplicationContext* testContext = new TestApplicationContext();

	UserDaoTest * userDaoTest = new UserDaoTest();
	userDaoTest->setApplicationContext(testContext);
	userDaoTest->run();
	delete userDaoTest;

	ChattingDaoTest * chattingDaoTest = new ChattingDaoTest();
	chattingDaoTest->setApplicationContext(testContext);
	chattingDaoTest->run();
	delete chattingDaoTest;
	
	InventoryInfoDaoTest * inventoryInfoDaoTest = new InventoryInfoDaoTest();
	inventoryInfoDaoTest->setApplicationContext(testContext);
	inventoryInfoDaoTest->run();
	delete inventoryInfoDaoTest;
	
	MapDaoTest * mapDaoTest = new MapDaoTest();
	mapDaoTest->setApplicationContext(testContext);
	mapDaoTest->run();
	delete mapDaoTest;
	
	MapInfoDaoTest * mapInfoDaoTest = new MapInfoDaoTest();
	mapInfoDaoTest->setApplicationContext(testContext);
	mapInfoDaoTest->run();
	delete mapInfoDaoTest;
	
	MonsterDaoTest * monsterDaoTest = new MonsterDaoTest();
	monsterDaoTest->setApplicationContext(testContext);
	monsterDaoTest->run();
	delete monsterDaoTest;

	LoadingScreenDaoTest * loadingScreenDaoTest = new LoadingScreenDaoTest();
	loadingScreenDaoTest->setApplicationContext(testContext);
	loadingScreenDaoTest->run();
	delete loadingScreenDaoTest;

	MapManageServiceTest* mapManageServiceTest = new MapManageServiceTest();
	mapManageServiceTest->setApplicationContext(testContext);
	mapManageServiceTest->run();
	delete mapManageServiceTest;
	
	UserServiceTest* userServiceTest = new UserServiceTest();
	userServiceTest->setApplicationContext(testContext);
	userServiceTest->run();
	delete userServiceTest;
	
	ChattingServiceTest* chattingServiceTest = new ChattingServiceTest();
	chattingServiceTest->setApplicationContext(testContext);
	chattingServiceTest->run();
	delete chattingServiceTest;

	LoadingScreenServiceTest* loadingScreenServiceTest = new LoadingScreenServiceTest();
	loadingScreenServiceTest->setApplicationContext(testContext);
	loadingScreenServiceTest->run();
	delete loadingScreenServiceTest;

#ifdef _WIN32
#elif __linux__
	GameServerTest * gameServerTest = new GameServerTest();
	gameServerTest->setApplicationContext(testContext);
	gameServerTest->run();
	delete gameServerTest;
#elif __APPLE__
	GameServerTest * gameServerTest = new GameServerTest();
	gameServerTest->setApplicationContext(testContext);
	gameServerTest->run();
	delete gameServerTest;
#endif

	delete testContext;

	ApplicationContext* context = new ApplicationContext();
	GameServer * gameServer = context->gameServer();

	try
	{
		gameServer->openServer(9190);

		std::cout << "--------------- Server start!! ---------------" << std::endl;

		while (1)
		{
#ifdef _WIN32
			gameServer->accept_win();
#elif __linux__
			gameServer->accept_linux();
#endif
		}

		gameServer->closeServer();
		delete gameServer;
		delete context;
	}
	catch (const runtime_error& error)
	{
		std::cout << error.what() << std::endl;
	}

	return 0;
}
