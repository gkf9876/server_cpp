#ifndef __MAP_MANAGE_SERVICE_TEST_H_
#define __MAP_MANAGE_SERVICE_TEST_H_

#include <iostream>
#include "MapManageService.h"
#include "../datasource/DataSource.h"

class MapManageServiceTest
{
private:
	MapManageService* mapManageService;
	DataSource* dataSource;

	MapDao* mapDao;
	MapInfoDao* mapInfoDao;
	MonsterDao* monsterDao;

	Map* map1;
	Map* map2;
	Map* map3;

	Monster monster1;
	Monster monster2;
	Monster monster3;
	Monster monster4;
	Monster monster5;
	Monster monster6;
	Monster monster7;
	Monster monster8;
	Monster monster9;

	MapInfo mapInfo1;
	MapInfo mapInfo2;
	MapInfo mapInfo3;
public:
	MapManageServiceTest();
	~MapManageServiceTest();
	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void run();

	void regenMonster();
	void regenMonsterTransaction();
};

#endif