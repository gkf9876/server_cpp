#include "UserService.h"

UserService::UserService(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->userDao = new UserDao(dataSource);
}

UserService::~UserService()
{
	delete this->userDao;
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