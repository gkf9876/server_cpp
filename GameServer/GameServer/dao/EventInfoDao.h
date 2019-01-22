#ifndef __EVENT_INFO_DAO_H_
#define __EVENT_INFO_DAO_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/EventInfo.h"

using namespace std;

class EventInfoDao
{
private:
	DataSource* dataSource;
public:
	EventInfoDao();
	~EventInfoDao();
	void setDataSource(DataSource* dataSource);

	void add(EventInfo eventInfo);
	void deleteAll();
	int getCount();
	int getCount(const char * name, const char * content);
	EventInfo get(const char* name, const char * content);
	list<EventInfo> getEventList(const char * name);
};

#endif
