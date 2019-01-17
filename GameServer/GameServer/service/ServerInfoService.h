#ifndef __SERVER_INFO_SERVICE_H_
#define __SERVER_INFO_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/ServerInfoDao.h"

using namespace std;

class ServerInfoService
{
private:
	ServerInfoDao* serverInfoDao;
	DataSource* dataSource;
public:
	ServerInfoService();
	~ServerInfoService();
	void setServerInfoDao(ServerInfoDao* serverInfoDao);

	ServerInfo getServerInfo(int idx);
	void updateServerInfo(ServerInfo serverInfo);
};

#endif