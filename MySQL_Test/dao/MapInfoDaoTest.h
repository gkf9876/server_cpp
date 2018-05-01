#ifndef __MAP_INFO_DAO_TEST_H_
#define __MAP_INFO_DAO_TEST_H_

#include<iostream>
#include "../datasource/DataSource.h"
#include "MapInfoDao.h"

using namespace std;

class MapInfoDaoTest
{
private:
	DataSource* dataSource;
	MapInfoDao* mapInfoDao;

	MapInfo * mapInfo1;
	MapInfo * mapInfo2;
	MapInfo * mapInfo3;
	MapInfo * mapInfo4;

	MapInfo item[10];
public:
	MapInfoDaoTest();
	~MapInfoDaoTest();
	void run();

	void assertThat(int value, int compValue);
	void assertThat(const char* value, const char* compValue);
	void checkSameMapInfo(MapInfo mapInfo1, MapInfo mapInfo2);

	void addAndGet();
	void getCountMonster();
	void getFieldMonster();
	void getFieldObject();
	void getMaxOrderItem();
	void getFieldItem();
	void deleteMapInfo();
};

#endif