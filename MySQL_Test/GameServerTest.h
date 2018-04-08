#ifndef __GAME_SERVER_TEST_H__
#define __GAME_SERVER_TEST_H__

#include <iostream>

#ifdef _WIN32
#include <process.h>
#elif __linux__
#include <pthread.h>
#endif

#include "GameServer.h"
#include "GameClient.h"
#include "domain/User.h"

using namespace std;

class GameServerTest
{
private:
	GameServer* gameServer;
	GameClient* gameClient[10];

	DataSource* dataSource;
	UserDao* userDao;

	User user[10];

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
	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void assertThat(char* value, char* compValue);
	void checkSameUser(User user1, User user2);

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

};

#endif
