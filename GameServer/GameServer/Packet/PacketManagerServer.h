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
	int fdNum, strLen;
	char buf[BUF_SIZE];
	TIMEVAL timeout;
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

	int readyRecv();

	void registClientSocket();
#ifdef _WIN32
	int recvDataAnalysis(int i, SOCKET* outputSock, int* outputCode, char* outputBuffer, int* outputSize);
	int fdIsset(SOCKET socket, fd_set FAR * fdSet, int i);
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

#ifdef _WIN32
	void open();
	int server_select();
	void connection_request();
	SOCKET read_message(int i, SOCKET* outputSock, int* outputCode, char* outputBuffer, int* outputSize);
#endif
	int getClientCount();
#ifdef _WIN32
	SOCKET getServSock();
	SOCKET reads_socket(int i);
	int fd_isset(int i);
	void close();
#endif
};

#endif
