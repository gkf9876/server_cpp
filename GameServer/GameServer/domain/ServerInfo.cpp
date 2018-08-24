#include "ServerInfo.h"

ServerInfo::ServerInfo()
{

}

ServerInfo::~ServerInfo()
{

}

void ServerInfo::setIdx(int idx)
{
	this->idx = idx;
}

int ServerInfo::getIdx()
{
	return this->idx;
}

void ServerInfo::setInputdate(const char* inputdate)
{
	strcpy(this->inputdate, inputdate);
}

const char* ServerInfo::getInputdate()
{
	return this->inputdate;
}