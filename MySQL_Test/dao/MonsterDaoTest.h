#ifndef __MONSTER_DAO_TEST_H_
#define __MONSTER_DAO_TEST_H_

#include<iostream>
#include "../datasource/DataSource.h"
#include "MonsterDao.h"

using namespace std;

class MonsterDaoTest
{
private:
	DataSource* dataSource;
	MonsterDao* monsterDao;

	Monster * monster1;
	Monster * monster2;
	Monster * monster3;
public:
	MonsterDaoTest();
	~MonsterDaoTest();
	void run();

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameMonster(Monster monster1, Monster monster2);

	void addAndGet();
	void getMonsterFailure();
	void duplciateKey();
	void update();
};

#endif