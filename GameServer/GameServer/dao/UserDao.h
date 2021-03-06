﻿#ifndef __USER_DAO_H_
#define __USER_DAO_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/User.h"

using namespace std;

class UserDao
{
private:
	DataSource* dataSource;
public:
	UserDao();
	~UserDao();
	void setDataSource(DataSource* dataSource);

	void add(User user);
	void update(User user);
	void deleteAll();
	int getCount();
	int getCount(const char* field);
	User get(const char* name);
	User get(int sock);
	void updateLogout(const char* name);
	void updateLogin(int sock, const char* name);
	list<User> getLoginUserAll();
	list<User> getFieldLoginUserAll(const char* field);
	list<User> getAllUser();

	void showLog(char* qurey);
};

#endif
