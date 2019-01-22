#include "EventSequence.h"

EventSequence::~EventSequence()
{
	delete this->eventCondition;

	for (int i = 0; i < this->eventObjectList.size(); i++)
	{
		delete this->eventObjectList.at(i);
	}
}

void EventSequence::setName(string name)
{
	this->name = name;
}

string EventSequence::getName()
{
	return this->name;
}

void EventSequence::setEventObject(EventObject * eventObject)
{
	this->eventObjectList.push_back(eventObject);
}



EventObject * EventSequence::getEventObject(int idx)
{
	return this->eventObjectList.at(idx);
}

int EventSequence::getEventSize()
{
	return eventObjectList.size();;
}

void EventSequence::setEventCondition(EventCondition * eventCondition)
{
	this->eventCondition = eventCondition;
}

EventCondition * EventSequence::getEventCondition()
{
	return this->eventCondition;
}

bool EventSequence::isConfirmCondition(User user)
{
	bool period = false;
	bool map = false;
	bool procedeEvent = false;

	if (this->eventCondition->getPeriod() != NONE)
	{
		time_t now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  nowTm;
		nowTm = *localtime(&now);
		time_t conditionTime = eventCondition->getTime();
		struct tm conditionTm;
		conditionTm = *localtime(&conditionTime);

		switch (this->eventCondition->getPeriod())
		{
		case EVERY_DAY:
			if (conditionTm.tm_hour == nowTm.tm_hour)
				if (conditionTm.tm_min == nowTm.tm_min)
					if (conditionTm.tm_sec == nowTm.tm_sec)
						period = true;
					else
						period = false;
				else
					period = false;
			else
				period = false;
			break;
		case EVERY_WEEK:
			if (conditionTm.tm_wday == nowTm.tm_wday)
				if (conditionTm.tm_hour == nowTm.tm_hour)
					if (conditionTm.tm_min == nowTm.tm_min)
						if (conditionTm.tm_sec == nowTm.tm_sec)
							period = true;
						else
							period = false;
					else
						period = false;
				else
					period = false;
			else
				period = false;
			break;
		case EVERY_MONTH:
			if (conditionTm.tm_mday == nowTm.tm_mday)
				if (conditionTm.tm_hour == nowTm.tm_hour)
					if (conditionTm.tm_min == nowTm.tm_min)
						if (conditionTm.tm_sec == nowTm.tm_sec)
							period = true;
						else
							period = false;
					else
						period = false;
				else
					period = false;
			else
				period = false;
			break;
		case ONE_DATE:
			if (now == conditionTime)
				period = true;
			else
				period = false;
			break;
		}
	}
	else
		period = true;

	if (this->eventCondition->getMapName() != "\"none\"")
	{
		if (!strcmp(user.getField(), this->eventCondition->getMapName().c_str()))
		{
			if (this->eventCondition->getXpos() == user.getXpos() && this->eventCondition->getYpos() == user.getYpos())
				map = true;
			else
				map = false;
		}
		else
			map = false;
	}
	else
		map = true;

	if (this->eventCondition->getProcedeEventName() != "NONE")
	{

	}
	else
		procedeEvent = true;

	if (period == true && map == true && procedeEvent == true)
		return true;
	else
		return false;
}

bool EventSequence::getProgress()
{
	return this->progress;
}

void EventSequence::setProgress(bool progress)
{
	this->progress = progress;
}
