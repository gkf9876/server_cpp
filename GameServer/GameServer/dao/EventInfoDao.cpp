#include "EventInfoDao.h"

EventInfoDao::EventInfoDao()
{
}

EventInfoDao::~EventInfoDao()
{
}

void EventInfoDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void EventInfoDao::add(EventInfo eventInfo)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "event_info(");
	sprintf(&query[strlen(query)], "inputdate, name, content, field, xpos, ypos) values(");
	sprintf(&query[strlen(query)], "sysdate(), ");
	sprintf(&query[strlen(query)], "'%s', ", eventInfo.getName());
	sprintf(&query[strlen(query)], "'%s', ", eventInfo.getContent());
	sprintf(&query[strlen(query)], "'%s', ", eventInfo.getField());
	sprintf(&query[strlen(query)], "'%d', ", eventInfo.getXpos());
	sprintf(&query[strlen(query)], "'%d'", eventInfo.getYpos());
	sprintf(&query[strlen(query)], ") ");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void EventInfoDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from event_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int EventInfoDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from event_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

int EventInfoDao::getCount(const char * name, const char * content)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(content) as count from event_info where name = '%s' and content = '%s'", name, content);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

EventInfo EventInfoDao::get(const char * name, const char * content)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, inputdate, name, content, field, xpos, ypos from event_info where name='%s' and content='%s'", name, content);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	EventInfo eventInfo;

	if (sql_row != NULL)
	{
		eventInfo.setIdx(atoi(sql_row[0]));
		eventInfo.setInputdate(sql_row[1]);
		eventInfo.setName(sql_row[2]);
		eventInfo.setContent(sql_row[3]);
		eventInfo.setField(sql_row[4]);
		eventInfo.setXpos(atoi(sql_row[5]));
		eventInfo.setYpos(atoi(sql_row[6]));
	}
	else
	{
		string error_message = "unknown name or content: ";
		error_message.append(name);
		error_message.append(",");
		error_message.append(content);
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return eventInfo;
}

list<EventInfo> EventInfoDao::getEventList(const char * name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from event_info where name='%s'", name);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	EventInfo eventInfo;
	list<EventInfo> eventInfoList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		eventInfo.setIdx(atoi(sql_row[0]));
		eventInfo.setInputdate(sql_row[1]);
		eventInfo.setName(sql_row[2]);
		eventInfo.setContent(sql_row[3]);
		eventInfo.setField(sql_row[4]);
		eventInfo.setXpos(atoi(sql_row[5]));
		eventInfo.setYpos(atoi(sql_row[6]));
		eventInfoList.push_back(eventInfo);
	}

	mysql_free_result(sql_result);

	return eventInfoList;
}
