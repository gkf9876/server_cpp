#include "ChattingDao.h"

ChattingDao::ChattingDao(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

ChattingDao::~ChattingDao()
{
}

void ChattingDao::add(Chatting chatting)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "chatting(");
	sprintf(&query[strlen(query)], "inputdate, name, content, field) values(");
	sprintf(&query[strlen(query)], "sysdate(), ");
	sprintf(&query[strlen(query)], "'%s', ", chatting.getName());
	sprintf(&query[strlen(query)], "'%s', ", chatting.getContent());
	sprintf(&query[strlen(query)], "'%s') ", chatting.getField());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void ChattingDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from chatting");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	initAutoIncrement();
}

void ChattingDao::initAutoIncrement()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "alter table chatting auto_increment=1");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int ChattingDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from chatting");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

Chatting ChattingDao::get(int idx)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select inputdate, name, content, field from chatting where idx='%d'", idx);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	Chatting chatting;

	if (sql_row != NULL)
	{
		chatting.setIdx(idx);
		chatting.setInputdate(sql_row[0]);
		chatting.setName(sql_row[1]);
		chatting.setContent(sql_row[2]);
		chatting.setField(sql_row[3]);
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

	return chatting;
}