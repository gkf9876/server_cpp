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

#include "service/MapManageServiceTest.h"
#include "service/UserServiceTest.h"
#include "service/ChattingServiceTest.h"

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
	
	GameServerTest * gameServerTest = new GameServerTest();
	gameServerTest->setApplicationContext(testContext);
	gameServerTest->run();
	delete gameServerTest;

	delete testContext;

//	ApplicationContext* context = new ApplicationContext();
//	GameServer * gameServer = context->gameServer();
//
//	try
//	{
//		gameServer->openServer(9190);
//
//		while (1)
//		{
//#ifdef _WIN32
//			gameServer->accept_win();
//#elif __linux__
//			gameServer->accept_linux();
//#endif
//		}
//
//		gameServer->closeServer();
//		delete gameServer;
//		delete context;
//	}
//	catch (const runtime_error& error)
//	{
//		std::cout << error.what() << std::endl;
//	}

	return 0;
}
