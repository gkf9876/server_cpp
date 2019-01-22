#include "EventCondition.h"

void EventCondition::setPeriod(Period period)
{
	this->period = period;
}

Period EventCondition::getPeriod()
{
	return this->period;
}

void EventCondition::setTime(time_t time)
{
	this->time = time;
}

time_t EventCondition::getTime()
{
	return this->time;
}

void EventCondition::setMapName(string mapName)
{
	this->mapName = mapName;
}

string EventCondition::getMapName()
{
	return this->mapName;
}

void EventCondition::setXpos(int xpos)
{
	this->xpos = xpos;
}

int EventCondition::getXpos()
{
	return this->xpos;
}

void EventCondition::setYpos(int ypos)
{
	this->ypos = ypos;
}

int EventCondition::getYpos()
{
	return this->ypos;
}

void EventCondition::setProcedeEventName(string procedeEventName)
{
	this->procedeEventName = procedeEventName;
}

string EventCondition::getProcedeEventName()
{
	return this->procedeEventName;
}