#include "PacketManager.h"

void PacketManager::openClient(const char* addr, int port)
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
	if (hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("connect() error!");
#elif __APPLE__
	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(addr);
	servAddr.sin_port = port;

	if (connect(hSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1)
		ErrorHandling("connect() error!");
#endif
}

void PacketManager::closeClient()
{
#ifdef _WIN32
	closesocket(hSocket);
	WSACleanup();
#elif __linux__
	close(hSocket);
#elif __APPLE__
	close(hSocket);
#endif
}

void PacketManager::ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void PacketManager::setIsGetObjectInfo(bool value)
{
	this->isGetObjectInfo = value;
}

bool PacketManager::getIsGetObjectInfo()
{
	return this->isGetObjectInfo;
}

void PacketManager::setIsGetMonsterInfo(bool value)
{
	this->isGetMonsterInfo = value;
}

bool PacketManager::getIsGetMonsterInfo()
{
	return this->isGetMonsterInfo;
}

void PacketManager::setIsGetItemInfo(bool value)
{
	this->isGetItemInfo = value;
}

bool PacketManager::getIsGetItemInfo()
{
	return this->isGetItemInfo;
}

void PacketManager::setIsGetInventoryInfo(bool value)
{
	this->isGetInventoryInfo = value;
}

bool PacketManager::getIsGetInventoryInfo()
{
	return this->isGetInventoryInfo;
}

void PacketManager::setIsMapPotalFinish(bool value)
{
	this->isMapPotalFinish = value;
}

bool PacketManager::getIsMapPotalFinish()
{
	return this->isMapPotalFinish;
}

void PacketManager::setIsThrowItemFinish(bool value)
{
	this->isThrowItemFinish = value;
}

bool PacketManager::getIsThrowItemFinish()
{
	return this->isThrowItemFinish;
}

void PacketManager::setIsGetItemFinish(bool value)
{
	this->isGetItemFinish = value;
}

bool PacketManager::getIsGetItemFinish()
{
	return this->isGetItemFinish;
}

void PacketManager::setIsMoveItemFinish(bool value)
{
	this->isMoveItemFinish = value;
}

bool PacketManager::getIsMoveItemFinish()
{
	return this->isMoveItemFinish;
}

void PacketManager::setIsChattingFinish(bool value)
{
	this->isChattingFinish = value;
}

bool PacketManager::getIsChattingFinish()
{
	return this->isChattingFinish;
}

void PacketManager::setIsMapMoveFinish(bool value)
{
	this->isMapMoveFinish = value;
}

bool PacketManager::getIsMapMoveFinish()
{
	return this->isMapMoveFinish;
}

void PacketManager::setIsUpdateUserInfoFinish(bool value)
{
	this->isUpdateUserInfoFinish = value;
}

bool PacketManager::getIsUpdateUserInfoFinish()
{
	return this->isUpdateUserInfoFinish;
}

void PacketManager::setIsJoinUserFinish(bool value)
{
	this->isJoinUserFinish = value;
}

bool PacketManager::getIsJoinUserFinish()
{
	return this->isJoinUserFinish;
}

void PacketManager::setIsJoinUserSeccess(bool value)
{
	this->isJoinUserSeccess = value;
}

bool PacketManager::getIsJoinUserSeccess()
{
	return this->isJoinUserSeccess;
}

void PacketManager::sendc(const char* data, int size)
{
#ifdef _WIN32
	send(hSocket, data, size, 0);
#elif __linux__
	write(hSocket, data, size);
#elif __APPLE__
	write(hSocket, data, size);
#endif
}

int PacketManager::recvc(char* data, int size)
{
#ifdef _WIN32
	return recv(hSocket, data, size, 0);
#elif __linux__
	return read(hSocket, data, size);
#elif __APPLE__
	return read(hSocket, data, size);
#endif
}

void PacketManager::sendRequest(int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	sendc(buffer, size + 8);
	free(buffer);
}

int PacketManager::recvRequest(int* code, char* data)
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