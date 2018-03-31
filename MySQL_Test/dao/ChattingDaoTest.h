#ifndef __CHATTING_DAO_TEST_H_
#define __CHATTING_DAO_TEST_H_

#include<iostream>
#include "../datasource/DataSource.h"
#include "ChattingDao.h"

using namespace std;

class ChattingDaoTest
{
private:
	DataSource* dataSource;
	ChattingDao* chattingDao;

	Chatting * chat1;
	Chatting * chat2;
	Chatting * chat3;
public:
	ChattingDaoTest();
	~ChattingDaoTest();
	void run();

	void assertThat(int value, int compValue);
	void assertThat(const char* value, const char* compValue);
	void checkSameChat(Chatting chat1, Chatting chat2);

	void addAndGet();
};

#endif