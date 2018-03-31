#ifndef __CHATTING_SERVICE_TEST_H_
#define __CHATTING_SERVICE_TEST_H_

#include <iostream>
#include "ChattingService.h"
#include "../datasource/DataSource.h"

class ChattingServiceTest
{
private:
	ChattingService* chattingService;
	ChattingDao* chattingDao;
	DataSource* dataSource;

	Chatting* chatting1;
	Chatting* chatting2;
	Chatting* chatting3;
public:
	ChattingServiceTest();
	~ChattingServiceTest();
	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameChatting(Chatting chatting1, Chatting chatting2);
	void run();

	void addAndGet();
};

#endif