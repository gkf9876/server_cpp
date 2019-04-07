#include "MapManageServiceTest.h"

MapManageServiceTest::MapManageServiceTest()
{
	this->map1 = new Map();
	map1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	map1->setMonster1("다람쥐");
	map1->setMonster2("사슴");
	map1->setMonster3("호랑이");
	map1->setMonster1Count(10);
	map1->setMonster2Count(5);
	map1->setMonster3Count(3);

	this->map2 = new Map();
	map2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx");
	map2->setMonster1("토끼");
	map2->setMonster2("너구리");
	map2->setMonster3("쥐");
	map2->setMonster1Count(11);
	map2->setMonster2Count(15);
	map2->setMonster3Count(17);

	this->map3 = new Map();
	map3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx");
	map3->setMonster1("들개");
	map3->setMonster2("사냥꾼");
	map3->setMonster3("고라니");
	map3->setMonster1Count(2);
	map3->setMonster2Count(20);
	map3->setMonster3Count(6);

	monster1.setName("다람쥐");
	monster1.setType("MONSTER");
	monster1.setFileDir("Resources/monster/다람쥐.jpg");
	monster1.setHp(10);

	monster2.setName("사슴");
	monster2.setType("MONSTER");
	monster2.setFileDir("Resources/monster/사슴.jpg");
	monster2.setHp(12);

	monster3.setName("호랑이");
	monster3.setType("MONSTER");
	monster3.setFileDir("Resources/monster/호랑이.jpg");
	monster3.setHp(20);

	monster4.setName("토끼");
	monster4.setType("MONSTER");
	monster4.setFileDir("Resources/monster/토끼.jpg");
	monster4.setHp(25);

	monster5.setName("너구리");
	monster5.setType("MONSTER");
	monster5.setFileDir("Resources/monster/너구리.jpg");
	monster5.setHp(28);

	monster6.setName("쥐");
	monster6.setType("MONSTER");
	monster6.setFileDir("Resources/monster/쥐.jpg");
	monster6.setHp(15);

	monster7.setName("들개");
	monster7.setType("MONSTER");
	monster7.setFileDir("Resources/monster/들개.jpg");
	monster7.setHp(30);

	monster8.setName("사냥꾼");
	monster8.setType("MONSTER");
	monster8.setFileDir("Resources/monster/사냥꾼.jpg");
	monster8.setHp(50);

	monster9.setName("고라니");
	monster9.setType("MONSTER");
	monster9.setFileDir("Resources/monster/고라니.jpg");
	monster9.setHp(27);

	mapInfo1.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo1.setObjectCode(1);
	mapInfo1.setName("다람쥐");
	mapInfo1.setType("MONSTER");
	mapInfo1.setXpos(4);
	mapInfo1.setYpos(6);
	mapInfo1.setZOrder(1);
	mapInfo1.setFileDir("Resources/monster/다람쥐.jpg");
	mapInfo1.setCount(1);
	mapInfo1.setHp(10);

	mapInfo2.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo2.setObjectCode(2);
	mapInfo2.setName("사슴");
	mapInfo2.setType("MONSTER");
	mapInfo2.setXpos(4);
	mapInfo2.setYpos(6);
	mapInfo2.setZOrder(1);
	mapInfo2.setFileDir("Resources/monster/사슴.jpg");
	mapInfo2.setCount(1);
	mapInfo2.setHp(10);

	mapInfo3.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo3.setObjectCode(3);
	mapInfo3.setName("호랑이");
	mapInfo3.setType("MONSTER");
	mapInfo3.setXpos(4);
	mapInfo3.setYpos(6);
	mapInfo3.setZOrder(1);
	mapInfo3.setFileDir("Resources/monster/호랑이.jpg");
	mapInfo3.setCount(1);
	mapInfo3.setHp(10);

	mapInfo4.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo4.setObjectCode(14);
	mapInfo4.setName("가로등");
	mapInfo4.setType("OBJECT");
	mapInfo4.setXpos(51);
	mapInfo4.setYpos(81);
	mapInfo4.setZOrder(3);
	mapInfo4.setFileDir("Images/가로등.jpg");
	mapInfo4.setCount(3);
	mapInfo4.setHp(150);

	mapInfo5.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo5.setObjectCode(14);
	mapInfo5.setName("신호등");
	mapInfo5.setType("OBJECT");
	mapInfo5.setXpos(11);
	mapInfo5.setYpos(31);
	mapInfo5.setZOrder(2);
	mapInfo5.setFileDir("Images/신호등.jpg");
	mapInfo5.setCount(2);
	mapInfo5.setHp(200);

	for (int i = 0; i < 10; i++)
	{
		char message[1024];
		item[i].setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
		item[i].setObjectCode(14);
		sprintf(message, "도토리_%d", i);
		item[i].setName(message);
		item[i].setType("ITEM");
		item[i].setXpos(211);
		item[i].setYpos(131);
		item[i].setZOrder(i);
		sprintf(message, "Images/도토리_%d.jpg", i);
		item[i].setFileDir(message);
		item[i].setCount(2 + i);
		item[i].setHp(0);
	}
}

