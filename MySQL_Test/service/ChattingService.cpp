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