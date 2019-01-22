#ifndef __EVENT_INFO_DAO_TEST_H_
#define __EVENT_INFO_DAO_TEST_H_

#include<iostream>
#include "EventInfoDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class EventInfoDaoTest
{
private:
	EventInfoDao* eventInfoDao;

	EventInfo * eventInfo1;
	EventInfo * eventInfo2;
	EventInfo * eventInfo3;
	EventInfo * eventInfo4;
	EventInfo * eventInfo5;
	EventInfo * eventInfo6;
public:
	EventInfoDaoTest();
	~EventInfoDaoTest();
	void setApplicationContext(ApplicationContext* context);
	void run();

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameEventInfo(EventInfo eventInfo1, EventInfo eventInfo2);

	void addAndGet();
	void getList();
};

#endif