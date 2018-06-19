#ifndef __USER_SERVICE_H_
#define __USER_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/UserDao.h"
#include "../dao/InventoryInfoDao.h"

using namespace std;

class UserService
{
private:
	UserDao* userDao;
	InventoryInfoDao* inventoryInfoDao;
	DataSource* dataSource;
public:
	UserService();
	~UserService();
	void setUserDao(UserDao* userDao);
	void setInventoryInfoDao(InventoryInfoDao* inventoryInfoDao);

	User getUserInfo(const char* name);
	User getUserInfo(int sock);
	void updateLogout(const char* name);
	void updateLogin(int sock, const char* name);
	list<User> getLoginUserAll();
	list<User> getFieldLoginUserAll(const char* field);
	int getUserCount(const char* field);
	list<InventoryInfo> getUserInventoryInfo(const char* name);
	void updateUserInfo(User userInfo);
	void deleteInventoryItem(const char* name, int xpos, int ypos);
	void addInventoryItem(InventoryInfo inventoryInfo);
	bool insertUserInfo(User userInfo);
	void moveInventoryItem(InventoryInfo inventoryInfo, int xpos, int ypos);
};

#endif