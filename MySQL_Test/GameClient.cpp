#include "GameClient.h"

GameClient::GameClient()
{

}

GameClient::~GameClient()
{

}

void GameClient::ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void GameClient::openClient(const char* addr, int port)
{
#ifdef _WIN32
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ErrorHandling("connect() error!");
#elif __linux__
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if(connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("connect() error!");
#endif
}

void GameClient::closeClient()
{
#ifdef _WIN32
	closesocket(hSocket);
	WSACleanup();
#elif __linux__
	close(hSocket);
#endif
}

void GameClient::sendc(const char* data, int size)
{
#ifdef _WIN32
	send(hSocket, data, size, 0);
#elif __linux__
	write(hSocket, data, size);
#endif
}

int GameClient::recvc(char* data, int size)
{
#ifdef _WIN32
	return recv(hSocket, data, size, 0);
#elif __linux__
	return read(hSocket, data, size);
#endif
}

void GameClient::sendRequest(int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	sendc(buffer, size + 8);
	free(buffer);
}

int GameClient::recvRequest(int* code, char* data)
{
	int size;
	int readLen;
	char buffer[BUF_SIZE];

	readLen = recvc(buffer, 4);
	memcpy(&size, buffer, sizeof(int));

	readLen += recvc(buffer, 4);
	memcpy(code, buffer, sizeof(int));

	readLen += recvc(data, size);

	return readLen;
}
