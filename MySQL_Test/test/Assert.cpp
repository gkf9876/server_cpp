﻿#include "Assert.h"

Assert::Assert()
{
}

Assert::~Assert()
{
}

void Assert::setApplicationContext(ApplicationContext* context)
{
	chattingDao = context->chattingDao();
	inventoryInfoDao = context->inventoryInfoDao();
	mapDao = context->mapDao();
	mapInfoDao = context->mapInfoDao();
	monsterDao = context->monsterDao();
	serverInfoDao = context->serverInfoDao();
	userDao = context->userDao();

	chattingService = context->chattingService();
	mapManageService = context->mapManageService();
	userService = context->userService();
}

void Assert::assertThatLog(GameClient* gameClient, int value, int compValue)
{
	if (value != compValue)
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		gameClient->addLog(o.str());
	}
}

void Assert::assertThatLog(GameClient* gameClient, char* value, char* compValue)
{
	if (strcmp(value, compValue))
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		gameClient->addLog(o.str());
	}
}

void Assert::assertThatLog(GameClient* gameClient, char* value, const char* compValue)
{
	if (strcmp(value, compValue))
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		gameClient->addLog(o.str());
	}
}

void Assert::assertThatLog(GameClient* gameClient, string value, string compValue)
{
	if (value.compare(compValue) != 0)
	{
		std::ostringstream o;
		o << "\tExpected is: <" << compValue << "> but: was <" << value << ">";
		gameClient->addLog(o.str());
	}
}

void Assert::checkSameUserLog(GameClient* gameClient, User user1, User user2)
{
	assertThatLog(gameClient, user1.getSock(), user2.getSock());
	assertThatLog(gameClient, user1.getName(), user2.getName());
	assertThatLog(gameClient, user1.getPassword(), user2.getPassword());
	assertThatLog(gameClient, user1.getXpos(), user2.getXpos());
	assertThatLog(gameClient, user1.getYpos(), user2.getYpos());
	assertThatLog(gameClient, user1.getField(), user2.getField());
	assertThatLog(gameClient, user1.getSeeDirection(), user2.getSeeDirection());
	assertThatLog(gameClient, user1.getAction(), user2.getAction());
	assertThatLog(gameClient, user1.getLogin(), user2.getLogin());
	assertThatLog(gameClient, user1.getLastLogin(), user2.getLastLogin());
	assertThatLog(gameClient, user1.getLastLogout(), user2.getLastLogout());
	assertThatLog(gameClient, user1.getJoinDate(), user2.getJoinDate());
}

void Assert::checkSameChatLog(GameClient* gameClient, Chatting chat1, Chatting chat2)
{
	assertThatLog(gameClient, chat1.getName(), chat2.getName());
	assertThatLog(gameClient, chat1.getContent(), chat2.getContent());
	assertThatLog(gameClient, chat1.getField(), chat2.getField());
}

void Assert::checkSameMapInfoLog(GameClient* gameClient, MapInfo mapInfo1, MapInfo mapInfo2)
{
	assertThatLog(gameClient, mapInfo1.getField(), mapInfo2.getField());
	assertThatLog(gameClient, mapInfo1.getObjectCode(), mapInfo2.getObjectCode());
	assertThatLog(gameClient, mapInfo1.getName(), mapInfo2.getName());
	assertThatLog(gameClient, mapInfo1.getType(), mapInfo2.getType());
	assertThatLog(gameClient, mapInfo1.getXpos(), mapInfo2.getXpos());
	assertThatLog(gameClient, mapInfo1.getYpos(), mapInfo2.getYpos());
	assertThatLog(gameClient, mapInfo1.getZOrder(), mapInfo2.getZOrder());
	assertThatLog(gameClient, mapInfo1.getFileDir(), mapInfo2.getFileDir());
	assertThatLog(gameClient, mapInfo1.getCount(), mapInfo2.getCount());
	assertThatLog(gameClient, mapInfo1.getHp(), mapInfo2.getHp());
}

void Assert::checkSameInventoryInfoLog(GameClient* gameClient, InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2)
{
	assertThatLog(gameClient, inventoryInfo1.getItemName(), inventoryInfo2.getItemName());
	assertThatLog(gameClient, inventoryInfo1.getUserName(), inventoryInfo2.getUserName());
	assertThatLog(gameClient, inventoryInfo1.getType(), inventoryInfo2.getType());
	assertThatLog(gameClient, inventoryInfo1.getXpos(), inventoryInfo2.getXpos());
	assertThatLog(gameClient, inventoryInfo1.getYpos(), inventoryInfo2.getYpos());
	assertThatLog(gameClient, inventoryInfo1.getFileDir(), inventoryInfo2.getFileDir());
	assertThatLog(gameClient, inventoryInfo1.getCount(), inventoryInfo2.getCount());
}

void Assert::checkSameDatabaseChattingListLog(GameClient* gameClient)
{
	int chattingSize;
	User mainUser = gameClient->getMainUser();

	list<Chatting> fieldChattingList = this->chattingDao->getFieldChatting(mainUser.getField());
	list<Chatting>::iterator iter = fieldChattingList.begin();
	assertThatLog(gameClient, fieldChattingList.size(), gameClient->sizeChattingInfo());

	if (gameClient->sizeChattingInfo() > fieldChattingList.size())
		chattingSize = fieldChattingList.size();
	else
		chattingSize = gameClient->sizeChattingInfo();

	for (int i=0; i<gameClient->sizeChattingInfo(); i++)
	{
		Chatting dbFieldChatting = *iter;
		checkSameChatLog(gameClient, gameClient->getChattingInfo(i), dbFieldChatting);
		iter++;
	}
}

void Assert::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void Assert::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void Assert::checkSameChat(Chatting chat1, Chatting chat2)
{
	assertThat(chat1.getName(), chat2.getName());
	assertThat(chat1.getContent(), chat2.getContent());
	assertThat(chat1.getField(), chat2.getField());
}