server : Main.o DataSource.o Chatting.o InventoryInfo.o Map.o MapInfo.o Monster.o ServerInfo.o User.o ChattingDao.o ChattingDaoTest.o InventoryInfoDao.o InventoryInfoDaoTest.o MapDao.o MapDaoTest.o MapInfoDao.o MapInfoDaoTest.o MonsterDao.o MonsterDaoTest.o ServerInfoDao.o UserDao.o UserDaoTest.o ChattingService.o ChattingServiceTest.o MapManageService.o MapManageServiceTest.o UserService.o UserServiceTest.o GameClient.o GameServer.o GameServerTest.o
	gcc -o server Main.o DataSource.o Chatting.o InventoryInfo.o Map.o MapInfo.o Monster.o ServerInfo.o User.o ChattingDao.o ChattingDaoTest.o InventoryInfoDao.o InventoryInfoDaoTest.o MapDao.o MapDaoTest.o MapInfoDao.o MapInfoDaoTest.o MonsterDao.o MonsterDaoTest.o ServerInfoDao.o UserDao.o UserDaoTest.o ChattingService.o ChattingServiceTest.o MapManageService.o MapManageServiceTest.o UserService.o UserServiceTest.o GameClient.o GameServer.o GameServerTest.o libtmx.a `xml2-config --libs` -lz -lpthread -lmysqlclient -lstdc++ -o server


Main.o : Main.cpp
	gcc -c -o Main.o Main.cpp

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

GameClient.o : GameClient.cpp
	gcc -c -o GameClient.o GameClient.cpp

GameServer.o : GameServer.cpp
	gcc -c -o GameServer.o GameServer.cpp

GameServerTest.o : GameServerTest.cpp
	gcc -c -o GameServerTest.o GameServerTest.cpp

clean :
	rm *.o server
