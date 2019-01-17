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

void ServerInfoDao::update(ServerInfo info)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "server_info ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "inputdate = sysdate() ");
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "idx = '1'");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

ServerInfo ServerInfoDao::get(int idx)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, inputdate from server_info where idx='%d'", idx);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	ServerInfo info;

	if (sql_row != NULL)
	{
		info.setIdx(idx);
		info.setInputdate(sql_row[1]);
	}
	else
	{
		string error_message = "unknown idx: ";

		std::ostringstream o;
		o << idx;

		error_message.append(o.str());
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return info;
}
