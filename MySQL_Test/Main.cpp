#include <iostream>
#include "GameServerTest.h"

#include "factory/ApplicationContext.h"
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
	ApplicationContext* context = new ApplicationContext();

	UserDaoTest * userDaoTest = new UserDaoTest();
	userDaoTest->setApplicationContext(context);
	userDaoTest->run();
	delete userDaoTest;

	ChattingDaoTest * chattingDaoTest = new ChattingDaoTest();
	chattingDaoTest->setApplicationContext(context);
	chattingDaoTest->run();
	delete chattingDaoTest;
	
	InventoryInfoDaoTest * inventoryInfoDaoTest = new InventoryInfoDaoTest();
	inventoryInfoDaoTest->setApplicationContext(context);
	inventoryInfoDaoTest->run();
	delete inventoryInfoDaoTest;
	
	MapDaoTest * mapDaoTest = new MapDaoTest();
	mapDaoTest->setApplicationContext(context);
	mapDaoTest->run();
	delete mapDaoTest;
	
	MapInfoDaoTest * mapInfoDaoTest = new MapInfoDaoTest();
	mapInfoDaoTest->setApplicationContext(context);
	mapInfoDaoTest->run();
	delete mapInfoDaoTest;
	
	MonsterDaoTest * monsterDaoTest = new MonsterDaoTest();
	monsterDaoTest->setApplicationContext(context);
	monsterDaoTest->run();
	delete monsterDaoTest;
	
	MapManageServiceTest* mapManageServiceTest = new MapManageServiceTest();
	mapManageServiceTest->setApplicationContext(context);
	mapManageServiceTest->run();
	delete mapManageServiceTest;
	
	UserServiceTest* userServiceTest = new UserServiceTest();
	userServiceTest->setApplicationContext(context);
	userServiceTest->run();
	delete userServiceTest;
	
	ChattingServiceTest* chattingServiceTest = new ChattingServiceTest();
	chattingServiceTest->setApplicationContext(context);
	chattingServiceTest->run();
	delete chattingServiceTest;
	
	GameServerTest * gameServerTest = new GameServerTest();
	gameServerTest->setApplicationContext(context);
	gameServerTest->run();
	delete gameServerTest;

	delete context;
	return 0;
}
