#include "EventInfo.h"

EventInfo::EventInfo()
{

}

EventInfo::~EventInfo()
{

}

void EventInfo::setIdx(int idx)
{
	this->idx = idx;
}

int EventInfo::getIdx()
{
	return this->idx;
}

void EventInfo::setInputdate(const char * inputdate)
{
	strcpy(this->inputdate, inputdate);
}

const char * EventInfo::getInputdate()
{
	return this->inputdate;
}

void EventInfo::setName(const char * name)
{
	strcpy(this->name, name);
}

const char * EventInfo::getName()
{
	return this->name;
}

void EventInfo::setContent(const char * content)
{
	strcpy(this->content, content);
}

const char * EventInfo::getContent()
{
	return this->content;
}

void EventInfo::setField(const char * field)
{
	strcpy(this->field, field);
}

const char * EventInfo::getField()
{
	return this->field;
}

void EventInfo::setXpos(int xpos)
{
	this->xpos = xpos;
}

int EventInfo::getXpos()
{
	return this->xpos;
}

void EventInfo::setYpos(int ypos)
{
	this->ypos = ypos;
}

int EventInfo::getYpos()
{
	return this->ypos;
}
