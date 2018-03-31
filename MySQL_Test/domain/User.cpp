#include "User.h"

User::User()
{

}

User::~User()
{

}

void User::setSock(int sock)
{
	this->sock = sock;
}

int User::getSock()
{
	return this->sock;
}

void User::setName(const char* name)
{
	strcpy(this->name, name);
}

const char* User::getName()
{
	return this->name;
}

void User::setPassword(const char* password)
{
	strcpy(this->password, password);
}

const char* User::getPassword()
{
	return this->password;
}

void User::setXpos(int xpos)
{
	this->xpos = xpos;
}

int User::getXpos()
{
	return this->xpos;
}

void User::setYpos(int ypos)
{
	this->ypos = ypos;
}

int User::getYpos()
{
	return this->ypos;
}

void User::setField(const char* field)
{
	strcpy(this->field, field);
}

const char* User::getField()
{
	return this->field;
}

void User::setSeeDirection(int seeDirection)
{
	this->seeDirection = seeDirection;
}

int User::getSeeDirection()
{
	return this->seeDirection;
}

void User::setAction(int action)
{
	this->action = action;
}

int User::getAction()
{
	return this->action;
}

void User::setLogin(int login)
{
	this->login = login;
}

int User::getLogin()
{
	return this->login;
}

void User::setLastLogin(const char* lastLogin)
{
	strcpy(this->lastLogin, lastLogin);
}

const char* User::getLastLogin()
{
	return this->lastLogin;
}

void User::setLastLogout(const char* lastLogout)
{
	strcpy(this->lastLogout, lastLogout);
}

const char* User::getLastLogout()
{
	return this->lastLogout;
}

void User::setJoinDate(const char* joinDate)
{
	strcpy(this->joinDate, joinDate);
}

const char* User::getJoinDate()
{
	return this->joinDate;
}