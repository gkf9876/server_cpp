#ifndef __MAP_INFO_DAO_H_
#define __MAP_INFO_DAO_H_

#include <iostream>
#include <stdio.h>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/MapInfo.h"

using namespace std;

class MapInfoDao
{
private:
	DataSource* dataSource;
public:
	MapInfoDao(DataSource* dataSource);
	~MapInfoDao();

	void add(MapInfo mapinfo);
	void deleteAll();
	void initAutoIncrement();
	int getCount();
	int getCountFieldMonster(const char* field, const char* name);
	MapInfo getMonster(int xpos, int ypos);
	list<MapInfo> getFieldMonster(const char* field);
	list<MapInfo> getFieldObject(const char* field);
};

#endif
