#ifndef __GAME_CLIENT_H__
#define __GAME_CLIENT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "domain/User.h"
#include "domain/InventoryInfo.h"
#include "domain/Monster.h"
#include "domain/MapInfo.h"
#include "domain/Chatting.h"
#include "domain/ServerInfo.h"
#include "domain/EventInfo.h"

#include "Packet/PacketManagerClient.h"
#include "event/EventProcedure.h"

#define INVENTORY_X_SIZE 3
#define INVENTORY_Y_SIZE 5

class GameClient
{
private:
	User mainUser;
	Chatting mainChatting;
	vector<User*> * usersInfo = NULL;								//현재 맵의 다른 유저들
	vector<MapInfo*> * objectInfo = NULL;							//현재 맵의 오브젝트
	vector<MapInfo*> * monsterInfo = NULL;							//현재 맵의 몬스터
	vector<MapInfo*> * itemInfo = NULL;
	vector<Chatting*> * chattingInfo = NULL;						//현재 맵의 채팅
	InventoryInfo * inventory_items_Info[3][5];						//아이템창에 있는 아이템 목록
	ServerInfo serverInfo;

	bool isLogin = false;
	bool popupLoginFail = false;


	vector<string> * log = NULL;

	EventProcedure * eventProcedure;

	bool logout = false;
public:
	PacketManagerClient * packetManagerClient;

	GameClient();
	~GameClient();
	void recvRun();

	void setMainUser(User user);
	User getMainUser();
	void setMainUserAction(int value);
	int getMainUserAction();

	void setMainChatting(Chatting chatting);
	Chatting getMainChatting();

    void setEventProcedure(EventProcedure * eventProcedure);
    
	EventProcedure * getEventProcedure();
	void addEventInfo(EventInfo eventInfo);

	void addUsersInfo(User* user);
	void removeUsersInfo(const char* userName);
	int sizeUserInfo();
	User getUsersInfo(int idx);
	void moveOtherUser(const char* userName, int xpos, int ypos, int seeDirection);
	User getUsersInfo(const char* name);
	void clearUsersInfo();
	void updateUserInfo(User user);

	void addObjectInfo(MapInfo* object);
	int sizeObjectInfo();
	MapInfo getObjectInfo(int idx);
	void clearObjectInfo();

	void addMonsterInfo(MapInfo* monster);
	int sizeMonsterInfo();
	MapInfo getMonsterInfo(int idx);
	void clearMonsterInfo();
	void moveMonsterInfo(int idx, int xpos, int ypos, int seeDirection, int action);

	void addItemInfo(MapInfo* itemInfo);
	int sizeItemInfo();
	MapInfo getItemInfo(int idx);
	void clearItemInfo();
	void removeItemInfo(int idx);

	void addChattingInfo(Chatting* chatting);
	int sizeChattingInfo();
	Chatting getChattingInfo(int idx);
	vector<Chatting> getChattingInfo();

	void addInventoryInfo(InventoryInfo* inventoryInfo);
	int sizeInventoryInfo();
	InventoryInfo* getInventoryInfo(int xpos, int ypos);
	void getItem(MapInfo mapInfo);
	void removeInventoryInfo(int xpos, int ypos);
	void moveInventoryInfo(int xpos, int ypos, int to_xpos, int to_ypos);

	void setServerInfo(ServerInfo serverInfo);
	ServerInfo getServerInfo();

	void setIsLogin(bool value);
	bool getIsLogin();
	void setPopupLoginFail(bool value);
	bool getPopupLoginFail();

	void setLogout(bool value);
	bool getLogout();

	void addLog(string message);
	void printAllLog();

	void openClient(const char* addr, int port);
	void closeClient();

	void requestLogin(const char * userName);
	void getUserInfo(const char* userName);

	void requestLogout();

	void chatting(const char* chattingInfo);
	void requestMapMove(int xpos, int ypos, const char* field, int seeDirection);

	void requestThrowItem(int xpos, int ypos);
	void requestGetItem();
	void requestMoveItem(int xpos, int ypos, int to_xpos, int to_ypos);

	void requestUpdateUserInfo();
	void requestJoinUser(User userInfo);

	bool getIsGetItemInfo();
	bool getIsJoinUserSeccess();

	void setRunEventInfo(EventInfo eventInfo);
};

#endif
