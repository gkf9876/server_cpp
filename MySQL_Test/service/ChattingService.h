#ifndef __CHATTING_SERVICE_H_
#define __CHATTING_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/ChattingDao.h"

class ChattingService
{
private:
	ChattingDao* chattingDao;
	DataSource* dataSource;
public:
	ChattingService(DataSource* dataSource);
	~ChattingService();

	void add(Chatting chatting);
};

#endif