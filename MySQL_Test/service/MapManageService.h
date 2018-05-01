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
	MapManageService();
	~MapManageService();
	void setMapDao(MapDao* mapDao);
	void setMapInfoDao(MapInfoDao* mapInfoDao);
	void setMonsterDao(MonsterDao* monsterDao);
	void setDataSource(DataSource* dataSource);

	void regenMonster();
	list<MapInfo> getFieldMonster(const char* field);
	list<MapInfo> getFieldObject(const char* field);
	void addFieldMapInfo(MapInfo mapInfo);
	MapInfo getMaxOrderItem(const char* field, int xpos, int ypos);
	list<MapInfo> getFieldItem(const char* field);
	void deleteMaxOrderItem(const char* field, int xpos, int ypos);
};

#endif