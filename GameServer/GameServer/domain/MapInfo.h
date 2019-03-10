﻿#ifndef __MAP_INFO_H_
#define __MAP_INFO_H_

#include <iostream>
#include <string.h>

#define ACTION_MAP_IN		0
#define ACTION_MAP_MOVE		1
#define ACTION_MAP_OUT		2
#define ACTION_MAP_POTAL	3
#define ACTION_MAP_MOVE_END	4
#define ACTION_ATTACK       5
#define ACTION_ATTACK_END   6

#define ACTION_UP_MOVE_1	7
#define ACTION_UP_MOVE_2	8
#define ACTION_UP_MOVE_3	9
#define ACTION_UP_MOVE_4	10

#define ACTION_DOWN_MOVE_1	11
#define ACTION_DOWN_MOVE_2	12
#define ACTION_DOWN_MOVE_3	13
#define ACTION_DOWN_MOVE_4	14

#define ACTION_RIGHT_MOVE_1	15
#define ACTION_RIGHT_MOVE_2	16
#define ACTION_RIGHT_MOVE_3	17
#define ACTION_RIGHT_MOVE_4	18

#define ACTION_LEFT_MOVE_1	19
#define ACTION_LEFT_MOVE_2	20
#define ACTION_LEFT_MOVE_3	21
#define ACTION_LEFT_MOVE_4	22

#define ACTION_UP_ATTACK	23
#define ACTION_DOWN_ATTACK	24
#define ACTION_RIGHT_ATTACK	25
#define ACTION_LEFT_ATTACK	26

#define ACTION_UP_READY		27
#define ACTION_DOWN_READY	28
#define ACTION_RIGHT_READY	29
#define ACTION_LEFT_READY	30

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
	int seeDirection;
	int action;
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

	void setSeeDirection(int seeDirection);
	int getSeeDirection();

	void setAction(int action);
	int getAction();
};

#endif
