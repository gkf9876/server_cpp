#ifndef __MAP_DAO_TEST_H_
#define __MAP_DAO_TEST_H_

#include<iostream>
#include "../datasource/DataSource.h"
#include "MapDao.h"

using namespace std;

class MapDaoTest
{
private:
	DataSource* dataSource;
	MapDao* mapDao;

	Map * map1;
	Map * map2;
	Map * map3;
public:
	MapDaoTest();
	~MapDaoTest();
	void run();

	void assertThat(int value, int compValue);
	void assertThat(const char* value, const char* compValue);
	void checkSameMap(Map map1, Map map2);

	void update();
	void select();
};

#endif