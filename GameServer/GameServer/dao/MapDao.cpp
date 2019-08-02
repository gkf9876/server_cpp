#include "MapDao.h"

MapDao::MapDao()
{
}

MapDao::~MapDao()
{
}

void MapDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void MapDao::add(Map map)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "map_list(");
	sprintf(&query[strlen(query)], "field, monster1, monster2, monster3, monster1_count, monster2_count, monster3_count) values(");
	sprintf(&query[strlen(query)], "'%s', ", map.getField());
	sprintf(&query[strlen(query)], "'%s', ", map.getMonster1());
	sprintf(&query[strlen(query)], "'%s', ", map.getMonster2());
	sprintf(&query[strlen(query)], "'%s', ", map.getMonster3());
	sprintf(&query[strlen(query)], "'%d', ", map.getMonster1Count());
	sprintf(&query[strlen(query)], "'%d', ", map.getMonster2Count());
	sprintf(&query[strlen(query)], "'%d') ", map.getMonster3Count());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void MapDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from map_list");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	initAutoIncrement();
}

void MapDao::initAutoIncrement()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "alter table map_list auto_increment=1");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int MapDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(field) as count from map_list");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

Map MapDao::get(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, monster1, monster2, monster3, monster1_count, monster2_count, monster3_count from map_list where field='%s'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	Map map;

	if (sql_row != NULL)
	{
		map.setIdx(atoi(sql_row[0]));
		map.setField(field);
		map.setMonster1(sql_row[1]);
		map.setMonster2(sql_row[2]);
		map.setMonster3(sql_row[3]);
		map.setMonster1Count(atoi(sql_row[4]));
		map.setMonster2Count(atoi(sql_row[5]));
		map.setMonster3Count(atoi(sql_row[6]));
	}
	else
	{
		string error_message = "unknown name: ";
		error_message.append(field);
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return map;
}

void MapDao::update(Map map)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "map_list ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "monster1 = '%s', ", map.getMonster1());
	sprintf(&query[strlen(query)], "monster2 = '%s', ", map.getMonster2());
	sprintf(&query[strlen(query)], "monster3 = '%s', ", map.getMonster3());
	sprintf(&query[strlen(query)], "monster1_count = '%d', ", map.getMonster1Count());
	sprintf(&query[strlen(query)], "monster2_count = '%d', ", map.getMonster2Count());
	sprintf(&query[strlen(query)], "monster3_count = '%d' ", map.getMonster3Count());
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "field = '%s'", map.getField ());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

list<Map> MapDao::getAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "SELECT IDX, FIELD, MONSTER1, MONSTER2, MONSTER3, MONSTER1_COUNT, MONSTER2_COUNT, MONSTER3_COUNT FROM map_list");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	Map map;
	list<Map> mapList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		map.setIdx(atoi(sql_row[0]));
		map.setField(sql_row[1]);
		map.setMonster1(sql_row[2]);
		map.setMonster2(sql_row[3]);
		map.setMonster3(sql_row[4]);
		map.setMonster1Count(atoi(sql_row[5]));
		map.setMonster2Count(atoi(sql_row[6]));
		map.setMonster3Count(atoi(sql_row[7]));
		mapList.push_back(map);
	}

	mysql_free_result(sql_result);

	return mapList;
}