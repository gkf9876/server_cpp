#ifndef __USER_DAO_TEST_H_
#define __USER_DAO_TEST_H_

#include<iostream>
#include "../datasource/DataSource.h"
#include "UserDao.h"

using namespace std;

class UserDaoTest
{
private:
	DataSource* dataSource;
	UserDao* userDao;

	User * user1;
	User * user2;
	User * user3;
public:
	UserDaoTest();
	~UserDaoTest();
	void run();

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameUser(User user1, User user2);

	void addAndGet1();
	void addAndGet2();
	void getUserFailure();
	void duplciateKey();
	void update();
	void getUserInfo();
	void updateLogout();
	void updateLogin();
	void getLoginUserAll();
	void getFieldLoginUserAll();
};

#endif