#ifndef __MAP_MANAGE_SERVICE_H_
#define __MAP_MANAGE_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/MapDao.h"
#include "../dao/MapInfoDao.h"
#include "../dao/MonsterDao.h"

class MapManageService
{
private:
	MapDao* mapDao;
	MapInfoDao* mapInfoDao;
	MonsterDao* monsterDao;
	DataSource* dataSource;
public:
	MapManageService(DataSource* dataSource);
	~MapManageService();

	void regenMonster();
};

#endif