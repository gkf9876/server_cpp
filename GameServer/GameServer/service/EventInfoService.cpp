#include "EventInfoService.h"

EventInfoService::EventInfoService()
{
}

EventInfoService::~EventInfoService()
{
}

void EventInfoService::setEventInfoDao(EventInfoDao* eventInfoDao)
{
	this->eventInfoDao = eventInfoDao;
}

void EventInfoService::addRunEvent(EventInfo eventInfo)
{
	this->eventInfoDao->add(eventInfo);
}

bool EventInfoService::isRunEvent(const char * name, const char * content)
{
	int count = this->eventInfoDao->getCount(name, content);

	if (count == 0)
		return false;
	else
		return true;
}

list<EventInfo> EventInfoService::getEventInfoList(const char * name)
{
	return this->eventInfoDao->getEventList(name);
}
