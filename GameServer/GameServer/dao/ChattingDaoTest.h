#ifndef __CHATTING_DAO_TEST_H_
#define __CHATTING_DAO_TEST_H_

#include<iostream>
#include "ChattingDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class ChattingDaoTest
{
private:
	ChattingDao* chattingDao;

	Chatting * chat1;
	Chatting * chat2;
	Chatting * chat3;
public:
	ChattingDaoTest();
	~ChattingDaoTest();
	void setApplicationContext(ApplicationContext* context);
	void run();

	void assertThat(int value, int compValue);
	void assertThat(const char* value, const char* compValue);
	void checkSameChat(Chatting chat1, Chatting chat2);

	void addAndGet();
	void getFieldChatting();
	void getUserFieldChatting();
};

#endif