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
#include "dao/EventInfoDaoTest.h"

#include "service/MapManageServiceTest.h"
#include "service/UserServiceTest.h"
#include "service/ChattingServiceTest.h"
#include "service/LoadingScreenServiceTest.h"
#include "service/ServerInfoServiceTest.h"
#include "service/EventInfoServiceTest.h"

int main()
{
	TestApplicationContext* testContext = new TestApplicationContext();

	//UserDaoTest * userDaoTest = new UserDaoTest();
	//userDaoTest->setApplicationContext(testContext);
	//userDaoTest->run();
	//delete userDaoTest;

	//ChattingDaoTest * chattingDaoTest = new ChattingDaoTest();
	//chattingDaoTest->setApplicationContext(testContext);
	//chattingDaoTest->run();
	//delete chattingDaoTest;
	//
	//InventoryInfoDaoTest * inventoryInfoDaoTest = new InventoryInfoDaoTest();
	//inventoryInfoDaoTest->setApplicationContext(testContext);
	//inventoryInfoDaoTest->run();
	//delete inventoryInfoDaoTest;
	//
	//MapDaoTest * mapDaoTest = new MapDaoTest();
	//mapDaoTest->setApplicationContext(testContext);
	//mapDaoTest->run();
	//delete mapDaoTest;
	//
	//MapInfoDaoTest * mapInfoDaoTest = new MapInfoDaoTest();
	//mapInfoDaoTest->setApplicationContext(testContext);
	//mapInfoDaoTest->run();
	//delete mapInfoDaoTest;
	//
	//MonsterDaoTest * monsterDaoTest = new MonsterDaoTest();
	//monsterDaoTest->setApplicationContext(testContext);
	//monsterDaoTest->run();
	//delete monsterDaoTest;

	//LoadingScreenDaoTest * loadingScreenDaoTest = new LoadingScreenDaoTest();
	//loadingScreenDaoTest->setApplicationContext(testContext);
	//loadingScreenDaoTest->run();
	//delete loadingScreenDaoTest;

	//EventInfoDaoTest * eventInfoDaoTest = new EventInfoDaoTest();
	//eventInfoDaoTest->setApplicationContext(testContext);
	//eventInfoDaoTest->run();
	//delete eventInfoDaoTest;

	//MapManageServiceTest* mapManageServiceTest = new MapManageServiceTest();
	//mapManageServiceTest->setApplicationContext(testContext);
	//mapManageServiceTest->run();
	//delete mapManageServiceTest;
	//
	//UserServiceTest* userServiceTest = new UserServiceTest();
	//userServiceTest->setApplicationContext(testContext);
	//userServiceTest->run();
	//delete userServiceTest;
	//
	//ChattingServiceTest* chattingServiceTest = new ChattingServiceTest();
	//chattingServiceTest->setApplicationContext(testContext);
	//chattingServiceTest->run();
	//delete chattingServiceTest;

	//LoadingScreenServiceTest* loadingScreenServiceTest = new LoadingScreenServiceTest();
	//loadingScreenServiceTest->setApplicationContext(testContext);
	//loadingScreenServiceTest->run();
	//delete loadingScreenServiceTest;

	//ServerInfoServiceTest* serverInfoServiceTest = new ServerInfoServiceTest();
	//serverInfoServiceTest->setApplicationContext(testContext);
	//serverInfoServiceTest->run();
	//delete serverInfoServiceTest;

	//EventInfoServiceTest* eventInfoServiceTest = new EventInfoServiceTest();
	//eventInfoServiceTest->setApplicationContext(testContext);
	//eventInfoServiceTest->run();
	//delete eventInfoServiceTest;

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
		int timeCount = 0;
		int count = 0;
		int flag;
		gameServer->openServer(9190);

		std::cout << "--------------- Server start!! ---------------" << std::endl;

		while (1)
		{
			if ((flag = gameServer->accept_win()) == SOCKET_ERROR)
				break;

			//1초마다 유저들 접속 확인
			gameServer->connectionConfirm(1);
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
