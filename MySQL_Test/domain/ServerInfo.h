#ifndef __SERVER_INFO_H_
#define __SERVER_INFO_H_

#include <iostream>
#include <string.h>

using namespace std;

class ServerInfo
{
private:
	int idx;
	char inputdate[20];
public:
	ServerInfo();
	~ServerInfo();

	void setIdx(int idx);
	int getIdx();

	void setInputdate(const char* inputdate);
	const char* getInputdate();
};

#endif
