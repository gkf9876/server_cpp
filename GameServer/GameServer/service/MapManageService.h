#ifndef __MAP_MANAGE_SERVICE_H_
#define __MAP_MANAGE_SERVICE_H_

#include <iostream>
#include <list>
#include <map>
#include <time.h>
#include "../dao/MapDao.h"
#include "../dao/MapInfoDao.h"
#include "../dao/MonsterDao.h"

#include "../util/TMXLoader/TMXLoader.h"

class MapManageService
{
private:
	MapDao* mapDao;
	MapInfoDao* mapInfoDao;
	MonsterDao* monsterDao;
	DataSource* dataSource;

	std::map<std::string, TMXLoader*> mapData;
public:
	MapManageService();
	~MapManageService();
	void setMapDao(MapDao* mapDao);
	void setMapInfoDao(MapInfoDao* mapInfoDao);
	void setMonsterDao(MonsterDao* monsterDao);
	void setDataSource(DataSource* dataSource);

	list<MapInfo> regenMonster();
	list<MapInfo> getFieldMonster(const char* field);
	list<MapInfo> getFieldObject(const char* field);
	void addFieldMapInfo(MapInfo mapInfo);
	MapInfo getMaxOrderItem(const char* field, int xpos, int ypos);
	list<MapInfo> getFieldItem(const char* field);
	void deleteMaxOrderItem(const char* field, int xpos, int ypos);

	void loadTMXData();
};

#endif