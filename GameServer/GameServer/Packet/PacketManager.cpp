#include "PacketManager.h"


void PacketManager::ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}


void PacketManager::setIsGetUserInfo(bool value)
{
	this->isGetUserInfo = value;
}

bool PacketManager::getIsGetUserInfo()
{
	return this->isGetUserInfo;
}

void PacketManager::setIsRequestLoginFinish(bool value)
{
	this->isRequestLoginFinish = value;
}

bool PacketManager::getIsRequestLoginFinish()
{
	return this->isRequestLoginFinish;
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

void PacketManager::setIsRunEventInfoFinish(bool value)
{
	this->isRunEventInfoFinish = value;
}

bool PacketManager::getIsRunEventInfoFinish()
{
	return this->isRunEventInfoFinish;
}

#if defined(_WIN32)
void PacketManager::sendc(SOCKET sock, const char* data, int size)
{
	send(sock, data, size, 0);
}
#elif defined(__linux__) || defined(__APPLE__)
void PacketManager::sendc(int sock, const char * data, int size)
{
	write(sock, data, size);
}
#endif

#if defined(_WIN32)
int PacketManager::recvc(SOCKET sock, char* data, int size)
{
	return recv(sock, data, size, 0);
}
#elif defined(__linux__) || defined(__APPLE__)
int PacketManager::recvc(int sock, char* data, int size)
{
	return read(sock, data, size);
}
#endif

#if defined(_WIN32)
void PacketManager::sendRequest(SOCKET sock, int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	sendc(sock, buffer, size + 8);
	free(buffer);
	Sleep(10);
}
#elif defined(__linux__) || defined(__APPLE__)
void PacketManager::sendRequest(int sock, int code, const char* data, int size)
{
	int writeLen;
	char* buffer = new char[size + 8];

	memcpy(&buffer[0], &size, sizeof(int));
	memcpy(&buffer[4], &code, sizeof(int));
	memcpy(&buffer[8], data, size);

	sendc(sock, buffer, size + 8);
	free(buffer);
}
#endif

#if defined(_WIN32)
int PacketManager::recvRequest(SOCKET sock, int* code, char* data)
{
	int size;
	int readLen1, readLen2, readLen3;
	char buffer[BUF_SIZE];

	if ((readLen1 = recvc(sock, buffer, 4)) <= 0)
		return -1;
	memcpy(&size, buffer, sizeof(int));

	if ((readLen2 = recvc(sock, buffer, 4)) <= 0)
		return -1;
	memcpy(code, buffer, sizeof(int));

	if ((readLen3 = recvc(sock, data, size)) == size)
		return (readLen1 + readLen2 + readLen3);
	else
		return -1;
}
#elif defined(__linux__) || defined(__APPLE__)
int PacketManager::recvRequest(int sock, int* code, char* data)
{
	int size;
	int readLen1, readLen2, readLen3;
	char buffer[BUF_SIZE];

	if ((readLen1 = recvc(sock, buffer, 4)) == 0)
		return 0;
	memcpy(&size, buffer, sizeof(int));

	if ((readLen2 = recvc(sock, buffer, 4)) == 0)
		return 0;
	memcpy(code, buffer, sizeof(int));

	if ((readLen3 = recvc(sock, data, size)) == size)
		return (readLen1 + readLen2 + readLen3);
	else
		return 0;
}
#endif