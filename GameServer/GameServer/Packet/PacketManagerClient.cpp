#include "PacketManagerClient.h"

void PacketManagerClient::openClient(const char* addr, int port)
{
#if defined(_WIN32)
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
#elif defined(__linux__) || defined(__APPLE__)
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

void PacketManagerClient::closeClient()
{
#if defined(_WIN32)
	closesocket(hSocket);
	WSACleanup();
#elif defined(__linux__) || defined(__APPLE__)
	close(hSocket);
#endif
}

void PacketManagerClient::sendRequestMessage(int code, void* data, int size){
	char message[BUF_SIZE];
	memcpy(message, data, size);
	sendRequest(hSocket, code, message, size);

	User sendUserInfo;

	switch (code)
	{
	case REQUEST_JOIN:
		while (getIsJoinUserFinish() != true);
		setIsJoinUserFinish(false);
		break;
	case UPDATE_USER_INFO:
		while (getIsUpdateUserInfoFinish() != true);
		setIsUpdateUserInfoFinish(false);
		break;
	case MOVE_INVENTORY_ITEM:
		while (getIsMoveItemFinish() != true);
		setIsMoveItemFinish(false);
		break;
	case REQUEST_EAT_ITEM:
		while (getIsGetItemFinish() != true);
		setIsGetItemFinish(false);
		break;
	case REQUEST_THROW_ITEM:
		while (getIsThrowItemFinish() != true);
		setIsThrowItemFinish(false);
		break;
	case CHATTING_PROCESS:
		while (getIsChattingFinish() != true);
		setIsChattingFinish(false);
		break;
	case REQUEST_USER_INFO:
		while (getIsGetUserInfo() != true);
		setIsGetUserInfo(false);
		break;
	case REQUEST_LOGIN:
		while (getIsRequestLoginFinish() != true);
		setIsRequestLoginFinish(false);
		break;
	case REQUEST_LOGOUT:
		break;
	case USER_MOVE_UPDATE:
		memcpy(&sendUserInfo, data, sizeof(User));
		if (sendUserInfo.getAction() != ACTION_MAP_POTAL)
		{
			while (getIsMapMoveFinish() != true);
			setIsMapMoveFinish(false);
		}
		else
		{
			//다른 맵 이동이 마칠때까지
			while (getIsMapPotalFinish() != true);
			setIsMapPotalFinish(false);
		}
		break;
	default:
		break;
	}
}

void PacketManagerClient::recvRequest(int* code, char * message)
{
	PacketManager::recvRequest(hSocket, code, message);
}
