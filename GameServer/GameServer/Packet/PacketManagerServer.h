#ifndef __PACKET_MANAGER_SERVER_H__
#define __PACKET_MANAGER_SERVER_H__

#include <iostream>
#include <stdio.h>

#if defined(_WIN32)
#include <Winsock2.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#endif

#include "PacketManager.h"

using namespace std;

class PacketManagerServer : public PacketManager
{
private:
#if defined(_WIN32)
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;
	fd_set reads, cpyReads;
	int adrSz;
	int fdNum;
#elif defined(__linux__) || defined(__APPLE__)
	int hServSock, hClntSock;
	struct sockaddr_in servAddr, clntAddr;
	socklen_t adr_sz;

	struct epoll_event* ep_events;
	struct epoll_event event;
	int epfd, event_cnt;
	int clientCount;
#endif
public:
	void openServer(int port);
	void closeServer();
	int getClientCount();

	int readyRecv();
	void registClientSocket();
#ifdef _WIN32
	int recvDataAnalysis(int i, SOCKET* outputSock, int* outputCode, char* outputBuffer, int* outputSize);
#elif __linux__
	int recvDataAnalysis(int i, int* outputSock, int* outputCode, char* outputBuffer, int* outputSize);
#endif
	int recvSocketNum(int i);
	int recvSocketCount();

#ifdef _WIN32
	void closeClient(SOCKET sock);
#elif __linux__
	void closeClient(int sock);
#endif
};

#endif
