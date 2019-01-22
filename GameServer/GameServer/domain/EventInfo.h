#ifndef __EVENT_INFO_H_
#define __EVENT_INFO_H_

#include <iostream>
#include <string.h>

using namespace std;

class EventInfo
{
private:
	int idx;
	char inputdate[20];
	char name[50];
	char content[100];
	char field[100];
	int xpos;
	int ypos;
public:
	EventInfo();
	~EventInfo();

	void setIdx(int idx);
	int getIdx();

	void setInputdate(const char * inputdate);
	const char * getInputdate();

	void setName(const char * name);
	const char * getName();

	void setContent(const char * content);
	const char * getContent();

	void setField(const char * field);
	const char * getField();

	void setXpos(int xpos);
	int getXpos();

	void setYpos(int ypos);
	int getYpos();
};

#endif
