#include "EventObject.h"

EventObject::~EventObject()
{
}

void EventObject::setCode(int code)
{
	this->code = code;
}

int EventObject::getCode()
{
	return this->code;
}

void EventObject::setName(string name)
{
	this->name = name;
}

string EventObject::getName()
{
	return this->name;
}

void EventObject::setType(string type)
{
	this->type = type;
}

string EventObject::getType()
{
	return this->type;
}

void EventObject::setTime(time_t time)
{
	this->time = time;
}

time_t EventObject::getTime()
{
	return this->time;
}

void EventObject::setPlace(string place)
{
	this->place = place;
}

string EventObject::getPlace()
{
	return this->place;
}

void EventObject::setSpeaker(string speaker)
{
	this->speaker = speaker;
}

string EventObject::getSpeaker()
{
	return this->speaker;
}

void EventObject::setLines(string lines)
{
	this->lines = lines;
}

string EventObject::getLines()
{
	return this->lines;
}