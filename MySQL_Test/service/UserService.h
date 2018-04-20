#ifndef __USER_SERVICE_H_
#define __USER_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/UserDao.h"

using namespace std;

class UserService
{
private:
	UserDao* userDao;
	DataSource* dataSource;
public:
	UserService(DataSource* dataSource);
	~UserService();

	User getUserInfo(const char* name);
	User getUserInfo(int sock);
	void updateLogout(const char* name);
	void updateLogin(int sock, const char* name);
	list<User> getLoginUserAll();
	list<User> getFieldLoginUserAll(const char* field);
	int getUserCount(const char* field);
};

#endif