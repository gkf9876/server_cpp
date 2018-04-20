#include "MapInfo.h"

MapInfo::MapInfo()
{

}

MapInfo::~MapInfo()
{

}

void MapInfo::setIdx(int idx)
{
	this->idx = idx;
}

int MapInfo::getIdx()
{
	return this->idx;;
}

void MapInfo::setField(const char* field)
{
	strcpy(this->field, field);
}

const char* MapInfo::getField()
{
	return this->field;
}

void MapInfo::setObjectCode(int objectCode)
{
	this->objectCode = objectCode;
}

int MapInfo::getObjectCode()
{
	return this->objectCode;
}

void MapInfo::setName(const char* name)
{
	strcpy(this->name, name);
}

const char* MapInfo::getName()
{
	return this->name;
}

void MapInfo::setType(const char* type)
{
	strcpy(this->type, type);
}

const char* MapInfo::getType()
{
	return this->type;
}

void MapInfo::setXpos(int xpos)
{
	this->xpos = xpos;
}

int MapInfo::getXpos()
{
	return this->xpos;
}

void MapInfo::setYpos(int ypos)
{
	this->ypos = ypos;
}

int MapInfo::getYpos()
{
	return this->ypos;
}

void MapInfo::setZOrder(int zOrder)
{
	this->zOrder = zOrder;
}

int MapInfo::getZOrder()
{
	return this->zOrder;
}

void MapInfo::setFileDir(const char* fileDir)
{
	strcpy(this->fileDir, fileDir);
}

const char* MapInfo::getFileDir()
{
	return this->fileDir;
}

void MapInfo::setCount(int count)
{
	this->count = count;
}

int MapInfo::getCount()
{
	return this->count;
}

void MapInfo::setHp(int hp)
{
	this->hp = hp;
}

int MapInfo::getHp()
{
	return this->hp;
}