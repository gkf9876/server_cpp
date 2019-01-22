#ifndef __UTIL_H__
#define __UTIL_H__

#include <iostream>
#include <time.h>
#include <vector>
#include "../domain/Chatting.h"

#ifdef _WIN32
#include <WinSock2.h>
#include <process.h>
#elif __linux__
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netdb.h>
#endif

class Util
{
public:
	struct tm MySQL_DateToTime(const char* date);
	vector<Chatting> latest5secondChatting(vector<Chatting> chatting);
	void MyPrintDebug(const char* message);
};

#endif
