#include "MapDaoTest.h"

MapDaoTest::MapDaoTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->mapDao = new MapDao(this->dataSource);

	this->map1 = new Map();
	map1->setIdx(1);
	map1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx");
	map1->setMonster1("다람쥐");
	map1->setMonster2("deer");
	map1->setMonster3("호랑이");
	map1->setMonster1Count(4);
	map1->setMonster2Count(6);
	map1->setMonster3Count(5);

	this->map2 = new Map();
	map2->setIdx(2);
	map2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx");
	map2->setMonster1("다람쥐2");
	map2->setMonster2("deer2");
	map2->setMonster3("호랑이2");
	map2->setMonster1Count(42);
	map2->setMonster2Count(62);
	map2->setMonster3Count(52);

	this->map3 = new Map();
	map3->setIdx(3);
	map3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx");
	map3->setMonster1("다람쥐3");
	map3->setMonster2("deer3");
	map3->setMonster3("호랑이3");
	map3->setMonster1Count(43);
	map3->setMonster2Count(63);
	map3->setMonster3Count(53);
}

MapDaoTest::~MapDaoTest()
{
	delete dataSource;
	delete mapDao;
	delete map1;
	delete map2;
	delete map3;
}

void MapDaoTest::run()
{
	try
	{
		update();
		select();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MapDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MapDaoTest::assertThat(const char* value, const char* compValue)
{
	if (strcmp(value, compValue))
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MapDaoTest::checkSameMap(Map map1, Map map2)
{
	//assertThat(map1.getIdx(), map2.getIdx());
	assertThat(map1.getField(), map2.getField());
	assertThat(map1.getMonster1(), map2.getMonster1());
	assertThat(map1.getMonster2(), map2.getMonster2());
	assertThat(map1.getMonster3(), map2.getMonster3());
	assertThat(map1.getMonster1Count(), map2.getMonster1Count());
	assertThat(map1.getMonster2Count(), map2.getMonster2Count());
	assertThat(map1.getMonster3Count(), map2.getMonster3Count());
}

void MapDaoTest::update()
{
	std::cout << "MapDaoTest : update()" << std::endl;
	mapDao->deleteAll();
	mapDao->add(*map1);
	mapDao->add(*map2);

	map1->setMonster1("다람쥐5");
	map1->setMonster2("deer5");
	map1->setMonster3("호랑이5");
	map1->setMonster1Count(45);
	map1->setMonster2Count(65);
	map1->setMonster3Count(55);

	mapDao->update(*map1);

	Map map1Update = mapDao->get(map1->getField());
	checkSameMap(map1Update, *map1);
	Map map2Update = mapDao->get(map2->getField());
	checkSameMap(map2Update, *map2);
}

void MapDaoTest::select()
{
	try
	{
		std::cout << "MapDaoTest : select()" << std::endl;

		list<Map> mapList = mapDao->getAll();
		assertThat(mapList.size(), mapDao->getCount());
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}