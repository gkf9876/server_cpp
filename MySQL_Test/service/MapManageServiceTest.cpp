#include "MapManageServiceTest.h"

MapManageServiceTest::MapManageServiceTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->mapManageService = new MapManageService(this->dataSource);
	this->mapDao = new MapDao(this->dataSource);
	this->mapInfoDao = new MapInfoDao(this->dataSource);
	this->monsterDao = new MonsterDao(this->dataSource);

	this->map1 = new Map();
	map1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	map1->setMonster1("´Ù¶÷Áã");
	map1->setMonster2("»ç½¿");
	map1->setMonster3("È£¶ûÀÌ");
	map1->setMonster1Count(10);
	map1->setMonster2Count(5);
	map1->setMonster3Count(3);

	this->map2 = new Map();
	map2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx");
	map2->setMonster1("Åä³¢");
	map2->setMonster2("³Ê±¸¸®");
	map2->setMonster3("Áã");
	map2->setMonster1Count(11);
	map2->setMonster2Count(15);
	map2->setMonster3Count(17);

	this->map3 = new Map();
	map3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx");
	map3->setMonster1("µé°³");
	map3->setMonster2("»ç³É²Û");
	map3->setMonster3("°í¶ó´Ï");
	map3->setMonster1Count(2);
	map3->setMonster2Count(20);
	map3->setMonster3Count(6);

	this->monster1;
	monster1.setName("´Ù¶÷Áã");
	monster1.setType("MONSTER");
	monster1.setFileDir("Resources/monster/´Ù¶÷Áã.jpg");
	monster1.setHp(10);

	this->monster2;
	monster2.setName("»ç½¿");
	monster2.setType("MONSTER");
	monster2.setFileDir("Resources/monster/»ç½¿.jpg");
	monster2.setHp(12);

	this->monster3;
	monster3.setName("È£¶ûÀÌ");
	monster3.setType("MONSTER");
	monster3.setFileDir("Resources/monster/È£¶ûÀÌ.jpg");
	monster3.setHp(20);

	this->monster4;
	monster4.setName("Åä³¢");
	monster4.setType("MONSTER");
	monster4.setFileDir("Resources/monster/Åä³¢.jpg");
	monster4.setHp(25);

	this->monster5;
	monster5.setName("³Ê±¸¸®");
	monster5.setType("MONSTER");
	monster5.setFileDir("Resources/monster/³Ê±¸¸®.jpg");
	monster5.setHp(28);

	this->monster6;
	monster6.setName("Áã");
	monster6.setType("MONSTER");
	monster6.setFileDir("Resources/monster/Áã.jpg");
	monster6.setHp(15);

	this->monster7;
	monster7.setName("µé°³");
	monster7.setType("MONSTER");
	monster7.setFileDir("Resources/monster/µé°³.jpg");
	monster7.setHp(30);

	this->monster8;
	monster8.setName("»ç³É²Û");
	monster8.setType("MONSTER");
	monster8.setFileDir("Resources/monster/»ç³É²Û.jpg");
	monster8.setHp(50);

	this->monster9;
	monster9.setName("°í¶ó´Ï");
	monster9.setType("MONSTER");
	monster9.setFileDir("Resources/monster/°í¶ó´Ï.jpg");
	monster9.setHp(27);

	this->mapInfo1;
	mapInfo1.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo1.setObjectCode(1);
	mapInfo1.setName("´Ù¶÷Áã");
	mapInfo1.setType("MONSTER");
	mapInfo1.setXpos(4);
	mapInfo1.setYpos(6);
	mapInfo1.setZOrder(1);
	mapInfo1.setFileDir("Resources/monster/´Ù¶÷Áã.jpg");
	mapInfo1.setCount(1);
	mapInfo1.setHp(10);

	this->mapInfo2;
	mapInfo2.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo2.setObjectCode(2);
	mapInfo2.setName("»ç½¿");
	mapInfo2.setType("MONSTER");
	mapInfo2.setXpos(4);
	mapInfo2.setYpos(6);
	mapInfo2.setZOrder(1);
	mapInfo2.setFileDir("Resources/monster/»ç½¿.jpg");
	mapInfo2.setCount(1);
	mapInfo2.setHp(10);

	this->mapInfo3;
	mapInfo3.setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	mapInfo3.setObjectCode(3);
	mapInfo3.setName("È£¶ûÀÌ");
	mapInfo3.setType("MONSTER");
	mapInfo3.setXpos(4);
	mapInfo3.setYpos(6);
	mapInfo3.setZOrder(1);
	mapInfo3.setFileDir("Resources/monster/È£¶ûÀÌ.jpg");
	mapInfo3.setCount(1);
	mapInfo3.setHp(10);
}

MapManageServiceTest::~MapManageServiceTest()
{
	delete this->dataSource;
	delete this->mapManageService;
	delete this->mapDao;
	delete this->mapInfoDao;

	delete this->map1;
	delete this->map2;
	delete this->map3;
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

void MapManageServiceTest::run()
{
	regenMonster();
	regenMonsterTransaction();
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

	map3->setMonster1("È«±æµ¿");
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