MapManageServiceTest::~MapManageServiceTest()
{
	delete this->map1;
	delete this->map2;
	delete this->map3;
}

void MapManageServiceTest::setApplicationContext(ApplicationContext* context)
{
	mapManageService = context->mapManageService();

	mapDao = context->mapDao();
	mapInfoDao = context->mapInfoDao();
	monsterDao = context->monsterDao();
}

void MapManageServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MapManageServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void MapManageServiceTest::checkSameMapInfo(MapInfo mapInfo1, MapInfo mapInfo2)
{
	assertThat(mapInfo1.getField(), mapInfo2.getField());
	assertThat(mapInfo1.getObjectCode(), mapInfo2.getObjectCode());
	assertThat(mapInfo1.getName(), mapInfo2.getName());
	assertThat(mapInfo1.getType(), mapInfo2.getType());
	assertThat(mapInfo1.getXpos(), mapInfo2.getXpos());
	assertThat(mapInfo1.getYpos(), mapInfo2.getYpos());
	assertThat(mapInfo1.getZOrder(), mapInfo2.getZOrder());
	assertThat(mapInfo1.getFileDir(), mapInfo2.getFileDir());
	assertThat(mapInfo1.getCount(), mapInfo2.getCount());
	assertThat(mapInfo1.getHp(), mapInfo2.getHp());
}

void MapManageServiceTest::run()
{
	try
	{
		regenMonster();
		regenMonsterTransaction();
		getFieldMonster();
		getFieldObject();
		addFieldMapInfo();
		getMaxOrderItem();
		getFieldItem();
		deleteMaxOrderItem();
		loadTMXMap();
		moveMonsters();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MapManageServiceTest::regenMonster()
{
	std::cout << "MapManageServiceTest : regenMonster()" << std::endl;

	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);
	mapDao->add(*map3);

	monsterDao->deleteAll();
	monsterDao->add(monster1);
	monsterDao->add(monster2);
	monsterDao->add(monster3);
	monsterDao->add(monster4);
	monsterDao->add(monster5);
	monsterDao->add(monster6);
	monsterDao->add(monster7);
	monsterDao->add(monster8);
	monsterDao->add(monster9);

	mapInfoDao->deleteAll();
	mapManageService->loadTMXData();
	mapManageService->regenMonster();

	list<Map> mapList = this->mapDao->getAll();
	list<Map>::iterator iter;

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
	}

	mapInfoDao->deleteAll();
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo1);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo2);
	mapInfoDao->add(mapInfo3);
	mapInfoDao->add(mapInfo3);
	mapInfoDao->add(mapInfo3);

	mapManageService->regenMonster();

	mapList = this->mapDao->getAll();

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), iter->getMonster1Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), iter->getMonster2Count());
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), iter->getMonster3Count());
	}
}

