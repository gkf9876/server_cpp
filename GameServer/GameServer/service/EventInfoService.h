#ifndef __EVENT_INFO_SERVICE_H_
#define __EVENT_INFO_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/EventInfoDao.h"

using namespace std;

class EventInfoService
{
private:
	EventInfoDao* eventInfoDao;
	DataSource* dataSource;
public:
	EventInfoService();
	~EventInfoService();
	void setEventInfoDao(EventInfoDao* eventInfoDao);

	void addRunEvent(EventInfo eventInfo);
	bool isRunEvent(const char * name, const char * content);
	list<EventInfo> getEventInfoList(const char * name);
};

#endif