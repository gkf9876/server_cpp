#ifndef __CHATTING_H_
#define __CHATTING_H_

#include <iostream>
#include <string.h>

using namespace std;

class Chatting
{
private:
	int idx;
	char inputdate[20];
	char name[50];
	char content[100];
	char field[100];
public:
	Chatting();
	~Chatting();

	void setIdx(int idx);
	int getIdx();

	void setInputdate(const char* inputdate);
	const char* getInputdate();

	void setName(const char* name);
	const char* getName();

	void setContent(const char* content);
	const char* getContent();

	void setField(const char* field);
	const char* getField();
};

#endif
