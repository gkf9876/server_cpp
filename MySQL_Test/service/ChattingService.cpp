#include "ChattingService.h"

ChattingService::ChattingService()
{
}

ChattingService::~ChattingService()
{
}

void ChattingService::setChattingDao(ChattingDao* chattingDao)
{
	this->chattingDao = chattingDao;
}

void ChattingService::add(Chatting chatting)
{
	chattingDao->add(chatting);
}

Chatting ChattingService::getLatestChatting(const char* userName, const char* field)
{
	list<Chatting> getChattingList = chattingDao->getUserFieldChatting(userName, field);
	list<Chatting>::iterator iter = getChattingList.begin();

	for (int i=0; i<getChattingList.size() - 1; i++)
	{
		iter++;
	}

	return *iter;
}