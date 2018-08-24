﻿#include "ApplicationContext.h"

ApplicationContext::ApplicationContext()
{
}

ApplicationContext::~ApplicationContext()
{
	if (dataSourceInstance != NULL)
		delete this->dataSourceInstance;

	if (chattingDaoInstance != NULL)
		delete this->chattingDaoInstance;

	if (inventoryInfoDaoInstance != NULL)
		delete this->inventoryInfoDaoInstance;

	if (mapDaoInstance != NULL)
		delete this->mapDaoInstance;

	if (mapInfoDaoInstance != NULL)
		delete this->mapInfoDaoInstance;

	if (monsterDaoInstance != NULL)
		delete this->monsterDaoInstance;

	if (serverInfoDaoInstance != NULL)
		delete this->serverInfoDaoInstance;

	if (userDaoInstance != NULL)
		delete this->userDaoInstance;

	if (chattingServiceInstance != NULL)
		delete this->chattingServiceInstance;

	if (mapManageServiceInstance != NULL)
		delete this->mapManageServiceInstance;

	if (userServiceInstance != NULL)
		delete this->userServiceInstance;

	if (gameServerInstance != NULL)
		delete this->gameServerInstance;
}

DataSource* ApplicationContext::dataSource()
{
	if (this->dataSourceInstance != NULL)
		return this->dataSourceInstance;
	else
	{
		this->dataSourceInstance = new DataSource("127.0.0.1", "yona", "yonadan", "gameServer");
		return this->dataSourceInstance;
	}
}

ChattingDao* ApplicationContext::chattingDao()
{
	if (this->chattingDaoInstance != NULL)
		return this->chattingDaoInstance;
	else
	{
		this->chattingDaoInstance = new ChattingDao();
		this->chattingDaoInstance->setDataSource(dataSource());
		return this->chattingDaoInstance;
	}
}

InventoryInfoDao* ApplicationContext::inventoryInfoDao()
{
	if (this->inventoryInfoDaoInstance != NULL)
		return this->inventoryInfoDaoInstance;
	else
	{
		this->inventoryInfoDaoInstance = new InventoryInfoDao();
		this->inventoryInfoDaoInstance->setDataSource(dataSource());
		return this->inventoryInfoDaoInstance;
	}
}

MapDao* ApplicationContext::mapDao()
{
	if (this->mapDaoInstance != NULL)
		return this->mapDaoInstance;
	else
	{
		this->mapDaoInstance = new MapDao();
		this->mapDaoInstance->setDataSource(dataSource());
		return this->mapDaoInstance;
	}
}

MapInfoDao* ApplicationContext::mapInfoDao()
{
	if (this->mapInfoDaoInstance != NULL)
		return this->mapInfoDaoInstance;
	else
	{
		this->mapInfoDaoInstance = new MapInfoDao();
		this->mapInfoDaoInstance->setDataSource(dataSource());
		return this->mapInfoDaoInstance;
	}
}

MonsterDao* ApplicationContext::monsterDao()
{
	if (this->monsterDaoInstance != NULL)
		return this->monsterDaoInstance;
	else
	{
		this->monsterDaoInstance = new MonsterDao();
		this->monsterDaoInstance->setDataSource(dataSource());
		return this->monsterDaoInstance;
	}
}

ServerInfoDao* ApplicationContext::serverInfoDao()
{
	if (this->serverInfoDaoInstance != NULL)
		return this->serverInfoDaoInstance;
	else
	{
		this->serverInfoDaoInstance = new ServerInfoDao();
		this->serverInfoDaoInstance->setDataSource(dataSource());
		return this->serverInfoDaoInstance;
	}
}

UserDao* ApplicationContext::userDao()
{
	if (this->userDaoInstance != NULL)
		return this->userDaoInstance;
	else
	{
		this->userDaoInstance = new UserDao();
		this->userDaoInstance->setDataSource(dataSource());
		return this->userDaoInstance;
	}
}

ChattingService* ApplicationContext::chattingService()
{
	if (this->chattingServiceInstance != NULL)
		return this->chattingServiceInstance;
	else
	{
		this->chattingServiceInstance = new ChattingService();
		this->chattingServiceInstance->setChattingDao(chattingDao());
		return this->chattingServiceInstance;
	}
}

MapManageService* ApplicationContext::mapManageService()
{
	if (this->mapManageServiceInstance != NULL)
		return this->mapManageServiceInstance;
	else
	{
		this->mapManageServiceInstance = new MapManageService();
		this->mapManageServiceInstance->setMapDao(mapDao());
		this->mapManageServiceInstance->setMapInfoDao(mapInfoDao());
		this->mapManageServiceInstance->setMonsterDao(monsterDao());
		this->mapManageServiceInstance->setDataSource(dataSource());
		return this->mapManageServiceInstance;
	}
}

UserService* ApplicationContext::userService()
{
	if (this->userServiceInstance != NULL)
		return this->userServiceInstance;
	else
	{
		this->userServiceInstance = new UserService();
		this->userServiceInstance->setUserDao(userDao());
		this->userServiceInstance->setInventoryInfoDao(inventoryInfoDao());
		return this->userServiceInstance;
	}
}

GameServer* ApplicationContext::gameServer()
{
	if (this->gameServerInstance != NULL)
		return this->gameServerInstance;
	else
	{
		this->gameServerInstance = new GameServer();
		this->gameServerInstance->setUserService(userService());
		this->gameServerInstance->setChattingService(chattingService());
		this->gameServerInstance->setMapManageService(mapManageService());
	}
}