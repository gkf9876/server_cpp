#include "MonsterDao.h"

MonsterDao::MonsterDao()
{
}

MonsterDao::~MonsterDao()
{
}

void MonsterDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void MonsterDao::add(Monster monster)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "monster_list(");
	sprintf(&query[strlen(query)], "name, type, file_dir, hp) values(");
	sprintf(&query[strlen(query)], "'%s', ", monster.getName());
	sprintf(&query[strlen(query)], "'%s', ", monster.getType());
	sprintf(&query[strlen(query)], "'%s', ", monster.getFileDir());
	sprintf(&query[strlen(query)], "'%d') ", monster.getHp());

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void MonsterDao::update(Monster Monster)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "monster_list ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "type = '%s', ", Monster.getType());
	sprintf(&query[strlen(query)], "file_dir = '%s', ", Monster.getFileDir());
	sprintf(&query[strlen(query)], "hp = '%d' ", Monster.getHp());
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "name = '%s'", Monster.getName());

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void MonsterDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from monster_list");

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	initAutoIncrement();
}

void MonsterDao::initAutoIncrement()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "alter table monster_list auto_increment=1");

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int MonsterDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from monster_list");

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

Monster MonsterDao::get(const char* name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, type, file_dir, hp from monster_list where name='%s'", name);

	query_stat = mysql_query(&connection, query);
	//showLog(query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	Monster Monster;

	if (sql_row != NULL)
	{
		Monster.setIdx(atoi(sql_row[0]));
		Monster.setName(name);
		Monster.setType(sql_row[1]);
		Monster.setFileDir(sql_row[2]);
		Monster.setHp(atoi(sql_row[3]));
	}
	else
	{
		string error_message = "unknown name: ";
		error_message.append(name);
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return Monster;
}

void MonsterDao::showLog(char* query) {
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	printf("[%4d.%2d.%2d %2d:%2d:%2d]%s\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, query);
}