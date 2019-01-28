#include "PacketManagerServer.h"

void PacketManagerServer::openServer(int port)
{
#if defined(_WIN32)
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(port);

	if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	FD_ZERO(&reads);
	FD_SET(hServSock, &reads);
#elif defined(__linux__) || defined(__APPLE__)
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(port);

	if (bind(hServSock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("bind() error");
	if (listen(hServSock, 5) == -1)
		ErrorHandling("listen() error");

	epfd = epoll_create(EPOLL_SIZE);
	ep_events = (struct epoll_event*)malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

	event.events = EPOLLIN;
	event.data.fd = hServSock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, hServSock, &event);

	clientCount = 0;
#endif
}

void PacketManagerServer::closeServer()
{
#if defined(_WIN32)
	closesocket(hServSock);
	WSACleanup();
#elif defined(__linux__) || defined(__APPLE__)
	close(hServSock);
	close(epfd);
#endif
}

int PacketManagerServer::getClientCount()
{
#ifdef _WIN32
	return reads.fd_count;
#elif __linux__
	return clientCount;
#endif
}

int PacketManagerServer::readyRecv()
{
#ifdef _WIN32
	cpyReads = reads;
	TIMEVAL timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;

	if ((fdNum = select(0, &cpyReads, 0, 0, &timeout)) == SOCKET_ERROR)
		return -1;
	else
		return 1;
#elif __linux__
	event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, 10);
	if (event_cnt == -1)
	{
		puts("epoll_wait() error");
		return -1;
	}
	else
		return 1;
#endif
}

void PacketManagerServer::registClientSocket()
{
#ifdef _WIN32
	adrSz = sizeof(clntAddr);
	hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &adrSz);
	FD_SET(hClntSock, &reads);
#elif __linux__
	adr_sz = sizeof(clntAddr);
	hClntSock = accept(hServSock, (struct sockaddr*)&clntAddr, &adr_sz);
	event.events = EPOLLIN;
	event.data.fd = hClntSock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, hClntSock, &event);
	clientCount++;
#endif
}

#ifdef _WIN32
int PacketManagerServer::recvDataAnalysis(int i, SOCKET* outputSock, int* outputCode, char* outputBuffer, int* outputSize)
{
	int code;
	int size;
	int strLen;
	char buffer[BUF_SIZE];

	strLen = recvRequest(reads.fd_array[i], &code, buffer);
	size = strLen - 8;
	if (strLen == 0)
	{
		closeClient(cpyReads.fd_array[i]);
		return cpyReads.fd_array[i];
	}
	else
	{
		if (code != REQUEST_LOGOUT)
		{
			*outputSock = reads.fd_array[i];
			*outputCode = code;
			memcpy(outputBuffer, buffer, BUF_SIZE);
			*outputSize = size;
		}
		else
		{
			*outputSock = cpyReads.fd_array[i];
			*outputCode = code;
			memcpy(outputBuffer, buffer, BUF_SIZE);
			*outputSize = size;
		}
		return -1;
	}
}
#elif __linux__
int PacketManagerServer::recvDataAnalysis(int i, int* outputSock, int* outputCode, char* outputBuffer, int* outputSize)
{
	int code;
	int size;
	int strLen;
	char buffer[BUF_SIZE];

	strLen = recvRequest(ep_events[i].data.fd, &code, buffer);
	size = strLen - 8;
	if (strLen == 0)
	{
		closeClient(ep_events[i].data.fd);
		return ep_events[i].data.fd;
	}
	else
	{
		*outputSock = ep_events[i].data.fd;
		*outputCode = code;
		memcpy(outputBuffer, buffer, BUF_SIZE);
		*outputSize = size;
		return -1;
	}
}
#endif

int PacketManagerServer::recvSocketNum(int i)
{
#ifdef _WIN32
	if (FD_ISSET(reads.fd_array[i], &cpyReads))
	{
		if (reads.fd_array[i] == hServSock)
			return 0;
		else
			return 1;
	}
#elif __linux__
	if (ep_events[i].data.fd == hServSock)
		return 0;
	else
		return 1;
#endif
	return -1;
}

int PacketManagerServer::recvSocketCount()
{
#ifdef _WIN32
	return reads.fd_count;
#elif __linux__
	return event_cnt;
#endif
}

#ifdef _WIN32
void PacketManagerServer::closeClient(SOCKET sock)
{
	//FD_CLR(sock);
	closesocket(sock);
}
#elif __linux__
void PacketManagerServer::closeClient(int sock)
{
	clientCount--;

	epoll_ctl(epfd, EPOLL_CTL_DEL, sock, NULL);
	close(sock);
}
#endif