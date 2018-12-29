#include "LoadingScreenDao.h"

LoadingScreenDao::LoadingScreenDao()
{
}

LoadingScreenDao::~LoadingScreenDao()
{
}

void LoadingScreenDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void LoadingScreenDao::setIdxAutoIncrement(int value)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "ALTER TABLE loading_screen AUTO_INCREMENT=%d;", value);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void LoadingScreenDao::add(LoadingScreen loadingScreen)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "loading_screen(");
	sprintf(&query[strlen(query)], "name, file_path) values(");
	sprintf(&query[strlen(query)], "'%s', ", loadingScreen.getName());
	sprintf(&query[strlen(query)], "'%s')", loadingScreen.getFilePath());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void LoadingScreenDao::update(LoadingScreen loadingScreen)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	
	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "loading_screen ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "name = '%s', ", loadingScreen.getName());
	sprintf(&query[strlen(query)], "file_path = '%s' ", loadingScreen.getFilePath());
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "idx = '%d'", loadingScreen.getIdx());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void LoadingScreenDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from loading_screen");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int LoadingScreenDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from loading_screen");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

LoadingScreen LoadingScreenDao::get(int idx)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select name, file_path from loading_screen where idx='%d'", idx);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	LoadingScreen loadingScreen;

	if (sql_row != NULL)
	{
		loadingScreen.setIdx(idx);
		loadingScreen.setName(sql_row[0]);
		loadingScreen.setFilePath(sql_row[1]);
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

	return loadingScreen;
}