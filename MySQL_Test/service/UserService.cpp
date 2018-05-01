#include "UserService.h"

UserService::UserService(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->userDao = new UserDao(dataSource);
	this->inventoryInfoDao = new InventoryInfoDao(dataSource);
}

UserService::~UserService()
{
	delete this->userDao;
	delete this->inventoryInfoDao;
}

User UserService::getUserInfo(const char* name)
{
	return userDao->get(name);
}

User UserService::getUserInfo(int sock)
{
	return userDao->get(sock);
}

void UserService::updateLogout(const char* name)
{
	userDao->updateLogout(name);
}

void UserService::updateLogin(int sock, const char* name)
{
	userDao->updateLogin(sock, name);
}

list<User> UserService::getLoginUserAll()
{
	return userDao->getLoginUserAll();
}

list<User> UserService::getFieldLoginUserAll(const char* field)
{
	return userDao->getFieldLoginUserAll(field);
}

int UserService::getUserCount(const char* field)
{
	return userDao->getCount(field);
}

list<InventoryInfo> UserService::getUserInventoryInfo(const char* name)
{
	return inventoryInfoDao->getUserInventoryList(name);
}

void UserService::updateUserInfo(User userInfo)
{
	userDao->update(userInfo);
}

void UserService::deleteInventoryItem(const char* name, int xpos, int ypos)
{
	inventoryInfoDao->deleteInventoryInfo(name, xpos, ypos);
}

void UserService::addInventoryItem(InventoryInfo inventoryInfo)
{
	inventoryInfoDao->add(inventoryInfo);
}