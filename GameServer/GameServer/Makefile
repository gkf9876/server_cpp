server : Main.o ApplicationContext.o TestApplicationContext.o Assert.o DataSource.o \
	Chatting.o InventoryInfo.o Map.o MapInfo.o Monster.o ServerInfo.o User.o LoadingScreen.o EventInfo.o \
	ChattingDao.o ChattingDaoTest.o InventoryInfoDao.o InventoryInfoDaoTest.o MapDao.o MapDaoTest.o MapInfoDao.o MapInfoDaoTest.o MonsterDao.o MonsterDaoTest.o ServerInfoDao.o UserDao.o UserDaoTest.o LoadingScreenDao.o LoadingScreenDaoTest.o EventInfoDao.o EventInfoDaoTest.o \
	ChattingService.o ChattingServiceTest.o MapManageService.o MapManageServiceTest.o UserService.o UserServiceTest.o LoadingScreenService.o LoadingScreenServiceTest.o ServerInfoService.o ServerInfoServiceTest.o EventInfoService.o EventInfoServiceTest.o \
	EventCondition.o EventObject.o EventProcedure.o EventSequence.o \
	PacketManager.o PacketManagerServer.o PacketManagerClient.o \
	cJSON.o Util.o TMXLoader.o TMXMap.o TMXTile.o TMXTileLayer.o TMXTileSet.o \
	GameClient.o GameServer.o GameServerTest.o
	gcc -o server Main.o ApplicationContext.o TestApplicationContext.o Assert.o DataSource.o \
		Chatting.o InventoryInfo.o Map.o MapInfo.o Monster.o ServerInfo.o User.o LoadingScreen.o EventInfo.o \
		ChattingDao.o ChattingDaoTest.o InventoryInfoDao.o InventoryInfoDaoTest.o MapDao.o MapDaoTest.o MapInfoDao.o MapInfoDaoTest.o MonsterDao.o MonsterDaoTest.o ServerInfoDao.o UserDao.o UserDaoTest.o LoadingScreenDao.o LoadingScreenDaoTest.o EventInfoDao.o EventInfoDaoTest.o \
		ChattingService.o ChattingServiceTest.o MapManageService.o MapManageServiceTest.o UserService.o UserServiceTest.o LoadingScreenService.o LoadingScreenServiceTest.o ServerInfoService.o ServerInfoServiceTest.o EventInfoService.o EventInfoServiceTest.o \
		EventCondition.o EventObject.o EventProcedure.o EventSequence.o \
		PacketManager.o PacketManagerServer.o PacketManagerClient.o \
		cJSON.o Util.o TMXLoader.o TMXMap.o TMXTile.o TMXTileLayer.o TMXTileSet.o \
		GameClient.o GameServer.o GameServerTest.o \
		libtmx.a `xml2-config --libs` -lz -lpthread -lmysqlclient -lstdc++ -lm -o server


Main.o : Main.cpp
	gcc -c -o Main.o Main.cpp
	
ApplicationContext.o : factory/ApplicationContext.cpp
	gcc -c -o ApplicationContext.o factory/ApplicationContext.cpp
	
TestApplicationContext.o : factory/TestApplicationContext.cpp
	gcc -c -o TestApplicationContext.o factory/TestApplicationContext.cpp

Assert.o : test/Assert.cpp
	gcc -c -o Assert.o test/Assert.cpp

DataSource.o : datasource/DataSource.cpp
	gcc -c -o DataSource.o datasource/DataSource.cpp

Chatting.o : domain/Chatting.cpp
	gcc -c -o Chatting.o domain/Chatting.cpp

InventoryInfo.o : domain/InventoryInfo.cpp
	gcc -c -o InventoryInfo.o domain/InventoryInfo.cpp

Map.o : domain/Map.cpp
	gcc -c -o Map.o domain/Map.cpp

MapInfo.o : domain/MapInfo.cpp
	gcc -c -o MapInfo.o domain/MapInfo.cpp

Monster.o : domain/Monster.cpp
	gcc -c -o Monster.o domain/Monster.cpp

ServerInfo.o : domain/ServerInfo.cpp
	gcc -c -o ServerInfo.o domain/ServerInfo.cpp

User.o : domain/User.cpp
	gcc -c -o User.o domain/User.cpp

LoadingScreen.o : domain/LoadingScreen.cpp
	gcc -c -o LoadingScreen.o domain/LoadingScreen.cpp
	
EventInfo.o : domain/EventInfo.cpp
	gcc -c -o EventInfo.o domain/EventInfo.cpp

ChattingDao.o : dao/ChattingDao.cpp
	gcc -c -o ChattingDao.o dao/ChattingDao.cpp

ChattingDaoTest.o : dao/ChattingDaoTest.cpp
	gcc -c -o ChattingDaoTest.o dao/ChattingDaoTest.cpp

InventoryInfoDao.o : dao/InventoryInfoDao.cpp
	gcc -c -o InventoryInfoDao.o dao/InventoryInfoDao.cpp

InventoryInfoDaoTest.o : dao/InventoryInfoDaoTest.cpp
	gcc -c -o InventoryInfoDaoTest.o dao/InventoryInfoDaoTest.cpp

MapDao.o : dao/MapDao.cpp
	gcc -c -o MapDao.o dao/MapDao.cpp

MapDaoTest.o : dao/MapDaoTest.cpp
	gcc -c -o MapDaoTest.o dao/MapDaoTest.cpp

MapInfoDao.o : dao/MapInfoDao.cpp
	gcc -c -o MapInfoDao.o dao/MapInfoDao.cpp

