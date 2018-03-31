#include "UserDao.h"

UserDao::UserDao(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

UserDao::~UserDao()
{
}

void UserDao::add(User user)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "user_list(");
	sprintf(&query[strlen(query)], "sock, name, password, xpos, ypos, field, seeDirection, action, login, lastLogin, lastLogout, joinDate) values(");
	sprintf(&query[strlen(query)], "'%d', ", user.getSock());
	sprintf(&query[strlen(query)], "'%s', ", user.getName());
	sprintf(&query[strlen(query)], "'%s', ", user.getPassword());
	sprintf(&query[strlen(query)], "'%d', ", user.getXpos());
	sprintf(&query[strlen(query)], "'%d', ", user.getYpos());
	sprintf(&query[strlen(query)], "'%s', ", user.getField());
	sprintf(&query[strlen(query)], "'%d', ", user.getSeeDirection());
	sprintf(&query[strlen(query)], "'%d', ", user.getAction());
	sprintf(&query[strlen(query)], "'%d', ", user.getLogin());
	sprintf(&query[strlen(query)], "'%s', ", user.getLastLogin());
	sprintf(&query[strlen(query)], "'%s', ", user.getLastLogout());
	sprintf(&query[strlen(query)], "'%s') ", user.getJoinDate());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void UserDao::update(User user)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	
	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "user_list ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "sock = '%d', "			, user.getSock());
	sprintf(&query[strlen(query)], "password = '%s', "		, user.getPassword());
	sprintf(&query[strlen(query)], "xpos = '%d', "			, user.getXpos());
	sprintf(&query[strlen(query)], "ypos = '%d', "			, user.getYpos());
	sprintf(&query[strlen(query)], "field = '%s', "			, user.getField());
	sprintf(&query[strlen(query)], "seeDirection = '%d', "	, user.getSeeDirection());
	sprintf(&query[strlen(query)], "action = '%d', "		, user.getAction());
	sprintf(&query[strlen(query)], "login = '%d', "			, user.getLogin());
	sprintf(&query[strlen(query)], "lastLogin = '%s', "		, user.getLastLogin());
	sprintf(&query[strlen(query)], "lastLogout = '%s', "	, user.getLastLogout());
	sprintf(&query[strlen(query)], "joinDate = '%s' "		, user.getJoinDate());
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "name = '%s'"			, user.getName());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void UserDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from user_list");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int UserDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from user_list");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

int UserDao::getCount(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(name) as count from user_list where field = '%s'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

User UserDao::get(const char* name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select sock, password, xpos, ypos, field, seeDirection, action, login, lastLogin, lastLogout, joinDate from user_list where name='%s'", name);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	User user;

	if (sql_row != NULL)
	{
		user.setSock(atoi(sql_row[0]));
		user.setName(name);
		user.setPassword(sql_row[1]);
		user.setXpos(atoi(sql_row[2]));
		user.setYpos(atoi(sql_row[3]));
		user.setField(sql_row[4]);
		user.setSeeDirection(atoi(sql_row[5]));
		user.setAction(atoi(sql_row[6]));
		user.setLogin(atoi(sql_row[7]));
		user.setLastLogin(sql_row[8]);
		user.setLastLogout(sql_row[9]);
		user.setJoinDate(sql_row[10]);
	}
	else
	{
		string error_message = "unknown name: ";
		error_message.append(name);
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return user;
}

User UserDao::get(int sock)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select name, password, xpos, ypos, field, seeDirection, action, login, lastLogin, lastLogout, joinDate from user_list where sock='%d'", sock);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	User user;

	if (sql_row != NULL)
	{
		user.setSock(sock);
		user.setName(sql_row[0]);
		user.setPassword(sql_row[1]);
		user.setXpos(atoi(sql_row[2]));
		user.setYpos(atoi(sql_row[3]));
		user.setField(sql_row[4]);
		user.setSeeDirection(atoi(sql_row[5]));
		user.setAction(atoi(sql_row[6]));
		user.setLogin(atoi(sql_row[7]));
		user.setLastLogin(sql_row[8]);
		user.setLastLogout(sql_row[9]);
		user.setJoinDate(sql_row[10]);
	}
	else
	{
		string error_message = "unknown sock: ";

		std::ostringstream o;
		o << sock;

		error_message.append(o.str());
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return user;
}

void UserDao::updateLogout(const char* name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update user_list set login = '0', sock = '0', lastLogout = sysdate() where name = '%s' and login = '1'", name);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void UserDao::updateLogin(int sock, const char* name)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update user_list set login = '1', sock = '%d', lastLogin = sysdate() where name = '%s'", sock, name);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

list<User> UserDao::getLoginUserAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from user_list where login='1'");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	User user;
	list<User> userList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		user.setSock(atoi(sql_row[0]));
		user.setName(sql_row[1]);
		user.setPassword(sql_row[2]);
		user.setXpos(atoi(sql_row[3]));
		user.setYpos(atoi(sql_row[4]));
		user.setField(sql_row[5]);
		user.setSeeDirection(atoi(sql_row[6]));
		user.setAction(atoi(sql_row[7]));
		user.setLogin(atoi(sql_row[8]));
		user.setLastLogin(sql_row[9]);
		user.setLastLogout(sql_row[10]);
		user.setJoinDate(sql_row[11]);
		userList.push_back(user);
	}

	mysql_free_result(sql_result);

	return userList;
}

list<User> UserDao::getFieldLoginUserAll(const char* field)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select * from user_list where login='1' and field='%s'", field);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	User user;
	list<User> userList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		user.setSock(atoi(sql_row[0]));
		user.setName(sql_row[1]);
		user.setPassword(sql_row[2]);
		user.setXpos(atoi(sql_row[3]));
		user.setYpos(atoi(sql_row[4]));
		user.setField(sql_row[5]);
		user.setSeeDirection(atoi(sql_row[6]));
		user.setAction(atoi(sql_row[7]));
		user.setLogin(atoi(sql_row[8]));
		user.setLastLogin(sql_row[9]);
		user.setLastLogout(sql_row[10]);
		user.setJoinDate(sql_row[11]);
		userList.push_back(user);
	}

	mysql_free_result(sql_result);

	return userList;
}