#ifndef __LOADING_SCREEN_H_
#define __LOADING_SCREEN_H_

#include <iostream>
#include <string.h>

using namespace std;

class LoadingScreen
{
private:
	int idx;
	char name[100];
	char filePath[100];
public:
	LoadingScreen();
	~LoadingScreen();

	void setIdx(int idx);
	int getIdx();

	void setName(const char* name);
	const char* getName();

	void setFilePath(const char* filePath);
	const char* getFilePath();
};

#endif
