#include "MapInfoDao.h"

MapInfoDao::MapInfoDao()
{
}

MapInfoDao::~MapInfoDao()
{
}

void MapInfoDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void MapInfoDao::add(MapInfo mapInfo)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "map_info(");
	sprintf(&query[strlen(query)], "field, object_code, name, type, xpos, ypos, z_order, file_dir, count, hp) values(");
	sprintf(&query[strlen(query)], "'%s', ", mapInfo.getField());
	sprintf(&query[strlen(query)], "'%d', ", mapInfo.getObjectCode());
	sprintf(&query[strlen(query)], "'%s', ", mapInfo.getName());
	sprintf(&query[strlen(query)], "'%s', ", mapInfo.getType());
	sprintf(&query[strlen(query)], "'%d', ", mapInfo.getXpos());
	sprintf(&query[strlen(query)], "'%d', ", mapInfo.getYpos());
	sprintf(&query[strlen(query)], "'%d', ", mapInfo.getZOrder());
	sprintf(&query[strlen(query)], "'%s', ", mapInfo.getFileDir());
	sprintf(&query[strlen(query)], "'%d', ", mapInfo.getCount());
	sprintf(&query[strlen(query)], "'%d') ", mapInfo.getHp());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void MapInfoDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from map_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	initAutoIncrement();
}

void MapInfoDao::initAutoIncrement()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "alter table map_info auto_increment=1");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int MapInfoDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(idx) as count from map_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

int MapInfoDao::getCountFieldMonster(const char* field, const char* name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from map_info where field = '%s' and name = '%s' and type = 'MONSTER'", field, name);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

MapInfo MapInfoDao::getMonster(const char* field, int xpos, int ypos)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, field, object_code, name, z_order, file_dir, count, hp from map_info where xpos='%d' and ypos='%d' and type = 'MONSTER' and field = '%s'", xpos, ypos, field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	MapInfo mapInfo;

	if (sql_row != NULL)
	{
		mapInfo.setIdx(atoi(sql_row[0]));
		mapInfo.setField(sql_row[1]);
		mapInfo.setObjectCode(atoi(sql_row[2]));
		mapInfo.setName(sql_row[3]);
		mapInfo.setType("MONSTER");
		mapInfo.setXpos(xpos);
		mapInfo.setYpos(ypos);
		mapInfo.setZOrder(atoi(sql_row[4]));
		mapInfo.setFileDir(sql_row[5]);
		mapInfo.setCount(atoi(sql_row[6]));
		mapInfo.setHp(atoi(sql_row[7]));
	}
	else
	{
		mapInfo.setName("nothing");
	}

	mysql_free_result(sql_result);

	return mapInfo;
}

list<MapInfo> MapInfoDao::getFieldMonster(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from map_info where field='%s' and type='MONSTER'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	MapInfo monster;
	list<MapInfo> monsterList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		monster.setIdx(atoi(sql_row[0]));
		monster.setField(sql_row[1]);
		monster.setObjectCode(atoi(sql_row[2]));
		monster.setName(sql_row[3]);
		monster.setType(sql_row[4]);
		monster.setXpos(atoi(sql_row[5]));
		monster.setYpos(atoi(sql_row[6]));
		monster.setZOrder(atoi(sql_row[7]));
		monster.setFileDir(sql_row[8]);
		monster.setCount(atoi(sql_row[9]));
		monster.setHp(atoi(sql_row[10]));
		monsterList.push_back(monster);
	}

	mysql_free_result(sql_result);

	return monsterList;
}

list<MapInfo> MapInfoDao::getFieldObject(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from map_info where field='%s' and type='OBJECT'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	MapInfo object;
	list<MapInfo> objectList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		object.setIdx(atoi(sql_row[0]));
		object.setField(sql_row[1]);
		object.setObjectCode(atoi(sql_row[2]));
		object.setName(sql_row[3]);
		object.setType(sql_row[4]);
		object.setXpos(atoi(sql_row[5]));
		object.setYpos(atoi(sql_row[6]));
		object.setZOrder(atoi(sql_row[7]));
		object.setFileDir(sql_row[8]);
		object.setCount(atoi(sql_row[9]));
		object.setHp(atoi(sql_row[10]));
		objectList.push_back(object);
	}

	mysql_free_result(sql_result);

	return objectList;
}

int MapInfoDao::getCountFieldMonster(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from map_info where field = '%s' and type = 'MONSTER'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

int MapInfoDao::getCountFieldObject(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from map_info where field = '%s' and type = 'OBJECT'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

MapInfo MapInfoDao::getMaxOrderItem(const char* field, int xpos, int ypos)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select A.idx, A.field, A.object_code, A.name, A.z_order, A.file_dir, A.count, A.hp from map_info A,(select max(z_order) as z_order from map_info where xpos='%d' and ypos='%d' and type = 'ITEM' and field = '%s') B where xpos='%d' and ypos='%d' and type = 'ITEM' and field = '%s' and B.z_order = A.z_order", xpos, ypos, field, xpos, ypos, field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	MapInfo mapInfo;

	if (sql_row != NULL)
	{
		mapInfo.setIdx(atoi(sql_row[0]));
		mapInfo.setField(sql_row[1]);
		mapInfo.setObjectCode(atoi(sql_row[2]));
		mapInfo.setName(sql_row[3]);
		mapInfo.setType("ITEM");
		mapInfo.setXpos(xpos);
		mapInfo.setYpos(ypos);
		mapInfo.setZOrder(atoi(sql_row[4]));
		mapInfo.setFileDir(sql_row[5]);
		mapInfo.setCount(atoi(sql_row[6]));
		mapInfo.setHp(atoi(sql_row[7]));
	}
	else
	{
		mapInfo.setName("nothing");
		mapInfo.setXpos(xpos);
		mapInfo.setYpos(ypos);
		mapInfo.setZOrder(-1);
	}

	mysql_free_result(sql_result);

	return mapInfo;
}

int MapInfoDao::getCountFieldItem(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from map_info where field = '%s' and type = 'ITEM'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

list<MapInfo> MapInfoDao::getFieldItem(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from map_info where field='%s' and type='ITEM'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	MapInfo object;
	list<MapInfo> objectList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		object.setIdx(atoi(sql_row[0]));
		object.setField(sql_row[1]);
		object.setObjectCode(atoi(sql_row[2]));
		object.setName(sql_row[3]);
		object.setType(sql_row[4]);
		object.setXpos(atoi(sql_row[5]));
		object.setYpos(atoi(sql_row[6]));
		object.setZOrder(atoi(sql_row[7]));
		object.setFileDir(sql_row[8]);
		object.setCount(atoi(sql_row[9]));
		object.setHp(atoi(sql_row[10]));
		objectList.push_back(object);
	}

	mysql_free_result(sql_result);

	return objectList;
}

void MapInfoDao::deleteMapInfo(int idx, const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from map_info where field='%s' and idx='%d'", field, idx);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}