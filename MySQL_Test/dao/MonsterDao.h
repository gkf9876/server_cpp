#ifndef __MONSTER_DAO_H_
#define __MONSTER_DAO_H_

#include <iostream>
#include <stdio.h>
#include "../datasource/DataSource.h"
#include "../domain/Monster.h"

using namespace std;

class MonsterDao
{
private:
	DataSource* dataSource;
public:
	MonsterDao(DataSource* dataSource);
	~MonsterDao();

	void add(Monster monster);
	void update(Monster monster);
	void deleteAll();
	void initAutoIncrement();
	int getCount();
	Monster get(const char* name);
};

#endif