void MapManageServiceTest::regenMonsterTransaction()
{
	std::cout << "MapManageServiceTest : regenMonsterTransaction()" << std::endl;

	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);

	map3->setMonster1("들개");
	mapDao->add(*map3);

	monsterDao->deleteAll();
	monsterDao->add(monster1);
	monsterDao->add(monster2);
	monsterDao->add(monster3);
	monsterDao->add(monster4);
	monsterDao->add(monster5);
	monsterDao->add(monster6);
	monsterDao->add(monster7);
	monsterDao->add(monster8);
	monsterDao->add(monster9);

	mapInfoDao->deleteAll();
	mapManageService->loadTMXData();
	mapManageService->regenMonster();

	list<Map> mapList = this->mapDao->getAll();
	list<Map>::iterator iter;

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster1()), 0);
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster2()), 0);
		assertThat(mapInfoDao->getCountFieldMonster(iter->getField(), iter->getMonster3()), 0);
	}
}

void MapManageServiceTest::getFieldMonster()
{
	std::cout << "MapManageServiceTest : getFieldMonster()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapInfoDao->add(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapInfoDao->add(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapInfoDao->add(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapInfoDao->add(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapInfoDao->add(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	list<MapInfo> fieldLoginMonsterList = mapInfoDao->getFieldMonster(mapInfo1.getField());
	list<MapInfo>::iterator iter;
	iter = fieldLoginMonsterList.begin();

	checkSameMapInfo(*iter, mapInfo1);

	iter++;
	checkSameMapInfo(*iter, mapInfo2);
}

void MapManageServiceTest::getFieldObject()
{
	std::cout << "MapManageServiceTest : getFieldObject()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapInfoDao->add(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapInfoDao->add(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapInfoDao->add(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapInfoDao->add(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapInfoDao->add(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	list<MapInfo> fieldLoginObjectList = mapInfoDao->getFieldObject(mapInfo1.getField());
	list<MapInfo>::iterator iter;
	iter = fieldLoginObjectList.begin();

	checkSameMapInfo(*iter, mapInfo4);

	iter++;
	checkSameMapInfo(*iter, mapInfo5);
}

void MapManageServiceTest::addFieldMapInfo()
{
	std::cout << "MapManageServiceTest : addFieldMapInfo()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapManageService->addFieldMapInfo(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapManageService->addFieldMapInfo(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapManageService->addFieldMapInfo(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapManageService->addFieldMapInfo(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapManageService->addFieldMapInfo(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	list<MapInfo> fieldLoginObjectList = mapInfoDao->getFieldObject(mapInfo1.getField());
	list<MapInfo>::iterator iter;
	iter = fieldLoginObjectList.begin();

	checkSameMapInfo(*iter, mapInfo4);

	iter++;
	checkSameMapInfo(*iter, mapInfo5);
}

void MapManageServiceTest::getMaxOrderItem()
{
	std::cout << "MapManageServiceTest : getMaxOrderItem()" << std::endl;

	char message[1024];

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapManageService->addFieldMapInfo(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapManageService->addFieldMapInfo(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapManageService->addFieldMapInfo(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapManageService->addFieldMapInfo(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapManageService->addFieldMapInfo(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCountFieldItem(item[0].getField()), i + 1);
		checkSameMapInfo(mapManageService->getMaxOrderItem(item[i].getField(), item[i].getXpos(), item[i].getYpos()), item[i]);
	}
}

void MapManageServiceTest::getFieldItem()
{
	std::cout << "MapManageServiceTest : getFieldItem()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapInfoDao->add(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapInfoDao->add(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapInfoDao->add(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapInfoDao->add(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapInfoDao->add(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCount(), 6 + i);
	}

	list<MapInfo> fieldLoginItemList = mapInfoDao->getFieldItem(mapInfo1.getField());
	list<MapInfo>::iterator iter;
	iter = fieldLoginItemList.begin();

	for (int i = 0; i < 10; i++)
	{
		checkSameMapInfo(*iter, item[i]);
		iter++;
	}
}

void MapManageServiceTest::deleteMaxOrderItem()
{
	std::cout << "MapManageServiceTest : deleteMaxOrderItem()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCount(), 0);

	mapInfoDao->add(mapInfo1);
	assertThat(mapInfoDao->getCount(), 1);

	mapInfoDao->add(mapInfo2);
	assertThat(mapInfoDao->getCount(), 2);

	mapInfoDao->add(mapInfo3);
	assertThat(mapInfoDao->getCount(), 3);

	mapInfoDao->add(mapInfo4);
	assertThat(mapInfoDao->getCount(), 4);

	mapInfoDao->add(mapInfo5);
	assertThat(mapInfoDao->getCount(), 5);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCount(), 6 + i);
	}

	for (int i = 0; i < 9; i++)
	{
		mapManageService->deleteMaxOrderItem(item[0].getField(), item[0].getXpos(), item[0].getYpos());
		checkSameMapInfo(mapManageService->getMaxOrderItem(item[0].getField(), item[0].getXpos(), item[0].getYpos()), item[8 - i]);
	}
}

