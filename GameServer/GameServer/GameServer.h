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
#include "service/ServerInfoService.h"
#include "service/EventInfoService.h"

#include "Packet/PacketManagerServer.h"

#define INVENTORY_X_SIZE 3
#define INVENTORY_Y_SIZE 5

using namespace std;

class GameServer
{
private:
	PacketManagerServer* packetManagerServer;

	UserService* userService;
	ChattingService* chattingService;
	MapManageService* mapManageService;
	ServerInfoService* serverInfoService;
	EventInfoService* eventInfoService;
public:
	GameServer();
	~GameServer();
	void setUserService(UserService* userService);
	void setChattingService(ChattingService* chattingService);
	void setMapManageService(MapManageService* mapManageService);
	void setServerInfoService(ServerInfoService* serverInfoService);
	void setEventInfoService(EventInfoService* eventInfoService);

	int getClientCount();

	void openServer(int port);
	void closeServer();

	void accept_win();

#ifdef _WIN32
	void run(SOCKET sock, int code, const char* buffer, int size);

	void getUserInfo(SOCKET sock, const char* name);
	void updateLogin(SOCKET sock, const char* name);
	void updateLogout(SOCKET sock);

	void chatting(SOCKET sock, const char* chatting);
	void updateMoveInfo(SOCKET sock, const char* userInfo);

	void createThrowItemOnMap(SOCKET sock, const char* mapInfo);
	void userGetMapItem(SOCKET sock, const char* userInfo);
	void moveInventoryInfo(SOCKET sock, const char* inventoryInfo);

	void updateUserInfo(SOCKET sock, const char* userInfo);
	void insertUserInfo(SOCKET sock, const char* userInfo);

	void connectionConfirm(int idx);

	void processingRunEvent(SOCKET sock, const char* eventInfo);

	void closeClient(SOCKET sock);

#elif __linux__
	void run(int sock, int code, const char* buffer, int size);

	void getUserInfo(int sock, const char* name);
	void updateLogin(int sock, const char* name);
	void updateLogout(int sock);

	void chatting(int sock, const char* chatting);
	void updateMoveInfo(int sock, const char* userInfo);

	void createThrowItemOnMap(int sock, const char* mapInfo);
	void userGetMapItem(int sock, const char* userInfo);
	void moveInventoryInfo(int sock, const char* inventoryInfo);

	void updateUserInfo(int sock, const char* userInfo);
	void insertUserInfo(int sock, const char* userInfo);

	void connectionConfirm(int idx);

	void processingRunEvent(int sock, const char* eventInfo);

	void closeClient(int sock);

#endif

	void regenMonster();
};

#endif
