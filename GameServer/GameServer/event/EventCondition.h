#ifndef  _EVENT_CONDITION_H_
#define  _EVENT_CONDITION_H_

#include <iostream>

using namespace std;

enum Period
{
	EVERY_DAY, EVERY_WEEK, EVERY_MONTH, ONE_DATE, NONE
};

class  EventCondition
{
private:
	Period period;
	time_t time;
	string mapName;
	int xpos;
	int ypos;
	string procedeEventName;
public:
	void setPeriod(Period period);
	Period getPeriod();

	void setTime(time_t time);
	time_t getTime();

	void setMapName(string mapName);
	string getMapName();

	void setXpos(int xpos);
	int getXpos();

	void setYpos(int ypos);
	int getYpos();

	void setProcedeEventName(string procedeEventName);
	string getProcedeEventName();
};

#endif