#ifndef __EVENT_INFO_SERVICE_TEST_H_
#define __EVENT_INFO_SERVICE_TEST_H_

#include <iostream>
#include "EventInfoService.h"
#include "../datasource/DataSource.h"
#include "../factory/ApplicationContext.h"

class EventInfoServiceTest
{
private:
	EventInfoService* eventInfoService;
	EventInfoDao* eventInfoDao;

	EventInfo* eventInfo1;
	EventInfo* eventInfo2;
	EventInfo* eventInfo3;
public:
	EventInfoServiceTest();
	~EventInfoServiceTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThat(int value, int compValue);
	void assertThat(bool value, bool compValue);
	void assertThat(string value, string compValue);
	void checkSameEventInfo(EventInfo eventInfo1, EventInfo eventInfo2);
	void run();

	void isRunEvent();
};

#endif