#ifndef __MAP_MANAGE_SERVICE_TEST_H_
#define __MAP_MANAGE_SERVICE_TEST_H_

#include <iostream>
#include "MapManageService.h"
#include "../datasource/DataSource.h"
#include "../factory/ApplicationContext.h"

class MapManageServiceTest
{
private:
	MapManageService* mapManageService;

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
	MapInfo mapInfo4;
	MapInfo mapInfo5;

	MapInfo item[10];
public:
	MapManageServiceTest();
	~MapManageServiceTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameMapInfo(MapInfo mapInfo1, MapInfo mapInfo2);
	void run();

	void regenMonster();
	void regenMonsterTransaction();
	void getFieldMonster();
	void getFieldObject();
	void addFieldMapInfo();
	void getMaxOrderItem();
	void getFieldItem();
	void deleteMaxOrderItem();
};

#endif