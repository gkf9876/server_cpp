#ifndef __GAME_SERVER_TEST_H__
#define __GAME_SERVER_TEST_H__

#include <iostream>
#include <vector>

#ifdef _WIN32
#include <process.h>
#elif __linux__
#include <pthread.h>
#endif

#include "GameServer.h"
#include "GameClient.h"
#include "factory/ApplicationContext.h"

using namespace std;

class GameServerTest
{
private:
	GameServer* gameServer;
	GameClient* gameClient[10];

	UserDao* userDao;
	MapDao* mapDao;
	MapInfoDao* mapInfoDao;
	MonsterDao* monsterDao;
	ChattingDao* chattingDao;
	InventoryInfoDao* inventoryInfoDao;

	MapManageService* mapManageService;

	User user[10];

	Map* map1;
	Map* map2;
	Map* map3;

	Monster monster1;
	Monster monster2;
	Monster monster3;
	Monster monster4;
	Monster monster5;
	Monster monster6;
	Monster monster7;
	Monster monster8;
	Monster monster9;

	MapInfo mapInfo1;
	MapInfo mapInfo2;
	MapInfo mapInfo3;

	MapInfo objectInfo[20];

	InventoryInfo item[10][8];

#ifdef _WIN32
	HANDLE hServerThread;
	HANDLE hClientThread[10];
	CRITICAL_SECTION cs;
#elif __linux__
	pthread_t hServerThread;
	pthread_t hClientThread[10];
	void* thr_ret;
	pthread_mutex_t mutex;
#endif

public:
	GameServerTest();
	~GameServerTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThatLog(int clientNum, int value, int compValue);
	void assertThatLog(int clientNum, string value, string compValue);
	void assertThatLog(int clientNum, char* value, char* compValue);
	void assertThatLog(int clientNum, char* value, const char* compValue);
	void checkSameUserLog(int clientNum, User user1, User user2);
	void checkSameChatLog(int clientNum, Chatting chat1, Chatting chat2);
	void checkSameMapInfoLog(int clientNum, MapInfo mapInfo1, MapInfo mapInfo2);
	void checkSameInventoryInfo(int clientNum, InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameChat(Chatting chat1, Chatting chat2);

	void run();

	GameServer* getGameServer();
	GameClient* getGameClient(int idx);
	UserDao* getUserDao();
	User getUser(int idx);

#ifdef _WIN32
	static unsigned WINAPI ServerThreadFunc(void* arg);

	static unsigned WINAPI ClientThreadFunc0(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc0(void* arg);
	static unsigned WINAPI ClientThreadFunc1(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc1(void* arg);
	static unsigned WINAPI ClientThreadFunc2(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc2(void* arg);
	static unsigned WINAPI ClientThreadFunc3(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc3(void* arg);
	static unsigned WINAPI ClientThreadFunc4(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc4(void* arg);
	static unsigned WINAPI ClientThreadFunc5(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc5(void* arg);
	static unsigned WINAPI ClientThreadFunc6(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc6(void* arg);
	static unsigned WINAPI ClientThreadFunc7(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc7(void* arg);
	static unsigned WINAPI ClientThreadFunc8(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc8(void* arg);
	static unsigned WINAPI ClientThreadFunc9(void* arg);
	static unsigned WINAPI ClientRecvThreadFunc9(void* arg);
#elif __linux__
	static void* ServerThreadFunc(void* arg);

	static void* ClientThreadFunc0(void* arg);
	static void* ClientRecvThreadFunc0(void* arg);
	static void* ClientThreadFunc1(void* arg);
	static void* ClientRecvThreadFunc1(void* arg);
	static void* ClientThreadFunc2(void* arg);
	static void* ClientRecvThreadFunc2(void* arg);
	static void* ClientThreadFunc3(void* arg);
	static void* ClientRecvThreadFunc3(void* arg);
	static void* ClientThreadFunc4(void* arg);
	static void* ClientRecvThreadFunc4(void* arg);
	static void* ClientThreadFunc5(void* arg);
	static void* ClientRecvThreadFunc5(void* arg);
	static void* ClientThreadFunc6(void* arg);
	static void* ClientRecvThreadFunc6(void* arg);
	static void* ClientThreadFunc7(void* arg);
	static void* ClientRecvThreadFunc7(void* arg);
	static void* ClientThreadFunc8(void* arg);
	static void* ClientRecvThreadFunc8(void* arg);
	static void* ClientThreadFunc9(void* arg);
	static void* ClientRecvThreadFunc9(void* arg);
#endif

	void regenMonster();
};

#endif
