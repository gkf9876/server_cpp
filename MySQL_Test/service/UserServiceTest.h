#ifndef __USER_SERVICE_TEST_H_
#define __USER_SERVICE_TEST_H_

#include <iostream>
#include "UserService.h"
#include "../datasource/DataSource.h"

class UserServiceTest
{
private:
	UserService* userService;
	UserDao* userDao;
	DataSource* dataSource;

	User* user1;
	User* user2;
	User* user3;
public:
	UserServiceTest();
	~UserServiceTest();
	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameUser(User user1, User user2);
	void run();

	void getUserInfo1();
	void getUserInfo2();
	void updateLogout();
	void updateLogin();
	void getLoginUserAll();
	void getFieldLoginUserAll();
};

#endif