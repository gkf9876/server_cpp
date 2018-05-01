#ifndef __CHATTING_SERVICE_H_
#define __CHATTING_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/ChattingDao.h"

class ChattingService
{
private:
	ChattingDao* chattingDao;
public:
	ChattingService();
	~ChattingService();
	void setChattingDao(ChattingDao* chattingDao);

	void add(Chatting chatting);
};

#endif