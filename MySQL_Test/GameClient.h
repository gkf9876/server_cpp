#ifndef __GAME_CLIENT_H__
#define __GAME_CLIENT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#ifdef _WIN32
#include <Winsock2.h>
#elif __linux__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif
#include "domain/User.h"
#include "domain/InventoryInfo.h"
#include "domain/Monster.h"
#include "domain/MapInfo.h"
#include "domain/Chatting.h"

#define BUF_SIZE 1024
#define EPOLL_SIZE 50
#define INVENTORY_X_SIZE 3
#define INVENTORY_Y_SIZE 5

#define REQUEST_USER_INFO				1
#define REQUEST_LOGIN					2
#define CHATTING_PROCESS				3
#define USER_MOVE_UPDATE				4
#define OTHER_USER_MAP_MOVE				5
#define REQUEST_JOIN					6
#define UPDATE_LOGIN_TIME				7
#define REQUEST_TILED_MAP				8
#define REQUEST_IMAGE					9
#define DELETE_FIELD_ITEM				10
#define REQUEST_FIELD_OBJECT_INFO		11
#define REQUEST_FIELD_MONSTER_INFO		12
#define REQUEST_INVENTORY_ITEM_INFO		13
#define REQUEST_FIELD_ITEM_INFO			14
#define MOVE_INVENTORY_ITEM				15
#define REQUEST_THROW_ITEM				16
#define REQUEST_EAT_ITEM				17
#define REGEN_MONSTER					18
#define ATTACK_FILED_OBJECT				19
#define REQUEST_LOGOUT					20
#define REQUEST_MAP_MOVE				21
#define REQUEST_MAP_POTAL_FINISH		22
#define REQUEST_THROW_ITEM_FINISH		23
#define REQUEST_GET_ITEM_FINISH			24
#define REQUEST_CHATTING_FINISH			25
#define REQUEST_MAP_MOVE_FINISH			26
#define UPDATE_USER_INFO				27
#define UPDATE_USER_INFO_FINISH			28
#define REQUEST_JOIN_FINISH				29
#define OTHER_USER_CHATTING_PROCESS		30
#define OTHER_REQUEST					100
#define REQUEST_ERROR					255

class GameClient
{
private:
#ifdef _WIN32
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
#elif __linux__
	int hSocket;
	struct sockaddr_in servAddr;
#endif
	User mainUser;
	Chatting mainChatting;
	vector<User*> * usersInfo = NULL;								//현재 맵의 다른 유저들
	vector<MapInfo*> * objectInfo = NULL;							//현재 맵의 오브젝트
	vector<MapInfo*> * monsterInfo = NULL;							//현재 맵의 몬스터
	vector<MapInfo*> * itemInfo = NULL;
	vector<Chatting*> * chattingInfo = NULL;						//현재 맵의 채팅
	InventoryInfo * inventory_items_Info[3][5];						//아이템창에 있는 아이템 목록

	bool isLogin = false;
	bool isGetUserInfo = false;
	bool popupLoginFail = false;

	bool isRequestLoginFinish = false;

	bool isGetObjectInfo = false;
	bool isGetMonsterInfo = false;
	bool isGetItemInfo = false;
	bool isGetInventoryInfo = false;
	bool isMapPotalFinish = false;
	bool isThrowItemFinish = false;
	bool isGetItemFinish = false;
	bool isChattingFinish = false;
	bool isMapMoveFinish = false;
	bool isUpdateUserInfoFinish = false;
	bool isjoinUserFinish = false;
	bool isJoinUserSeccess = false;

	vector<string> * log = NULL;

	bool logout = false;
public:
	GameClient();
	~GameClient();
	void recvRun();

	void setMainUser(User user);
	User getMainUser();
	void setMainUserAction(int value);
	int getMainUserAction();

	void setMainChatting(Chatting chatting);
	Chatting getMainChatting();

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

	void setIsLogin(bool value);
	bool getIsLogin();
	void setIsGetUserInfo(bool value);
	bool getIsGetUserInfo();
	void setPopupLoginFail(bool value);
	bool getPopupLoginFail();

	void setIsRequestLoginFinish(bool value);
	bool getIsRequestLoginFinish();

	void setIsGetObjectInfo(bool value);
	bool getIsGetObjectInfo();
	void setIsGetMonsterInfo(bool value);
	bool getIsGetMonsterInfo();
	void setIsGetItemInfo(bool value);
	bool getIsGetItemInfo();
	void setIsGetInventoryInfo(bool value);
	bool getIsGetInventoryInfo();
	void setIsMapPotalFinish(bool value);
	bool getIsMapPotalFinish();
	void setIsThrowItemFinish(bool value);
	bool getIsThrowItemFinish();
	void setIsGetItemFinish(bool value);
	bool getIsGetItemFinish();
	void setIsChattingFinish(bool value);
	bool getIsChattingFinish();
	void setIsMapMoveFinish(bool value);
	bool getIsMapMoveFinish();
	void setIsUpdateUserInfoFinish(bool value);
	bool getIsUpdateUserInfoFinish();
	void setIsJoinUserSeccess(bool value);
	bool getIsJoinUserSeccess();

	void setLogout(bool value);
	bool getLogout();

	void addLog(string message);
	void printAllLog();

	void ErrorHandling(const char* message);

	void openClient(const char* addr, int port);
	void closeClient();

	void sendc(const char* data, int size);
	int recvc(char* data, int size);

	void sendRequest(int code, const char* data, int size);
	int recvRequest(int* code, char* data);

	void requestLogin(const char * userName);
	void getUserInfo(const char* userName);

	void requestLogout();

	void chatting(const char* chattingInfo);
	void requestMapMove(int xpos, int ypos, const char* field, int seeDirection);

	void requestThrowItem(int xpos, int ypos);
	void requestGetItem();

	void requestUpdateUserInfo();
	void requestJoinUser(User userInfo);
};

#endif
