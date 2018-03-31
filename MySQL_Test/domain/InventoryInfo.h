#ifndef __INVENTORY_INFO_H_
#define __INVENTORY_INFO_H_

#include <iostream>
#include <string.h>

using namespace std;

class InventoryInfo
{
private:
	int idx;
	char itemName[50];
	char userName[50];
	char type[50];
	int xpos;
	int ypos;
	char fileDir[100];
	int count;
public:
	InventoryInfo();
	~InventoryInfo();

	void setIdx(int idx);
	int getIdx();

	void setItemName(const char* itemName);
	const char* getItemName();

	void setUserName(const char* userName);
	const char* getUserName();

	void setType(const char* type);
	const char* getType();

	void setXpos(int xpos);
	int getXpos();

	void setYpos(int ypos);
	int getYpos();

	void setFileDir(const char* fileDir);
	const char* getFileDir();

	void setCount(int count);
	int getCount();
};

#endif
