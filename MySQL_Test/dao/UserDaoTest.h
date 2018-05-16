#ifndef __USER_DAO_TEST_H_
#define __USER_DAO_TEST_H_

#include<iostream>
#include "UserDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class UserDaoTest
{
private:
	UserDao* userDao;

	User * user1;
	User * user2;
	User * user3;
public:
	UserDaoTest();
	~UserDaoTest();
	void setApplicationContext(ApplicationContext* context);
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
	void getAllUser();
};

#endif