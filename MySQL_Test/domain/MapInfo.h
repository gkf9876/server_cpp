#ifndef __MAP_INFO_H_
#define __MAP_INFO_H_

#include <iostream>
#include <string.h>

using namespace std;

class MapInfo
{
private:
	int idx;
	char field[100];
	int objectCode;
	char name[50];
	char type[50];
	int xpos;
	int ypos;
	int zOrder;
	char fileDir[100];
	int count;
	int hp;
public:
	MapInfo();
	~MapInfo();
	bool operator<(const MapInfo &t);

	void setIdx(int idx);
	int getIdx();

	void setField(const char* field);
	const char* getField();

	void setObjectCode(int objectCode);
	int getObjectCode();

	void setName(const char* name);
	const char* getName();

	void setType(const char* type);
	const char* getType();

	void setXpos(int xpos);
	int getXpos();

	void setYpos(int ypos);
	int getYpos();

	void setZOrder(int zOrder);
	int getZOrder();

	void setFileDir(const char* fileDir);
	const char* getFileDir();

	void setCount(int count);
	int getCount();

	void setHp(int hp);
	int getHp();
};

#endif
