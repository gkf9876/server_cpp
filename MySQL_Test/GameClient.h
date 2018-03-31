#ifndef __GAME_CLIENT_H__
#define __GAME_CLIENT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Winsock2.h>
#elif __linux__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif
#include "domain/User.h"

#define BUF_SIZE 1024
#define EPOLL_SIZE 50

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
#define REQUEST_FIELD_ITEM_INFO			11
#define REQUEST_FIELD_MONSTER_INFO		12
#define REQUEST_INVENTORY_ITEM_INFO		13
#define MOVE_INVENTORY_ITEM				14
#define THROW_ITEM						15
#define REGEN_MONSTER					16
#define ATTACK_FILED_OBJECT				17

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
public:
	GameClient();
	~GameClient();

	void ErrorHandling(const char* message);

	void openClient(const char* addr, int port);
	void closeClient();

	void sendc(const char* data, int size);
	int recvc(char* data, int size);

	void sendRequest(int code, const char* data, int size);
	int recvRequest(int* code, char* data);
};

#endif
