#include "InventoryInfo.h"

InventoryInfo::InventoryInfo()
{

}

InventoryInfo::~InventoryInfo()
{

}

void InventoryInfo::setIdx(int idx)
{
	this->idx = idx;
}

int InventoryInfo::getIdx()
{
	return this->idx;
}

void InventoryInfo::setItemName(const char* itemName)
{
	strcpy(this->itemName, itemName);
}

const char* InventoryInfo::getItemName()
{
	return this->itemName;
}

void InventoryInfo::setUserName(const char* userName)
{
	strcpy(this->userName, userName);
}

const char* InventoryInfo::getUserName()
{
	return this->userName;
}

void InventoryInfo::setType(const char* type)
{
	strcpy(this->type, type);
}

const char* InventoryInfo::getType()
{
	return this->type;
}

void InventoryInfo::setXpos(int xpos)
{
	this->xpos = xpos;
}

int InventoryInfo::getXpos()
{
	return this->xpos;
}

void InventoryInfo::setYpos(int ypos)
{
	this->ypos = ypos;
}

int InventoryInfo::getYpos()
{
	return this->ypos;
}

void InventoryInfo::setFileDir(const char* fileDir)
{
	strcpy(this->fileDir, fileDir);
}

const char* InventoryInfo::getFileDir()
{
	return this->fileDir;
}

void InventoryInfo::setCount(int count)
{
	this->count = count;
}

int InventoryInfo::getCount()
{
	return this->count;
}