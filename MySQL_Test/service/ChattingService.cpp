#include "ChattingService.h"

ChattingService::ChattingService(DataSource* dataSource)
{
	this->dataSource = dataSource;
	this->chattingDao = new ChattingDao(dataSource);
}

ChattingService::~ChattingService()
{
	delete this->chattingDao;
}

void ChattingService::add(Chatting chatting)
{
	chattingDao->add(chatting);
}