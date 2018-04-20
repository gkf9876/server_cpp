#include "MonsterDaoTest.h"

MonsterDaoTest::MonsterDaoTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->monsterDao = new MonsterDao(this->dataSource);

	this->monster1 = new Monster();
	monster1->setIdx(1);
	monster1->setName("다람쥐");
	monster1->setType("MONSTER");
	monster1->setFileDir("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");
	monster1->setHp(12);

	this->monster2 = new Monster();
	monster2->setIdx(2);
	monster2->setName("토끼");
	monster2->setType("MONSTER");
	monster2->setFileDir("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");
	monster2->setHp(20);

	this->monster3 = new Monster();
	monster3->setIdx(3);
	monster3->setName("호랑이");
	monster3->setType("MONSTER");
	monster3->setFileDir("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
	monster3->setHp(50);
}

MonsterDaoTest::~MonsterDaoTest()
{
	delete dataSource;
	delete monsterDao;
	delete monster1;
	delete monster2;
	delete monster3;
}

void MonsterDaoTest::run()
{
	addAndGet();
	getMonsterFailure();
	duplciateKey();
	update();
}

void MonsterDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void MonsterDaoTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void MonsterDaoTest::checkSameMonster(Monster monster1, Monster monster2)
{
	assertThat(monster1.getIdx(), monster2.getIdx());
	assertThat(monster1.getName(), monster2.getName());
	assertThat(monster1.getType(), monster2.getType());
	assertThat(monster1.getFileDir(), monster2.getFileDir());
	assertThat(monster1.getHp(), monster2.getHp());
}

void MonsterDaoTest::addAndGet()
{
	std::cout << "MonsterDaoTest : addAndGet()" << std::endl;

	monsterDao->deleteAll();
	assertThat(monsterDao->getCount(), 0);

	monsterDao->add(*monster1);
	monsterDao->add(*monster2);
	assertThat(monsterDao->getCount(), 2);

	Monster monsterget1 = monsterDao->get(monster1->getName());
	checkSameMonster(monsterget1, *monster1);

	Monster monsterget2 = monsterDao->get(monster2->getName());
	checkSameMonster(monsterget2, *monster2);
}

void MonsterDaoTest::getMonsterFailure()
{
	std::cout << "MonsterDaoTest : getMonsterFailure()" << std::endl;

	monsterDao->deleteAll();
	assertThat(monsterDao->getCount(), 0);

	try
	{
		Monster monsterget = monsterDao->get("unknown_id");
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MonsterDaoTest::duplciateKey()
{
	std::cout << "MonsterDaoTest : duplciateKey()" << std::endl;

	monsterDao->deleteAll();

	try
	{
		monsterDao->add(*monster1);
		monsterDao->add(*monster1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void MonsterDaoTest::update()
{
	std::cout << "MonsterDaoTest : update()" << std::endl;

	monsterDao->deleteAll();
	monsterDao->add(*monster1);
	monsterDao->add(*monster2);

	monster1->setIdx(1);
	monster1->setName("다람쥐");
	monster1->setType("MONSTER");
	monster1->setFileDir("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");
	monster1->setHp(6);

	monsterDao->update(*monster1);

	Monster monster1Update = monsterDao->get(monster1->getName());
	checkSameMonster(monster1Update, *monster1);
	Monster monster2Update = monsterDao->get(monster2->getName());
	checkSameMonster(monster2Update, *monster2);
}