#ifndef __SERVER_INFO_DAO_H_
#define __SERVER_INFO_DAO_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/ServerInfo.h"

using namespace std;

class ServerInfoDao
{
private:
	DataSource* dataSource;
public:
	ServerInfoDao();
	~ServerInfoDao();
	void setDataSource(DataSource* dataSource);

	void update(ServerInfo info);
	ServerInfo get(int idx);

	void showLog(char* qurey);
};

#endif
