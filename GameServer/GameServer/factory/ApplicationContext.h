#ifndef __APPLICATION_CONTEXT_H__
#define __APPLICATION_CONTEXT_H__

#include <iostream>

#include "../dao/ChattingDao.h"
#include "../dao/InventoryInfoDao.h"
#include "../dao/MapDao.h"
#include "../dao/MapInfoDao.h"
#include "../dao/MonsterDao.h"
#include "../dao/ServerInfoDao.h"
#include "../dao/UserDao.h"
#include "../dao/LoadingScreenDao.h"
#include "../dao/EventInfoDao.h"

#include "../service/ChattingService.h"
#include "../service/MapManageService.h"
#include "../service/UserService.h"
#include "../service/LoadingScreenService.h"
#include "../service/ServerInfoService.h"
#include "../service/EventInfoService.h"

#include "../GameServer.h"

class ApplicationContext
{
private:
	ChattingDao* chattingDaoInstance = NULL;
	InventoryInfoDao* inventoryInfoDaoInstance = NULL;
	MapDao* mapDaoInstance = NULL;
	MapInfoDao* mapInfoDaoInstance = NULL;
	MonsterDao* monsterDaoInstance = NULL;
	ServerInfoDao* serverInfoDaoInstance = NULL;
	UserDao* userDaoInstance = NULL;
	LoadingScreenDao* loadingScreenDaoInstance = NULL;
	EventInfoDao* eventInfoDaoInstance = NULL;

	ChattingService* chattingServiceInstance = NULL;
	MapManageService* mapManageServiceInstance = NULL;
	UserService* userServiceInstance = NULL;
	LoadingScreenService* loadingScreenServiceInstance = NULL;
	ServerInfoService* serverInfoServiceInstance = NULL;
	EventInfoService* eventInfoServiceInstance = NULL;

	GameServer* gameServerInstance = NULL;

protected:
	DataSource * dataSourceInstance = NULL;
public:
	ApplicationContext();
	~ApplicationContext();

	virtual DataSource* dataSource();

	ChattingDao* chattingDao();
	InventoryInfoDao* inventoryInfoDao();
	MapDao* mapDao();
	MapInfoDao* mapInfoDao();
	MonsterDao* monsterDao();
	ServerInfoDao* serverInfoDao();
	UserDao* userDao();
	LoadingScreenDao* loadingScreenDao();
	EventInfoDao* eventInfoDao();

	ChattingService* chattingService();
	MapManageService* mapManageService();
	UserService* userService();
	LoadingScreenService* loadingScreenService();
	ServerInfoService* serverInfoService();
	EventInfoService* eventInfoService();

	GameServer* gameServer();
};

#endif