void MapManageServiceTest::loadTMXMap()
{
	std::cout << "MapManageServiceTest : loadTMXMap()" << std::endl;

	mapInfoDao->deleteAll();
	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);
	mapDao->add(*map3);

	mapManageService->loadTMXData();
	mapManageService->regenMonster();

	list<Map> mapList = mapDao->getAll();
	list<Map>::iterator iter;

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		int monsterCount = iter->getMonster1Count() + iter->getMonster2Count() + iter->getMonster3Count();
		assertThat(monsterCount, mapInfoDao->getCountFieldMonster(iter->getField()));
	}
}

void MapManageServiceTest::moveMonsters()
{
	std::cout << "MapManageServiceTest : moveMonsters()" << std::endl;

	mapInfoDao->deleteAll();
	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);
	mapDao->add(*map3);

	mapManageService->loadTMXData();
	mapManageService->regenMonster();

	std::map<std::string, TMXLoader*> mapData = mapManageService->getMapData();

	mapManageService->moveMonsters();

	list<Map> mapList = this->mapDao->getAll();
	list<Map>::iterator iter;

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
		TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
		std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
		std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

		list<MapInfo> monsterList = mapInfoDao->getFieldMonster(iter->getField());
		list<MapInfo>::iterator iter2;

		for (iter2 = monsterList.begin(); iter2 != monsterList.end(); iter2++)
		{
			assertThat(backgroundTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 130);
			assertThat(metaInfoTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 0);
		}
	}

	mapManageService->moveMonsters();

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
		TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
		std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
		std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

		list<MapInfo> monsterList = mapInfoDao->getFieldMonster(iter->getField());
		list<MapInfo>::iterator iter2;

		for (iter2 = monsterList.begin(); iter2 != monsterList.end(); iter2++)
		{
			assertThat(backgroundTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 130);
			assertThat(metaInfoTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 0);
		}
	}

	mapManageService->moveMonsters();

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
		TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
		std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
		std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

		list<MapInfo> monsterList = mapInfoDao->getFieldMonster(iter->getField());
		list<MapInfo>::iterator iter2;

		for (iter2 = monsterList.begin(); iter2 != monsterList.end(); iter2++)
		{
			assertThat(backgroundTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 130);
			assertThat(metaInfoTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 0);
		}
	}

	mapManageService->moveMonsters();

	for (iter = mapList.begin(); iter != mapList.end(); iter++)
	{
		TMXTileLayer* metaInfoLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "MetaInfo");
		TMXTileLayer* backgroundLayer = mapData[iter->getField()]->getTMXTileLayer(iter->getField(), "Background");
		std::vector<std::vector<unsigned int>> metaInfoTileVector = metaInfoLayer->getTileVector();
		std::vector<std::vector<unsigned int>> backgroundTileVector = backgroundLayer->getTileVector();

		list<MapInfo> monsterList = mapInfoDao->getFieldMonster(iter->getField());
		list<MapInfo>::iterator iter2;

		for (iter2 = monsterList.begin(); iter2 != monsterList.end(); iter2++)
		{
			assertThat(backgroundTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 130);
			assertThat(metaInfoTileVector[metaInfoLayer->getHeight() - (iter2->getYpos() + 1)][iter2->getXpos()], 0);
		}
	}
}