#ifndef __TEST_APPLICATION_CONTEXT_H__
#define __TEST_APPLICATION_CONTEXT_H__

#include "ApplicationContext.h"

class TestApplicationContext : public ApplicationContext
{
private:
	DataSource * dataSourceInstance = NULL;

	ChattingDao* chattingDaoInstance = NULL;
	InventoryInfoDao* inventoryInfoDaoInstance = NULL;
	MapDao* mapDaoInstance = NULL;
	MapInfoDao* mapInfoDaoInstance = NULL;
	MonsterDao* monsterDaoInstance = NULL;
	ServerInfoDao* serverInfoDaoInstance = NULL;
	UserDao* userDaoInstance = NULL;

	ChattingService* chattingServiceInstance = NULL;
	MapManageService* mapManageServiceInstance = NULL;
	UserService* userServiceInstance = NULL;

	GameServer* gameServerInstance = NULL;

public:
	TestApplicationContext();
	~TestApplicationContext();

	DataSource* dataSource();

	ChattingDao* chattingDao();
	InventoryInfoDao* inventoryInfoDao();
	MapDao* mapDao();
	MapInfoDao* mapInfoDao();
	MonsterDao* monsterDao();
	ServerInfoDao* serverInfoDao();
	UserDao* userDao();

	ChattingService* chattingService();
	MapManageService* mapManageService();
	UserService* userService();

	GameServer* gameServer();
};

#endif