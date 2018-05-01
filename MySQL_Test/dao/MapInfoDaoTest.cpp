#include "MapInfoDaoTest.h"

MapInfoDaoTest::MapInfoDaoTest()
{
	this->mapInfo1 = new MapInfo();
	mapInfo1->setIdx(1);
	mapInfo1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo1->setObjectCode(12);
	mapInfo1->setName("다람쥐");
	mapInfo1->setType("MONSTER");
	mapInfo1->setXpos(4);
	mapInfo1->setYpos(6);
	mapInfo1->setZOrder(1);
	mapInfo1->setFileDir("Images/다람쥐.jpg");
	mapInfo1->setCount(1);
	mapInfo1->setHp(5);

	this->mapInfo2 = new MapInfo();
	mapInfo2->setIdx(2);
	mapInfo2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo2->setObjectCode(13);
	mapInfo2->setName("호랑이");
	mapInfo2->setType("MONSTER");
	mapInfo2->setXpos(5);
	mapInfo2->setYpos(8);
	mapInfo2->setZOrder(2);
	mapInfo2->setFileDir("Images/호랑이.jpg");
	mapInfo2->setCount(2);
	mapInfo2->setHp(15);

	this->mapInfo3 = new MapInfo();
	mapInfo3->setIdx(3);
	mapInfo3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo3->setObjectCode(14);
	mapInfo3->setName("가로등");
	mapInfo3->setType("OBJECT");
	mapInfo3->setXpos(51);
	mapInfo3->setYpos(81);
	mapInfo3->setZOrder(3);
	mapInfo3->setFileDir("Images/가로등.jpg");
	mapInfo3->setCount(3);
	mapInfo3->setHp(150);

	this->mapInfo4 = new MapInfo();
	mapInfo4->setIdx(4);
	mapInfo4->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo4->setObjectCode(14);
	mapInfo4->setName("신호등");
	mapInfo4->setType("OBJECT");
	mapInfo4->setXpos(11);
	mapInfo4->setYpos(31);
	mapInfo4->setZOrder(2);
	mapInfo4->setFileDir("Images/신호등.jpg");
	mapInfo4->setCount(2);
	mapInfo4->setHp(200);

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

MapInfoDaoTest::~MapInfoDaoTest()
{
	delete mapInfo1;
	delete mapInfo2;
	delete mapInfo3;
	delete mapInfo4;
}

void MapInfoDaoTest::setApplicationContext(ApplicationContext* context)
{
	this->mapInfoDao = context->mapInfoDao();
}

void MapInfoDaoTest::run()
{
	try
	{
		addAndGet();
		getCountMonster();
		getFieldMonster();
		getFieldObject();
		getMaxOrderItem();
		getFieldItem();
		deleteMapInfo();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MapInfoDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MapInfoDaoTest::assertThat(const char* value, const char* compValue)
{
	if (strcmp(value, compValue))
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MapInfoDaoTest::checkSameMapInfo(MapInfo mapInfo1, MapInfo mapInfo2)
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

void MapInfoDaoTest::addAndGet()
{
	try
	{
		std::cout << "MapInfoDaoTest : addAndGet()" << std::endl;

		mapInfoDao->deleteAll();
		assertThat(mapInfoDao->getCount(), 0);

		mapInfoDao->add(*mapInfo1);
		mapInfoDao->add(*mapInfo2);
		assertThat(mapInfoDao->getCount(), 2);

		MapInfo mapinfoget1 = mapInfoDao->getMonster(mapInfo1->getField(), mapInfo1->getXpos(), mapInfo1->getYpos());
		checkSameMapInfo(mapinfoget1, *mapInfo1);

		MapInfo mapinfoget2 = mapInfoDao->getMonster(mapInfo2->getField(), mapInfo2->getXpos(), mapInfo2->getYpos());
		checkSameMapInfo(mapinfoget2, *mapInfo2);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MapInfoDaoTest::getCountMonster()
{
	try
	{
		std::cout << "MapInfoDaoTest : getCountMonster()" << std::endl;

		mapInfoDao->deleteAll();
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField(), mapInfo1->getName()), 0);

		mapInfoDao->add(*mapInfo1);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField(), mapInfo1->getName()), 1);
		mapInfoDao->add(*mapInfo1);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField(), mapInfo1->getName()), 2);
		mapInfoDao->add(*mapInfo1);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField(), mapInfo1->getName()), 3);

		mapInfoDao->add(*mapInfo2);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo2->getField(), mapInfo2->getName()), 1);
		mapInfoDao->add(*mapInfo2);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo2->getField(), mapInfo2->getName()), 2);

		mapInfoDao->add(*mapInfo3);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo3->getField(), mapInfo3->getName()), 0);
		mapInfoDao->add(*mapInfo3);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo3->getField(), mapInfo3->getName()), 0);
		mapInfoDao->add(*mapInfo3);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo3->getField(), mapInfo3->getName()), 0);
		mapInfoDao->add(*mapInfo3);
		assertThat(mapInfoDao->getCountFieldMonster(mapInfo3->getField(), mapInfo3->getName()), 0);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MapInfoDaoTest::getFieldMonster()
{
	std::cout << "MapInfoDaoTest : getFieldMonster()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField()), 0);

	mapInfoDao->add(*mapInfo1);
	assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField()), 1);

	mapInfoDao->add(*mapInfo2);
	assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField()), 2);

	mapInfoDao->add(*mapInfo3);
	assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField()), 2);

	mapInfoDao->add(*mapInfo4);
	assertThat(mapInfoDao->getCountFieldMonster(mapInfo1->getField()), 2);

	list<MapInfo> fieldLoginUserList = mapInfoDao->getFieldMonster(mapInfo1->getField());
	list<MapInfo>::iterator iter;
	iter = fieldLoginUserList.begin();

	checkSameMapInfo(*iter, *mapInfo1);

	iter++;
	checkSameMapInfo(*iter, *mapInfo2);
}

