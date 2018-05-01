#include "ServerInfoDao.h"

ServerInfoDao::ServerInfoDao()
{

}

ServerInfoDao::~ServerInfoDao()
{

}

void ServerInfoDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}