MapInfoDaoTest.o : dao/MapInfoDaoTest.cpp
	gcc -c -o MapInfoDaoTest.o dao/MapInfoDaoTest.cpp

MonsterDao.o : dao/MonsterDao.cpp
	gcc -c -o MonsterDao.o dao/MonsterDao.cpp

MonsterDaoTest.o : dao/MonsterDaoTest.cpp
	gcc -c -o MonsterDaoTest.o dao/MonsterDaoTest.cpp

ServerInfoDao.o : dao/ServerInfoDao.cpp
	gcc -c -o ServerInfoDao.o dao/ServerInfoDao.cpp

UserDao.o : dao/UserDao.cpp
	gcc -c -o UserDao.o dao/UserDao.cpp

UserDaoTest.o : dao/UserDaoTest.cpp
	gcc -c -o UserDaoTest.o dao/UserDaoTest.cpp

LoadingScreenDao.o : dao/LoadingScreenDao.cpp
	gcc -c -o LoadingScreenDao.o dao/LoadingScreenDao.cpp

LoadingScreenDaoTest.o : dao/LoadingScreenDaoTest.cpp
	gcc -c -o LoadingScreenDaoTest.o dao/LoadingScreenDaoTest.cpp

EventInfoDao.o : dao/EventInfoDao.cpp
	gcc -c -o EventInfoDao.o dao/EventInfoDao.cpp

EventInfoDaoTest.o : dao/EventInfoDaoTest.cpp
	gcc -c -o EventInfoDaoTest.o dao/EventInfoDaoTest.cpp

ChattingService.o : service/ChattingService.cpp
	gcc -c -o ChattingService.o service/ChattingService.cpp

ChattingServiceTest.o : service/ChattingServiceTest.cpp
	gcc -c -o ChattingServiceTest.o service/ChattingServiceTest.cpp

MapManageService.o : service/MapManageService.cpp
	gcc -c -o MapManageService.o service/MapManageService.cpp

MapManageServiceTest.o : service/MapManageServiceTest.cpp
	gcc -c -o MapManageServiceTest.o service/MapManageServiceTest.cpp

UserService.o : service/UserService.cpp
	gcc -c -o UserService.o service/UserService.cpp

UserServiceTest.o : service/UserServiceTest.cpp
	gcc -c -o UserServiceTest.o service/UserServiceTest.cpp

LoadingScreenService.o : service/LoadingScreenService.cpp
	gcc -c -o LoadingScreenService.o service/LoadingScreenService.cpp

LoadingScreenServiceTest.o : service/LoadingScreenServiceTest.cpp
	gcc -c -o LoadingScreenServiceTest.o service/LoadingScreenServiceTest.cpp

ServerInfoService.o : service/ServerInfoService.cpp
	gcc -c -o ServerInfoService.o service/ServerInfoService.cpp

ServerInfoServiceTest.o : service/ServerInfoServiceTest.cpp
	gcc -c -o ServerInfoServiceTest.o service/ServerInfoServiceTest.cpp
	
EventInfoService.o : service/EventInfoService.cpp
	gcc -c -o EventInfoService.o service/EventInfoService.cpp

EventInfoServiceTest.o : service/EventInfoServiceTest.cpp
	gcc -c -o EventInfoServiceTest.o service/EventInfoServiceTest.cpp
	
EventCondition.o : event/EventCondition.cpp
	gcc -c -o EventCondition.o event/EventCondition.cpp
	
EventObject.o : event/EventObject.cpp
	gcc -c -o EventObject.o event/EventObject.cpp
	
EventProcedure.o : event/EventProcedure.cpp
	gcc -c -o EventProcedure.o event/EventProcedure.cpp
	
EventSequence.o : event/EventSequence.cpp
	gcc -c -o EventSequence.o event/EventSequence.cpp

PacketManager.o : Packet/PacketManager.cpp
	gcc -c -o PacketManager.o Packet/PacketManager.cpp

PacketManagerServer.o : Packet/PacketManagerServer.cpp
	gcc -c -o PacketManagerServer.o Packet/PacketManagerServer.cpp

PacketManagerClient.o : Packet/PacketManagerClient.cpp
	gcc -c -o PacketManagerClient.o Packet/PacketManagerClient.cpp

cJSON.o : util/cJSON.c
	gcc -c -o cJSON.o util/cJSON.c
	
Util.o : util/Util.cpp
	gcc -c -o Util.o util/Util.cpp

TMXLoader.o : util/TMXLoader/TMXLoader.cpp
	gcc -c -o TMXLoader.o util/TMXLoader/TMXLoader.cpp -lstdc++
	
TMXMap.o : util/TMXLoader/TMXMap.cpp
	gcc -c -o TMXMap.o util/TMXLoader/TMXMap.cpp -lstdc++

TMXTile.o : util/TMXLoader/TMXTile.cpp
	gcc -c -o TMXTile.o util/TMXLoader/TMXTile.cpp -lstdc++

TMXTileLayer.o : util/TMXLoader/TMXTileLayer.cpp
	gcc -c -o TMXTileLayer.o util/TMXLoader/TMXTileLayer.cpp -lstdc++

TMXTileSet.o : util/TMXLoader/TMXTileSet.cpp
	gcc -c -o TMXTileSet.o util/TMXLoader/TMXTileSet.cpp -lstdc++

GameClient.o : GameClient.cpp
	gcc -c -o GameClient.o GameClient.cpp

GameServer.o : GameServer.cpp
	gcc -c -o GameServer.o GameServer.cpp

GameServerTest.o : GameServerTest.cpp
	gcc -c -o GameServerTest.o GameServerTest.cpp

clean :
	rm *.o server
