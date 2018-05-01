#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <iostream>

#include "../factory/ApplicationContext.h"

#include "../dao/ChattingDao.h"
#include "../dao/InventoryInfoDao.h"
#include "../dao/MapDao.h"
#include "../dao/MapInfoDao.h"
#include "../dao/MonsterDao.h"
#include "../dao/ServerInfoDao.h"
#include "../dao/UserDao.h"

#include "../service/ChattingService.h"
#include "../service/MapManageService.h"
#include "../service/UserService.h"

#include "../GameServer.h"
#include "../GameClient.h"

class Assert
{
private:
	ChattingDao* chattingDao = NULL;
	InventoryInfoDao* inventoryInfoDao = NULL;
	MapDao* mapDao = NULL;
	MapInfoDao* mapInfoDao = NULL;
	MonsterDao* monsterDao = NULL;
	ServerInfoDao* serverInfoDao = NULL;
	UserDao* userDao = NULL;

	ChattingService* chattingService = NULL;
	MapManageService* mapManageService = NULL;
	UserService* userService = NULL;

public:
	Assert();
	~Assert();
	void setApplicationContext(ApplicationContext* context);

	void assertThatLog(GameClient* gameClient, int value, int compValue);
	void assertThatLog(GameClient* gameClient, string value, string compValue);
	void assertThatLog(GameClient* gameClient, char* value, char* compValue);
	void assertThatLog(GameClient* gameClient, char* value, const char* compValue);
	void checkSameUserLog(GameClient* gameClient, User user1, User user2);
	void checkSameChatLog(GameClient* gameClient, Chatting chat1, Chatting chat2);
	void checkSameMapInfoLog(GameClient* gameClient, MapInfo mapInfo1, MapInfo mapInfo2);
	void checkSameInventoryInfoLog(GameClient* gameClient, InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2);

	void checkSameDatabaseChattingListLog(GameClient* gameClient);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameChat(Chatting chat1, Chatting chat2);
};

#endif
