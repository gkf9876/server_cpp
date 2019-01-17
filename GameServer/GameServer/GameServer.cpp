#include "GameServer.h"

GameServer::GameServer()
{
	packetManagerServer = new PacketManagerServer();
}

GameServer::~GameServer()
{
	delete packetManagerServer;
}

void GameServer::setUserService(UserService* userService)
{
	this->userService = userService;
}

void GameServer::setChattingService(ChattingService* chattingService)
{
	this->chattingService = chattingService;
}

void GameServer::setMapManageService(MapManageService* mapManageService)
{
	this->mapManageService = mapManageService;
}

void GameServer::setServerInfoService(ServerInfoService * serverInfoService)
{
	this->serverInfoService = serverInfoService;
}


int GameServer::getClientCount()
{
	return packetManagerServer->getClientCount();
}

void GameServer::openServer(int port)
{
	packetManagerServer->openServer(port);
}

void GameServer::closeServer()
{
	packetManagerServer->closeServer();
}

#ifdef _WIN32

void GameServer::run(SOCKET sock, int code, const char* buffer, int size)
{
	try
	{
		switch (code)
		{
		case REQUEST_USER_INFO:
			getUserInfo(sock, buffer);
			break;
		case CHATTING_PROCESS:
			chatting(sock, buffer);
			break;
		case REQUEST_LOGIN:
			updateLogin(sock, buffer);
			break;
		case USER_MOVE_UPDATE:
			updateMoveInfo(sock, buffer);
			break;
		case OTHER_USER_MAP_MOVE:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_JOIN:
			insertUserInfo(sock, buffer);
			break;
		case UPDATE_LOGIN_TIME:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_TILED_MAP:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_IMAGE:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case DELETE_FIELD_ITEM:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case MOVE_INVENTORY_ITEM:
			moveInventoryInfo(sock, buffer);
			break;
		case REQUEST_THROW_ITEM:
			createThrowItemOnMap(sock, buffer);
			break;
		case REQUEST_EAT_ITEM:
			userGetMapItem(sock, buffer);
			break;
		case ATTACK_FILED_OBJECT:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_LOGOUT:
			closeClient(sock);
			break;
		case UPDATE_USER_INFO:
			updateUserInfo(sock, buffer);
			break;
		default:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#elif __linux__

void GameServer::run(int sock, int code, const char* buffer, int size)
{
	try
	{
		switch (code)
		{
		case REQUEST_USER_INFO:
			getUserInfo(sock, buffer);
			break;
		case CHATTING_PROCESS:
			chatting(sock, buffer);
			break;
		case REQUEST_LOGIN:
			updateLogin(sock, buffer);
			break;
		case USER_MOVE_UPDATE:
			updateMoveInfo(sock, buffer);
			break;
		case OTHER_USER_MAP_MOVE:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_JOIN:
			insertUserInfo(sock, buffer);
			break;
		case UPDATE_LOGIN_TIME:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_TILED_MAP:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_IMAGE:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case DELETE_FIELD_ITEM:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_FIELD_OBJECT_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_FIELD_MONSTER_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_INVENTORY_ITEM_INFO:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case MOVE_INVENTORY_ITEM:
			moveInventoryInfo(sock, buffer);
			break;
		case REQUEST_THROW_ITEM:
			createThrowItemOnMap(sock, buffer);
			break;
		case REQUEST_EAT_ITEM:
			userGetMapItem(sock, buffer);
			break;
		case ATTACK_FILED_OBJECT:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		case REQUEST_LOGOUT:
			closeClient(sock);
			break;
		case UPDATE_USER_INFO:
			updateUserInfo(sock, buffer);
			break;
		default:
			packetManagerServer->sendRequest(sock, code, buffer, size);
			break;
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#endif

void GameServer::accept_win()
{
	int code;
	int size;
#ifdef _WIN32
	SOCKET outputSock;
#elif __linux__
	int outputSock;
#endif
	int outputCode;
	char outputBuffer[BUF_SIZE];
	int outputSize;

	if (packetManagerServer->readyRecv() == -1)
		return;

	for (int i = 0; i < packetManagerServer->recvSocketCount(); i++)
	{
		int sockType = packetManagerServer->recvSocketNum(i);
		if (sockType == 0)
			packetManagerServer->registClientSocket();
		else if (sockType == 1)
		{
			int num;
			if ((num = packetManagerServer->recvDataAnalysis(i, &outputSock, &outputCode, outputBuffer, &outputSize)) != -1)
				updateLogout(num);
			else
				run(outputSock, outputCode, outputBuffer, outputSize);
		}
	}
}

#ifdef _WIN32
void GameServer::getUserInfo(SOCKET sock, const char* name)
#elif __linux__
void GameServer::getUserInfo(int sock, const char* name)
#endif
{
	char message[BUF_SIZE];

	try
	{
		User getUser = userService->getUserInfo(name);
		memcpy(message, &getUser, sizeof(User));

		packetManagerServer->sendRequest(sock, REQUEST_USER_INFO, message, sizeof(User));
		//printf("send code(%d), UserInfo(%s), size(%d)\n", REQUEST_USER_INFO, getUser.getName(), sizeof(User));
	}
	catch (const runtime_error& error)
	{
		packetManagerServer->sendRequest(sock, REQUEST_USER_INFO, "unknown_id_send_fail", strlen("unknown_id_send_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::updateLogin(SOCKET sock, const char* name)
#elif __linux__
void GameServer::updateLogin(int sock, const char* name)
#endif
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User loginUser;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	list<InventoryInfo> inventoryList;
	list<InventoryInfo>::iterator inventoryIter;

	list<MapInfo> itemList;
	list<MapInfo>::iterator itemIter;

	int code;

	try
	{
		loginUser = userService->getUserInfo(name);

		if (loginUser.getLogin() == 0)
		{
			userService->updateLogin(sock, name);
			loginUser = userService->getUserInfo(name);
			packetManagerServer->sendRequest(sock, REQUEST_LOGIN, "login okey", strlen("login okey") + 1);
		}
		else
		{
			packetManagerServer->sendRequest(sock, REQUEST_LOGIN, "login fail", strlen("login fail") + 1);
			return;
		}

		loginUserList = userService->getFieldLoginUserAll(loginUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			memcpy(message, &loginUser, sizeof(User));
			packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

			iter->setAction(ACTION_MAP_IN);
			memcpy(message, &(*iter), sizeof(User));
			packetManagerServer->sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
		}

		mapMonsterList = mapManageService->getFieldMonster(loginUser.getField());

		for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
		{
			memcpy(message, &(*monsterIter), sizeof(MapInfo));
			packetManagerServer->sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
		}

		mapObjectList = mapManageService->getFieldObject(loginUser.getField());

		for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
		{
			memcpy(message, &(*objectIter), sizeof(MapInfo));
			packetManagerServer->sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
		}

		inventoryList = userService->getUserInventoryInfo(loginUser.getName());

		for (inventoryIter = inventoryList.begin(); inventoryIter != inventoryList.end(); inventoryIter++)
		{
			memcpy(message, &(*inventoryIter), sizeof(InventoryInfo));
			packetManagerServer->sendRequest(sock, REQUEST_INVENTORY_ITEM_INFO, message, sizeof(InventoryInfo));
			printf("REQUEST_INVENTORY_ITEM_INFO, name(%s), pos(%d, %d)\n", inventoryIter->getItemName(), inventoryIter->getXpos(), inventoryIter->getYpos());
		}
		printf("\n");

		itemList = mapManageService->getFieldItem(loginUser.getField());

		for (itemIter = itemList.begin(); itemIter != itemList.end(); itemIter++)
		{
			memcpy(message, &(*itemIter), sizeof(MapInfo));
			packetManagerServer->sendRequest(sock, REQUEST_FIELD_ITEM_INFO, message, sizeof(MapInfo));
		}
	}
	catch (const runtime_error& error)
	{
		packetManagerServer->sendRequest(sock, REQUEST_LOGIN, "login fail", strlen("login fail"));
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::updateLogout(SOCKET sock)
#elif __linux__
void GameServer::updateLogout(int sock)
#endif
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User logoutUser;

	try
	{
		logoutUser = userService->getUserInfo(sock);
		userService->updateLogout(logoutUser.getName());
		packetManagerServer->sendRequest(sock, REQUEST_LOGOUT, "logout okey", strlen("logout okey") + 1);

		loginUserList = userService->getFieldLoginUserAll(logoutUser.getField());

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			logoutUser.setAction(ACTION_MAP_OUT);
			memcpy(message, &logoutUser, sizeof(User));
			packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
		}
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
		packetManagerServer->sendRequest(sock, REQUEST_LOGOUT, "logout fail", strlen("logout fail") + 1);
	}
}

#ifdef _WIN32
void GameServer::chatting(SOCKET sock, const char* chatting)
#elif __linux__
void GameServer::chatting(int sock, const char* chatting)
#endif
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User chattingUser;
	Chatting chattingInfo;
	Chatting sendChattingInfo;

	try
	{
		chattingUser = userService->getUserInfo(sock);
		loginUserList = userService->getFieldLoginUserAll(chattingUser.getField());

		memcpy(&chattingInfo, chatting, sizeof(Chatting));
		chattingService->add(chattingInfo);

		sendChattingInfo = chattingService->getLatestChatting(chattingInfo.getName(), chattingInfo.getField());
		memcpy(message, &sendChattingInfo, sizeof(Chatting));

		packetManagerServer->sendRequest(sock, CHATTING_PROCESS, message, sizeof(Chatting));

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_CHATTING_PROCESS, message, sizeof(Chatting));
		}

		packetManagerServer->sendRequest(sock, REQUEST_CHATTING_FINISH, "chatting_finish", strlen("chatting_finish") + 1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::updateMoveInfo(SOCKET sock, const char* userInfo)
#elif __linux__
void GameServer::updateMoveInfo(int sock, const char* userInfo)
#endif
{
	char message[BUF_SIZE];
	User moveUser;
	list<User> fieldUserList, regionFieldUserList;
	list<User>::iterator iter;
	User user;

	list<MapInfo> mapMonsterList;
	list<MapInfo>::iterator monsterIter;

	list<MapInfo> mapObjectList;
	list<MapInfo>::iterator objectIter;

	list<MapInfo> mapItemList;
	list<MapInfo>::iterator itemIter;

	try
	{
		memcpy(&user, userInfo, sizeof(User));

		if (user.getAction() == ACTION_MAP_MOVE)
		{
			packetManagerServer->sendRequest(sock, REQUEST_MAP_MOVE, userInfo, sizeof(User));

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, userInfo, sizeof(User));
			}

			packetManagerServer->sendRequest(sock, REQUEST_MAP_MOVE_FINISH, "map_move_finish", strlen("map_move_finish") + 1);
		}
		else if (user.getAction() == ACTION_MAP_POTAL)
		{
			packetManagerServer->sendRequest(sock, REQUEST_MAP_MOVE, userInfo, sizeof(User));

			moveUser = userService->getUserInfo(user.getName());
			regionFieldUserList = userService->getFieldLoginUserAll(moveUser.getField());
			moveUser.setAction(ACTION_MAP_OUT);

			for (iter = regionFieldUserList.begin(); iter != regionFieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &moveUser, sizeof(User));
				packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			fieldUserList = userService->getFieldLoginUserAll(user.getField());
			user.setAction(ACTION_MAP_IN);
			userService->updateUserInfo(user);

			for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
			{
				if (iter->getSock() == sock)
					continue;

				memcpy(message, &user, sizeof(User));
				packetManagerServer->sendRequest(iter->getSock(), OTHER_USER_MAP_MOVE, message, sizeof(User));

				iter->setAction(ACTION_MAP_IN);
				memcpy(message, &(*iter), sizeof(User));
				packetManagerServer->sendRequest(sock, OTHER_USER_MAP_MOVE, message, sizeof(User));
			}

			mapMonsterList = mapManageService->getFieldMonster(user.getField());

			for (monsterIter = mapMonsterList.begin(); monsterIter != mapMonsterList.end(); monsterIter++)
			{
				memcpy(message, &(*monsterIter), sizeof(MapInfo));
				packetManagerServer->sendRequest(sock, REQUEST_FIELD_MONSTER_INFO, message, sizeof(MapInfo));
			}

			mapObjectList = mapManageService->getFieldObject(user.getField());

			for (objectIter = mapObjectList.begin(); objectIter != mapObjectList.end(); objectIter++)
			{
				memcpy(message, &(*objectIter), sizeof(MapInfo));
				packetManagerServer->sendRequest(sock, REQUEST_FIELD_OBJECT_INFO, message, sizeof(MapInfo));
			}

			mapItemList = mapManageService->getFieldItem(user.getField());

			for (itemIter = mapItemList.begin(); itemIter != mapItemList.end(); itemIter++)
			{
				memcpy(message, &(*itemIter), sizeof(MapInfo));
				packetManagerServer->sendRequest(sock, REQUEST_FIELD_ITEM_INFO, message, sizeof(MapInfo));
			}

			packetManagerServer->sendRequest(sock, REQUEST_MAP_POTAL_FINISH, "map_potal_finish", strlen("map_potal_finish") + 1);
		}
	}
	catch (const runtime_error& error)
	{
		packetManagerServer->sendRequest(sock, REQUEST_MAP_MOVE, "map_move_fail", strlen("map_move_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::createThrowItemOnMap(SOCKET sock, const char* inventoryInfo)
#elif __linux__
void GameServer::createThrowItemOnMap(int sock, const char* inventoryInfo)
#endif
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User user;
	InventoryInfo inventoryItemInfo;
	MapInfo insertMapInfo;
	MapInfo backItem;

	try
	{
		user = userService->getUserInfo(sock);
		loginUserList = userService->getFieldLoginUserAll(user.getField());
		backItem = mapManageService->getMaxOrderItem(user.getField(), user.getXpos(), user.getYpos());

		memcpy(&inventoryItemInfo, inventoryInfo, sizeof(InventoryInfo));

		insertMapInfo.setField(user.getField());
		insertMapInfo.setObjectCode(12);
		insertMapInfo.setName(inventoryItemInfo.getItemName());
		insertMapInfo.setType(inventoryItemInfo.getType());
		insertMapInfo.setXpos(user.getXpos());
		insertMapInfo.setYpos(user.getYpos());
		insertMapInfo.setZOrder(backItem.getZOrder() + 1);
		insertMapInfo.setFileDir(inventoryItemInfo.getFileDir());
		insertMapInfo.setCount(inventoryItemInfo.getCount());
		insertMapInfo.setHp(0);

		mapManageService->addFieldMapInfo(insertMapInfo);
		insertMapInfo = mapManageService->getMaxOrderItem(user.getField(), user.getXpos(), user.getYpos());
		userService->deleteInventoryItem(user.getName(), inventoryItemInfo.getXpos(), inventoryItemInfo.getYpos());

		memcpy(message, &insertMapInfo, sizeof(MapInfo));

		for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
		{
			packetManagerServer->sendRequest(iter->getSock(), REQUEST_FIELD_ITEM_INFO, message, sizeof(MapInfo));
		}

		packetManagerServer->sendRequest(sock, REQUEST_THROW_ITEM_FINISH, inventoryInfo, sizeof(InventoryInfo));
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::userGetMapItem(SOCKET sock, const char* userInfo)
#elif __linux__
void GameServer::userGetMapItem(int sock, const char* userInfo)
#endif
{
	char message[BUF_SIZE];
	list<User> loginUserList;
	list<User>::iterator iter;
	User getUser;
	MapInfo itemInfo;
	InventoryInfo inventoryInfo;
	list<InventoryInfo> userInventoryInfo;
	list<InventoryInfo>::iterator userInventoryInfoIter;

	try
	{
		memcpy(&getUser, userInfo, sizeof(User));
		loginUserList = userService->getFieldLoginUserAll(getUser.getField());

		itemInfo = mapManageService->getMaxOrderItem(getUser.getField(), getUser.getXpos(), getUser.getYpos());
		userInventoryInfo = userService->getUserInventoryInfo(getUser.getName());
		userInventoryInfoIter = userInventoryInfo.begin();

		for (int i = 0; i < INVENTORY_X_SIZE; i++)
		{
			for (int j = 0; j < INVENTORY_Y_SIZE; j++)
			{
				if (userInventoryInfo.size() != 0 && userInventoryInfoIter->getXpos() == i && userInventoryInfoIter->getYpos() == j)
				{
					userInventoryInfoIter++;
					continue;
				}
				else
				{
					mapManageService->deleteMaxOrderItem(getUser.getField(), getUser.getXpos(), getUser.getYpos());

					for (iter = loginUserList.begin(); iter != loginUserList.end(); iter++)
					{
						memcpy(message, &itemInfo, sizeof(MapInfo));
						packetManagerServer->sendRequest(iter->getSock(), DELETE_FIELD_ITEM, message, sizeof(MapInfo));
					}

					inventoryInfo.setItemName(itemInfo.getName());
					inventoryInfo.setUserName(getUser.getName());
					inventoryInfo.setType("ITEM");
					inventoryInfo.setXpos(i);
					inventoryInfo.setYpos(j);
					inventoryInfo.setFileDir(itemInfo.getFileDir());
					inventoryInfo.setCount(itemInfo.getCount());

					userService->addInventoryItem(inventoryInfo);

					memcpy(message, &inventoryInfo, sizeof(InventoryInfo));
					packetManagerServer->sendRequest(sock, REQUEST_EAT_ITEM, message, sizeof(InventoryInfo));
					packetManagerServer->sendRequest(sock, REQUEST_GET_ITEM_FINISH, "get_item_finish", strlen("get_item_finish") + 1);
					return;
				}
			}
		}

		packetManagerServer->sendRequest(sock, REQUEST_GET_ITEM_FINISH, "get_item_finish", strlen("get_item_finish") + 1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::moveInventoryInfo(SOCKET sock, const char* inventoryInfo)
#elif __linux__
void GameServer::moveInventoryInfo(int sock, const char* inventoryInfo)
#endif
{
	char message[BUF_SIZE];
	User user;
	InventoryInfo inventoryItemInfo;
	InventoryInfo* imsiInventoryItemInfo = NULL;
	InventoryInfo* targetInventoryItemInfo = NULL;
	list<InventoryInfo> inventoryItemList;
	list<InventoryInfo>::iterator inventoryItemListIter;

	try
	{
		user = userService->getUserInfo(sock);
		inventoryItemList = userService->getUserInventoryInfo(user.getName());

		memcpy(&inventoryItemInfo, inventoryInfo, sizeof(InventoryInfo));

		for (inventoryItemListIter = inventoryItemList.begin(); inventoryItemListIter != inventoryItemList.end(); inventoryItemListIter++)
		{
			if (inventoryItemInfo.getXpos() == inventoryItemListIter->getXpos() && inventoryItemInfo.getYpos() == inventoryItemListIter->getYpos())
			{
				imsiInventoryItemInfo = &(*inventoryItemListIter);
			}

			if (inventoryItemInfo.getIdx() == inventoryItemListIter->getIdx())
			{
				targetInventoryItemInfo = &(*inventoryItemListIter);
			}
		}

		if (imsiInventoryItemInfo == NULL)
		{
			userService->moveInventoryItem(inventoryItemInfo, inventoryItemInfo.getXpos(), inventoryItemInfo.getYpos());

			packetManagerServer->sendRequest(sock, MOVE_INVENTORY_ITEM, inventoryInfo, sizeof(InventoryInfo));
		}
		else
		{
			userService->moveInventoryItem(inventoryItemInfo, inventoryItemInfo.getXpos(), inventoryItemInfo.getYpos());
			userService->moveInventoryItem(*imsiInventoryItemInfo, targetInventoryItemInfo->getXpos(), targetInventoryItemInfo->getYpos());

			imsiInventoryItemInfo->setXpos(targetInventoryItemInfo->getXpos());
			imsiInventoryItemInfo->setYpos(targetInventoryItemInfo->getYpos());

			memcpy(message, imsiInventoryItemInfo, sizeof(InventoryInfo));
			packetManagerServer->sendRequest(sock, MOVE_INVENTORY_ITEM, message, sizeof(InventoryInfo));
			packetManagerServer->sendRequest(sock, MOVE_INVENTORY_ITEM, inventoryInfo, sizeof(InventoryInfo));
		}
		packetManagerServer->sendRequest(sock, MOVE_INVENTORY_ITEM_FINISH, "move_inventory_item_finish", strlen("move_inventory_item_finish") + 1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::updateUserInfo(SOCKET sock, const char* userInfo)
#elif __linux__
void GameServer::updateUserInfo(int sock, const char* userInfo)
#endif
{
	char message[BUF_SIZE];
	list<User> fieldUserList;
	list<User>::iterator iter;
	User user;

	try
	{
		memcpy(&user, userInfo, sizeof(User));

		fieldUserList = userService->getFieldLoginUserAll(user.getField());
		userService->updateUserInfo(user);

		for (iter = fieldUserList.begin(); iter != fieldUserList.end(); iter++)
		{
			if (iter->getSock() == sock)
				continue;

			packetManagerServer->sendRequest(iter->getSock(), UPDATE_USER_INFO, userInfo, sizeof(User));
		}

		packetManagerServer->sendRequest(sock, UPDATE_USER_INFO_FINISH, "update_user_finish", strlen("update_user_finish") + 1);
	}
	catch (const runtime_error& error)
	{
		packetManagerServer->sendRequest(sock, REQUEST_MAP_MOVE, "update_user_fail", strlen("update_user_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::insertUserInfo(SOCKET sock, const char* userInfo)
#elif __linux__
void GameServer::insertUserInfo(int sock, const char* userInfo)
#endif
{
	char message[BUF_SIZE];
	User user;

	try
	{
		memcpy(&user, userInfo, sizeof(User));

		user.setSock(0);
		user.setPassword("5678");
		user.setXpos(23);
		user.setYpos(11);
		user.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
		user.setSeeDirection(29);
		user.setAction(ACTION_MAP_MOVE_END);
		user.setLogin(0);
		user.setLastLogin("2018-03-17 10:42:57");
		user.setLastLogout("2018-03-17 10:43:00");
		user.setJoinDate("2018-01-01 10:00:00");

		if (userService->insertUserInfo(user) == true)
			packetManagerServer->sendRequest(sock, REQUEST_JOIN, "join_user_success", strlen("join_user_success") + 1);
		else
			packetManagerServer->sendRequest(sock, REQUEST_JOIN, "join_user_fail", strlen("join_user_fail") + 1);

		packetManagerServer->sendRequest(sock, REQUEST_JOIN_FINISH, "join_user_finish", strlen("join_user_finish") + 1);
	}
	catch (const runtime_error& error)
	{
		packetManagerServer->sendRequest(sock, REQUEST_JOIN_FINISH, "join_user_fail", strlen("join_user_fail") + 1);
		std::cout << '\t' << error.what() << std::endl;
	}
}

#ifdef _WIN32
void GameServer::connectionConfirm(int idx)
#elif __linux__
void GameServer::connectionConfirm(int idx)
#endif
{
	char message[BUF_SIZE];
	ServerInfo serverInfo;
	serverInfo.setIdx(idx);

	list<User> loginUser = userService->getLoginUserAll();
	list<User>::iterator iter;

	serverInfoService->updateServerInfo(serverInfo);
	serverInfo = serverInfoService->getServerInfo(idx);

	memcpy(message, &serverInfo, sizeof(ServerInfo));

	for (iter = loginUser.begin(); iter != loginUser.end(); iter++)
	{
		packetManagerServer->sendRequest(iter->getSock(), REQUEST_SERVER_INFO, message, sizeof(ServerInfo));
	}
}

#ifdef _WIN32
void GameServer::closeClient(SOCKET sock)
#elif __linux__
void GameServer::closeClient(int sock)
#endif
{
	updateLogout(sock);
	packetManagerServer->closeClient(sock);
}

void GameServer::regenMonster()
{
	this->mapManageService->regenMonster();
}