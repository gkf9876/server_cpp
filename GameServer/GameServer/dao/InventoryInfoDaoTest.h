﻿#ifndef __INVENTORY_INFO_DAO_TEST_H_
#define __INVENTORY_INFO_DAO_TEST_H_

#include <iostream>
#include <list>
#include "InventoryInfoDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class InventoryInfoDaoTest
{
private:
	InventoryInfoDao* inventoryInfoDao;

	InventoryInfo * inventoryInfo1;
	InventoryInfo * inventoryInfo2;
	InventoryInfo * inventoryInfo3;

	InventoryInfo item[20];
public:
	InventoryInfoDaoTest();
	~InventoryInfoDaoTest();
	void setApplicationContext(ApplicationContext* context);
	void run();

	void assertThat(int value, int compValue);
	void assertThat(const char* value, const char* compValue);
	void checkSameInventoryInfo(InventoryInfo inventory1, InventoryInfo inventory2);

	void addAndGet();
	void getUserFailure();
	void update();
	void getUserInventoryInfo();
	void deleteInventoryInfo();
};

#endif