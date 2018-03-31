#ifndef __MAP_DAO_H_
#define __MAP_DAO_H_

#include <iostream>
#include <stdio.h>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/Map.h"

using namespace std;

class MapDao
{
private:
	DataSource* dataSource;
public:
	MapDao(DataSource* dataSource);
	~MapDao();

	void add(Map map);
	void deleteAll();
	void initAutoIncrement();
	int getCount();
	Map get(const char* field);
	void update(Map map);
	list<Map> getAll();
};

#endif
