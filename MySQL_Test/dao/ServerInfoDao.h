#ifndef __SERVER_INFO_DAO_H_
#define __SERVER_INFO_DAO_H_

#include <iostream>
#include <stdio.h>
#include "../datasource/DataSource.h"
#include "../domain/ServerInfo.h"

using namespace std;

class ServerInfoDao
{
private:
	DataSource* dataSource;
public:
	ServerInfoDao(DataSource* dataSource);
	~ServerInfoDao();
};

#endif