void MapInfoDaoTest::getFieldObject()
{
	std::cout << "MapInfoDaoTest : getFieldObject()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo1);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo2);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo3);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 1);

	mapInfoDao->add(*mapInfo4);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);

	list<MapInfo> fieldObjectList = mapInfoDao->getFieldObject(mapInfo1->getField());
	list<MapInfo>::iterator iter;
	iter = fieldObjectList.begin();

	checkSameMapInfo(*iter, *mapInfo3);

	iter++;
	checkSameMapInfo(*iter, *mapInfo4);
}

void MapInfoDaoTest::getMaxOrderItem()
{
	std::cout << "MapInfoDaoTest : getMaxOrderItem()" << std::endl;

	char message[1024];

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo1);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo2);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo3);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 1);

	mapInfoDao->add(*mapInfo4);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCountFieldItem(mapInfo3->getField()), i + 1);
		checkSameMapInfo(mapInfoDao->getMaxOrderItem(item[0].getField(), item[0].getXpos(), item[0].getYpos()), item[i]);
	}
}

void MapInfoDaoTest::getFieldItem()
{
	std::cout << "MapInfoDaoTest : getFieldItem()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo1);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo2);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo3);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 1);

	mapInfoDao->add(*mapInfo4);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);
	}

	list<MapInfo> fieldItemList = mapInfoDao->getFieldItem(item[0].getField());
	list<MapInfo>::iterator iter;
	iter = fieldItemList.begin();

	for (int i = 0; i < 10; i++)
	{
		checkSameMapInfo(*iter, item[i]);
		iter++;
	}
}

void MapInfoDaoTest::deleteMapInfo()
{
	std::cout << "MapInfoDaoTest : deleteMapInfo()" << std::endl;

	mapInfoDao->deleteAll();
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo1);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo2);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 0);

	mapInfoDao->add(*mapInfo3);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 1);

	mapInfoDao->add(*mapInfo4);
	assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->add(item[i]);
		assertThat(mapInfoDao->getCountFieldObject(mapInfo3->getField()), 2);
	}

	mapInfoDao->deleteMapInfo(1, mapInfo1->getField());
	assertThat(mapInfoDao->getCount(), 13);

	mapInfoDao->deleteMapInfo(2, mapInfo2->getField());
	assertThat(mapInfoDao->getCount(), 12);

	mapInfoDao->deleteMapInfo(3, mapInfo3->getField());
	assertThat(mapInfoDao->getCount(), 11);

	mapInfoDao->deleteMapInfo(4, mapInfo4->getField());
	assertThat(mapInfoDao->getCount(), 10);

	for (int i = 0; i < 10; i++)
	{
		mapInfoDao->deleteMapInfo(5 + i, item[i].getField());
		assertThat(mapInfoDao->getCount(), 9 - i);
	}
}