#ifndef __USER_H_
#define __USER_H_

#include <iostream>
#include <string.h>

#define ACTION_MAP_IN		0
#define ACTION_MAP_MOVE		1
#define ACTION_MAP_OUT		2
#define ACTION_MAP_POTAL	3
#define ACTION_MAP_MOVE_END	4
#define ACTION_ATTACK       5
#define ACTION_ATTACK_END   6

using namespace std;

class User
{
private:
	int sock;
	char name[50];
	char password[50];
	int xpos;
	int ypos;
	char field[100];
	int seeDirection;
	int action;
	int login;
	char lastLogin[20];
	char lastLogout[20];
	char joinDate[20];
public:
	User();
	~User();

	void setSock(int sock);
	int getSock();

	void setName(const char* name);
	const char* getName();

	void setPassword(const char* password);
	const char* getPassword();

	void setXpos(int xpos);
	int getXpos();

	void setYpos(int ypos);
	int getYpos();

	void setField(const char* field);
	const char* getField();

	void setSeeDirection(int seeDirection);
	int getSeeDirection();

	void setAction(int action);
	int getAction();

	void setLogin(int login);
	int getLogin();

	void setLastLogin(const char* lastLogin);
	const char* getLastLogin();

	void setLastLogout(const char* lastLogout);
	const char* getLastLogout();

	void setJoinDate(const char* joinDate);
	const char* getJoinDate();
};

#endif
