#include "DataSource.h"

DataSource::DataSource(const char* host, const char* user, const char* pass, const char* database)
{
	strcpy(this->host, host);
	strcpy(this->user, user);
	strcpy(this->pass, pass);
	strcpy(this->database, database);

	mysql_init(&this->connection);
	mysql_options(&this->connection, MYSQL_SET_CHARSET_NAME, "utf8");
	mysql_options(&this->connection, MYSQL_INIT_COMMAND, "SET NAMES euckr");

	if (!mysql_real_connect(&this->connection, host, user, pass, database, 3306, (char *)NULL, 0))
		std::cout << "Mysql connection error : " << mysql_error(&this->connection) << std::endl;
}

DataSource::~DataSource()
{
	mysql_close(&this->connection);
}

MYSQL DataSource::getConnection()
{
	return this->connection;
}