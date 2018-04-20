#ifndef __DATA_SOURCE_H__
#define __DATA_SOURCE_H__

#include <iostream>

#ifdef _WIN32
#include <mysql.h>
#elif __linux__
#include "mysql/mysql.h"
#endif

#include <string.h>

class DataSource
{
private:
	char host[20];
	char user[20];
	char pass[20];
	char database[20];

	MYSQL connection;
public:
	DataSource(const char* host, const char* user, const char* pass, const char* database);
	~DataSource();

	MYSQL getConnection();
};

#endif
