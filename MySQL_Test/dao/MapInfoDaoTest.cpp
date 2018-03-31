#include "MapInfoDaoTest.h"

MapInfoDaoTest::MapInfoDaoTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->mapInfoDao = new MapInfoDao(this->dataSource);

	this->mapInfo1 = new MapInfo();
	mapInfo1->setIdx(1);
	mapInfo1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo1->setObjectCode(12);
	mapInfo1->setName("´Ù¶÷Áã");
	mapInfo1->setType("MONSTER");
	mapInfo1->setXpos(4);
	mapInfo1->setYpos(6);
	mapInfo1->setZOrder(1);
	mapInfo1->setFileDir("Images/´Ù¶÷Áã.jpg");
	mapInfo1->setCount(1);
	mapInfo1->setHp(5);

	this->mapInfo2 = new MapInfo();
	mapInfo2->setIdx(2);
	mapInfo2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo2->setObjectCode(13);
	mapInfo2->setName("È£¶ûÀÌ");
	mapInfo2->setType("MONSTER");
	mapInfo2->setXpos(5);
	mapInfo2->setYpos(8);
	mapInfo2->setZOrder(2);
	mapInfo2->setFileDir("Images/È£¶ûÀÌ.jpg");
	mapInfo2->setCount(2);
	mapInfo2->setHp(15);

	this->mapInfo3 = new MapInfo();
	mapInfo3->setIdx(3);
	mapInfo3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo3->setObjectCode(14);
	mapInfo3->setName("°¡·Îµî");
	mapInfo3->setType("OBJECT");
	mapInfo3->setXpos(51);
	mapInfo3->setYpos(81);
	mapInfo3->setZOrder(3);
	mapInfo3->setFileDir("Images/°¡·Îµî.jpg");
	mapInfo3->setCount(3);
	mapInfo3->setHp(150);
}

MapInfoDaoTest::~MapInfoDaoTest()
{
	delete dataSource;
	delete mapInfoDao;
	delete mapInfo1;
	delete mapInfo2;
	delete mapInfo3;
}

void MapInfoDaoTest::run()
{
	addAndGet();
	getCountMonster();
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
	assertThat(mapInfo1.getIdx(), mapInfo2.getIdx());
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

		MapInfo mapinfoget1 = mapInfoDao->getMonster(mapInfo1->getXpos(), mapInfo1->getYpos());
		checkSameMapInfo(mapinfoget1, *mapInfo1);

		MapInfo mapinfoget2 = mapInfoDao->getMonster(mapInfo2->getXpos(), mapInfo2->getYpos());
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