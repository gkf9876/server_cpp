#include <iostream>
#include "GameServerTest.h"

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
	UserDaoTest * userDaoTest = new UserDaoTest();
	userDaoTest->run();
	delete userDaoTest;

	ChattingDaoTest * chattingDaoTest = new ChattingDaoTest();
	chattingDaoTest->run();
	delete chattingDaoTest;
	
	InventoryInfoDaoTest * inventoryInfoDaoTest = new InventoryInfoDaoTest();
	inventoryInfoDaoTest->run();
	delete inventoryInfoDaoTest;
	
	MapDaoTest * mapDaoTest = new MapDaoTest();
	mapDaoTest->run();
	delete mapDaoTest;
	
	MapInfoDaoTest * mapInfoDaoTest = new MapInfoDaoTest();
	mapInfoDaoTest->run();
	delete mapInfoDaoTest;
	
	MonsterDaoTest * monsterDaoTest = new MonsterDaoTest();
	monsterDaoTest->run();
	delete monsterDaoTest;
	
	MapManageServiceTest* mapManageServiceTest = new MapManageServiceTest();
	mapManageServiceTest->run();
	delete mapManageServiceTest;
	
	UserServiceTest* userServiceTest = new UserServiceTest();
	userServiceTest->run();
	delete userServiceTest;
	
	ChattingServiceTest* chattingServiceTest = new ChattingServiceTest();
	chattingServiceTest->run();
	delete chattingServiceTest;
	
	GameServerTest * gameServerTest = new GameServerTest();
	gameServerTest->run();
	delete gameServerTest;

	return 0;
}
