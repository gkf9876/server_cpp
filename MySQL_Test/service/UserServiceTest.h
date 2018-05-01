#ifndef __USER_SERVICE_TEST_H_
#define __USER_SERVICE_TEST_H_

#include <iostream>
#include "UserService.h"
#include "../datasource/DataSource.h"
#include "../factory/ApplicationContext.h"

class UserServiceTest
{
private:
	UserService* userService;
	UserDao* userDao;
	InventoryInfoDao* inventoryInfoDao;

	User* user1;
	User* user2;
	User* user3;

	InventoryInfo item[20];
public:
	UserServiceTest();
	~UserServiceTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameUser(User user1, User user2);
	void checkSameInventoryInfo(InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2);
	void run();

	void getUserInfo1();
	void getUserInfo2();
	void updateLogout();
	void updateLogin();
	void getLoginUserAll();
	void getFieldLoginUserAll();
	void getUserInventoryInfo();
	void updateUserInfo();
	void deleteInventoryItem();
};

#endif