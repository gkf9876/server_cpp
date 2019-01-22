#ifndef  _EVENT_SEQUENCE_H_
#define  _EVENT_SEQUENCE_H_

#include <iostream>
#include <time.h>
#include <vector>

#include "../domain/User.h"
#include "../util/Util.h"

#include "EventObject.h"
#include "EventCondition.h"

using namespace std;

class  EventSequence
{
private:
	string name;
	EventCondition* eventCondition;
	vector<EventObject*> eventObjectList;
	bool progress = false;
public:
	~EventSequence();

	void setName(string name);
	string getName();

	void setEventObject(EventObject* eventObject);
	EventObject* getEventObject(int idx);

	int getEventSize();

	void setEventCondition(EventCondition* eventCondition);
	EventCondition * getEventCondition();

	bool isConfirmCondition(User user);

	bool getProgress();
	void setProgress(bool progress);

};

#endif