#include "Map.h"

Map::Map()
{

}
Map::~Map()
{

}

void Map::setIdx(int idx)
{
	this->idx = idx;
}

int Map::getIdx()
{
	return this->idx;
}

void Map::setField(const char* field)
{
	strcpy(this->field, field);
}

const char* Map::getField()
{
	return this->field;
}

void Map::setMonster1(const char* monster1)
{
	strcpy(this->monster1, monster1);
}

const char* Map::getMonster1()
{
	return this->monster1;
}

void Map::setMonster2(const char* monster2)
{
	strcpy(this->monster2, monster2);
}

const char* Map::getMonster2()
{
	return this->monster2;
}

void Map::setMonster3(const char* monster3)
{
	strcpy(this->monster3, monster3);
}

const char* Map::getMonster3()
{
	return this->monster3;
}

void Map::setMonster1Count(int monster1Count)
{
	this->monster1Count = monster1Count;
}

int Map::getMonster1Count()
{
	return this->monster1Count;
}

void Map::setMonster2Count(int monster2Count)
{
	this->monster2Count = monster2Count;
}

int Map::getMonster2Count()
{
	return this->monster2Count;
}

void Map::setMonster3Count(int monster3Count)
{
	this->monster3Count = monster3Count;
}

int Map::getMonster3Count()
{
	return this->monster3Count;
}