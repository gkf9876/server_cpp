#ifndef __INVENTORY_INFO_DAO_H_
#define __INVENTORY_INFO_DAO_H_

#include <iostream>
#include <stdio.h>
#include "../datasource/DataSource.h"
#include "../domain/InventoryInfo.h"

using namespace std;

class InventoryInfoDao
{
private:
	DataSource* dataSource;
public:
	InventoryInfoDao(DataSource* dataSource);
	~InventoryInfoDao();

	void add(InventoryInfo inventoryInfo);
	void deleteAll();
	void initAutoIncrement();
	int getCount();
	InventoryInfo get(const char* itemName);
	void update(InventoryInfo inventoryInfo);
};

#endif
