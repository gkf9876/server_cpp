#ifndef __PACKET_MANAGER_CLIENT_H__
#define __PACKET_MANAGER_CLIENT_H__

#include "PacketManager.h"
#include "../domain/User.h"
#include <iostream>

#if defined(_WIN32)
#include <Winsock2.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

using namespace std;

class PacketManagerClient : public PacketManager
{
private:
#if defined(_WIN32)
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
#elif defined(__linux__) || defined(__APPLE__)
	int hSocket;
	struct sockaddr_in servAddr;
#endif
public:
	void openClient(const char* addr, int port);
	void closeClient();

	void sendRequestMessage(int code, void* data, int size);
	void recvRequest(int* code, char* message);
};

#endif
