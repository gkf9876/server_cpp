#ifndef __GAME_SERVER_H__
#define __GAME_SERVER_H__

#include <iostream>
#include <stdlib.h>

#ifdef _WIN32
#include <Winsock2.h>
#elif __linux__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#endif

#include <list>
#include "datasource/DataSource.h"
#include "service/UserService.h"
#include "service/ChattingService.h"
#include "service/MapManageService.h"

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
#define OTHER_REQUEST					100
#define REQUEST_ERROR					255
#define CUR_PATH						"/home/gkf9876/server/Resources/"
//#define CUR_PATH						"/home/pi/server/Resources/"

using namespace std;

class GameServer
{
private:
#ifdef _WIN32
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;
	TIMEVAL timeout;
	fd_set reads, cpyReads;
	int adrSz;
	int fdNum;
	int strLen;
	char buffer[BUF_SIZE];
#elif __linux__
	int hServSock, hClntSock;
	struct sockaddr_in servAddr, clntAddr;
	socklen_t adr_sz;
	int strLen;
	char buffer[BUF_SIZE];

	struct epoll_event* ep_events;
	struct epoll_event event;
	int epfd, event_cnt;
	int clientCount;
#endif
	DataSource* dataSource;
	UserService* userService;
	ChattingService* chattingService;
	MapManageService* mapManageService;
public:
	GameServer(DataSource* dataSource);
	~GameServer();

	void ErrorHandling(const char* message);

	void openServer(int port);
	void closeServer();

#ifdef _WIN32
	void accept_win();

	void sends(SOCKET sock, const char* data, int size);
	int recvs(SOCKET sock, char* data, int size);

	void sendRequest(SOCKET sock, int code, const char* data, int size);
	int recvRequest(SOCKET sock, int* code, char* data);
	int getClientCount();

	void getUserInfo(SOCKET sock, const char* name);
	void updateLogin(SOCKET sock, const char* name);
	void updateLogout(SOCKET sock);

	void chatting(SOCKET sock, const char* chatting);
	void updateMoveInfo(SOCKET sock, const char* userInfo);

	void createThrowItemOnMap(SOCKET sock, const char* mapInfo);
	void userGetMapItem(SOCKET sock, const char* userInfo);

#elif __linux__
	void accept_linux();

	void sends(int sock, const char* data, int size);
	int recvs(int sock, char* data, int size);

	void sendRequest(int sock, int code, const char* data, int size);
	int recvRequest(int sock, int* code, char* data);
	int getClientCount();

	void getUserInfo(int sock, const char* name);
	void updateLogin(int sock, const char* name);
	void updateLogout(int sock);

	void chatting(int sock, const char* chatting);
	void updateMoveInfo(int sock, const char* userInfo);

	void createThrowItemOnMap(int sock, const char* mapInfo);
	void userGetMapItem(int sock, const char* userInfo);

#endif

	void regenMonster();
};

#endif
