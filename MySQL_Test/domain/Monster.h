#ifndef __MONSTER_H_
#define __MONSTER_H_

#include <iostream>
#include <string.h>

using namespace std;

class Monster
{
private:
	int idx;
	char name[50];
	char type[50];
	char fileDir[100];
	int hp;
public:
	Monster();
	~Monster();

	void setIdx(int idx);
	int getIdx();

	void setName(const char* name);
	const char* getName();

	void setType(const char* type);
	const char* getType();

	void setFileDir(const char* fileDir);
	const char* getFileDir();

	void setHp(int hp);
	int getHp();
};

#endif
