﻿#ifndef __MAP_INFO_DAO_TEST_H_
#define __MAP_INFO_DAO_TEST_H_

#include<iostream>
#include "MapInfoDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class MapInfoDaoTest
{
private:
	MapInfoDao* mapInfoDao;

	MapInfo * mapInfo1;
	MapInfo * mapInfo2;
	MapInfo * mapInfo3;
	MapInfo * mapInfo4;

	MapInfo item[10];
public:
	MapInfoDaoTest();
	~MapInfoDaoTest();
	void setApplicationContext(ApplicationContext* context);
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