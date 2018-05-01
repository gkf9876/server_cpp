#include "InventoryInfoDao.h"

InventoryInfoDao::InventoryInfoDao()
{
}

InventoryInfoDao::~InventoryInfoDao()
{
}

void InventoryInfoDao::setDataSource(DataSource* dataSource)
{
	this->dataSource = dataSource;
}

void InventoryInfoDao::add(InventoryInfo InventoryInfo)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "insert into ");
	sprintf(&query[strlen(query)], "inventory_info(");
	sprintf(&query[strlen(query)], "itemName, userName, type, xpos, ypos, file_dir, count) values(");
	sprintf(&query[strlen(query)], "'%s', ", InventoryInfo.getItemName());
	sprintf(&query[strlen(query)], "'%s', ", InventoryInfo.getUserName());
	sprintf(&query[strlen(query)], "'%s', ", InventoryInfo.getType());
	sprintf(&query[strlen(query)], "'%d', ", InventoryInfo.getXpos());
	sprintf(&query[strlen(query)], "'%d', ", InventoryInfo.getYpos());
	sprintf(&query[strlen(query)], "'%s', ", InventoryInfo.getFileDir());
	sprintf(&query[strlen(query)], "'%d') ", InventoryInfo.getCount());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

void InventoryInfoDao::deleteAll()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from inventory_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	initAutoIncrement();
}

void InventoryInfoDao::initAutoIncrement()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "alter table inventory_info auto_increment=1");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

int InventoryInfoDao::getCount()
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select count(itemName) as count from inventory_info");

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);
	mysql_free_result(sql_result);

	return atoi(sql_row[0]);
}

InventoryInfo InventoryInfoDao::get(const char* itemName)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, userName, type, xpos, ypos, file_dir, count from inventory_info where itemName='%s'", itemName);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);
	sql_row = mysql_fetch_row(sql_result);

	InventoryInfo inventoryInfo;

	if (sql_row != NULL)
	{
		inventoryInfo.setIdx(atoi(sql_row[0]));
		inventoryInfo.setItemName(itemName);
		inventoryInfo.setUserName(sql_row[1]);
		inventoryInfo.setType(sql_row[2]);
		inventoryInfo.setXpos(atoi(sql_row[3]));
		inventoryInfo.setYpos(atoi(sql_row[4]));
		inventoryInfo.setFileDir(sql_row[5]);
		inventoryInfo.setCount(atoi(sql_row[6]));
	}
	else
	{
		string error_message = "unknown name: ";
		error_message.append(itemName);
		throw runtime_error(error_message);
	}

	mysql_free_result(sql_result);

	return inventoryInfo;
}

void InventoryInfoDao::update(InventoryInfo inventoryInfo)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "update ");
	sprintf(&query[strlen(query)], "inventory_info ");
	sprintf(&query[strlen(query)], "set ");
	sprintf(&query[strlen(query)], "idx = '%d', ", inventoryInfo.getIdx());
	sprintf(&query[strlen(query)], "userName = '%s', ", inventoryInfo.getUserName());
	sprintf(&query[strlen(query)], "type = '%s', ", inventoryInfo.getType());
	sprintf(&query[strlen(query)], "xpos = '%d', ", inventoryInfo.getXpos());
	sprintf(&query[strlen(query)], "ypos = '%d', ", inventoryInfo.getYpos());
	sprintf(&query[strlen(query)], "file_dir = '%s', ", inventoryInfo.getFileDir());
	sprintf(&query[strlen(query)], "count = '%d' ", inventoryInfo.getCount());
	sprintf(&query[strlen(query)], "WHERE ");
	sprintf(&query[strlen(query)], "itemName = '%s'", inventoryInfo.getItemName());

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}

list<InventoryInfo> InventoryInfoDao::getUserInventoryList(const char* userName)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	sprintf(query, "select idx, itemName, userName, type, xpos, ypos, file_dir, count from inventory_info where userName='%s' order by xpos asc, ypos asc", userName);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));

	sql_result = mysql_store_result(&connection);

	InventoryInfo inventoryInfo;
	list<InventoryInfo> inventoryInfoList;

	while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
	{
		inventoryInfo.setIdx(atoi(sql_row[0]));
		inventoryInfo.setItemName(sql_row[1]);
		inventoryInfo.setUserName(sql_row[2]);
		inventoryInfo.setType(sql_row[3]);
		inventoryInfo.setXpos(atoi(sql_row[4]));
		inventoryInfo.setYpos(atoi(sql_row[5]));
		inventoryInfo.setFileDir(sql_row[6]);
		inventoryInfo.setCount(atoi(sql_row[7]));

		inventoryInfoList.push_back(inventoryInfo);
	}

	mysql_free_result(sql_result);

	return inventoryInfoList;
}

void InventoryInfoDao::deleteInventoryInfo(const char* userName, int xpos, int ypos)
{
	char query[1024];
	int query_stat;
	MYSQL connection = this->dataSource->getConnection();

	sprintf(query, "delete from inventory_info where userName = '%s' and xpos = '%d' and ypos = '%d'", userName, xpos, ypos);

	query_stat = mysql_query(&connection, query);

	if (query_stat != 0)
		throw runtime_error(mysql_error(&connection));
}