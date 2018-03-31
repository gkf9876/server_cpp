#include "Monster.h"

Monster::Monster()
{

}

Monster::~Monster()
{

}

void Monster::setIdx(int idx)
{
	this->idx = idx;
}

int Monster::getIdx()
{
	return this->idx;
}

void Monster::setName(const char* name)
{
	strcpy(this->name, name);
}

const char* Monster::getName()
{
	return this->name;
}

void Monster::setType(const char* type)
{
	strcpy(this->type, type);
}

const char* Monster::getType()
{
	return this->type;
}

void Monster::setFileDir(const char* fileDir)
{
	strcpy(this->fileDir, fileDir);
}

const char* Monster::getFileDir()
{
	return this->fileDir;
}

void Monster::setHp(int hp)
{
	this->hp = hp;
}

int Monster::getHp()
{
	return this->hp;
}