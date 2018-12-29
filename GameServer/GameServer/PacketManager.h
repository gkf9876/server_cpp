#ifndef __PACKET_MANAGER_H__
#define __PACKET_MANAGER_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Winsock2.h>
#elif __linux__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#elif __APPLE__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

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
#define MOVE_INVENTORY_ITEM_FINISH		31
#define OTHER_REQUEST					100
#define REQUEST_ERROR					255
#define TEST                            555

using namespace std;

class PacketManager
{
private:
	char buffer[1024];
	int count;
	time_t currentTime;
	time_t endTime;

#ifdef _WIN32
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
#elif __linux__
	int hSocket;
	struct sockaddr_in servAddr;
#elif __APPLE__
	int hSocket;
	struct sockaddr_in servAddr;
#endif

	bool isGetObjectInfo = false;
	bool isGetMonsterInfo = false;
	bool isGetItemInfo = false;
	bool isGetInventoryInfo = false;
	bool isMapPotalFinish = false;
	bool isThrowItemFinish = false;
	bool isGetItemFinish = false;
	bool isMoveItemFinish = false;
	bool isChattingFinish = false;
	bool isMapMoveFinish = false;
	bool isUpdateUserInfoFinish = false;
	bool isJoinUserFinish = false;
	bool isJoinUserSeccess = false;
public:
	void openClient(const char* addr, int port);
	void closeClient();
	void ErrorHandling(const char* message);

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
	void setIsMoveItemFinish(bool value);
	bool getIsMoveItemFinish();
	void setIsChattingFinish(bool value);
	bool getIsChattingFinish();
	void setIsMapMoveFinish(bool value);
	bool getIsMapMoveFinish();
	void setIsUpdateUserInfoFinish(bool value);
	bool getIsUpdateUserInfoFinish();
	void setIsJoinUserFinish(bool value);
	bool getIsJoinUserFinish();
	void setIsJoinUserSeccess(bool value);
	bool getIsJoinUserSeccess();

	void sendc(const char* data, int size);
	int recvc(char* data, int size);
	void sendRequest(int code, const char* data, int size);
	int recvRequest(int* code, char* data);
};

#endif
