#ifndef  _EVENT_OBJECT_H_
#define  _EVENT_OBJECT_H_

#include <iostream>
#include "../util/cJSON.h"

using namespace std;

class  EventObject
{
private:
	int code;
	string name;
	string type;
	time_t time;
	string place;
	string speaker;
	string lines;
public:
	~EventObject();

	void setCode(int code);
	int getCode();

	void setName(string name);
	string getName();

	void setType(string type);
	string getType();

	void setTime(time_t time);
	time_t getTime();

	void setPlace(string place);
	string getPlace();

	void setSpeaker(string speaker);
	string getSpeaker();

	void setLines(string lines);
	string getLines();
};

#endif