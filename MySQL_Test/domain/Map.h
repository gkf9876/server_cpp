#ifndef __MAP_H_
#define __MAP_H_

#include <iostream>
#include <string.h>

using namespace std;

class Map
{
private:
	int idx;
	char field[100];
	char monster1[50];
	char monster2[50];
	char monster3[50];
	int monster1Count;
	int monster2Count;
	int monster3Count;
public:
	Map();
	~Map();

	void setIdx(int idx);
	int getIdx();

	void setField(const char* field);
	const char* getField();

	void setMonster1(const char* monster1);
	const char* getMonster1();

	void setMonster2(const char* monster2);
	const char* getMonster2();

	void setMonster3(const char* monster3);
	const char* getMonster3();

	void setMonster1Count(int monster1Count);
	int getMonster1Count();

	void setMonster2Count(int monster2Count);
	int getMonster2Count();

	void setMonster3Count(int monster3Count);
	int getMonster3Count();
};

#endif
