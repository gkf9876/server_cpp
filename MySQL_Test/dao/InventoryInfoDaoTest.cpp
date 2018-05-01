#include "InventoryInfoDaoTest.h"

InventoryInfoDaoTest::InventoryInfoDaoTest()
{
	this->inventoryInfo1 = new InventoryInfo();
	inventoryInfo1->setIdx(1);
	inventoryInfo1->setItemName("사과");
	inventoryInfo1->setUserName("홍길동");
	inventoryInfo1->setType("아이템");
	inventoryInfo1->setXpos(5);
	inventoryInfo1->setYpos(4);
	inventoryInfo1->setFileDir("TileMaps / KonyangUniv.Daejeon / JukhunDigitalFacilitie / floor_08 / floor.tmx1");
	inventoryInfo1->setCount(5);

	this->inventoryInfo2 = new InventoryInfo();
	inventoryInfo2->setIdx(2);
	inventoryInfo2->setItemName("오렌지");
	inventoryInfo2->setUserName("김동우");
	inventoryInfo2->setType("아이템");
	inventoryInfo2->setXpos(7);
	inventoryInfo2->setYpos(8);
	inventoryInfo2->setFileDir("TileMaps / KonyangUniv.Daejeon / JukhunDigitalFacilitie / floor_08 / floor.tmx2");
	inventoryInfo2->setCount(11);

	this->inventoryInfo3 = new InventoryInfo();
	inventoryInfo3->setIdx(3);
	inventoryInfo3->setItemName("토마토");
	inventoryInfo3->setUserName("gkf1234");
	inventoryInfo3->setType("아이템");
	inventoryInfo3->setXpos(11);
	inventoryInfo3->setYpos(1);
	inventoryInfo3->setFileDir("TileMaps / KonyangUniv.Daejeon / JukhunDigitalFacilitie / floor_08 / floor.tmx3");
	inventoryInfo3->setCount(2);

	for (int i = 0; i < 10; i++)
	{
		char message[100];
		sprintf(message, "토마토_%d", i);
		item[i].setItemName(message);
		item[i].setUserName("gkf1234");
		item[i].setType("ITEM");
		item[i].setXpos(1 + i);
		item[i].setYpos(10 + i);
		sprintf(message, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_%d", i);
		item[i].setFileDir(message);
		item[i].setCount(1 + i);
	}

	for (int i = 10; i < 20; i++)
	{
		char message[100];
		sprintf(message, "토마토_%d", i);
		item[i].setItemName(message);
		sprintf(message, "gkf1234_%d", i);
		item[i].setUserName(message);
		item[i].setType("ITEM");
		item[i].setXpos(1 + i);
		item[i].setYpos(10 + i);
		sprintf(message, "TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_%d", i);
		item[i].setFileDir(message);
		item[i].setCount(1 + i);
	}
}

InventoryInfoDaoTest::~InventoryInfoDaoTest()
{
	delete inventoryInfo1;
	delete inventoryInfo2;
	delete inventoryInfo3;
}

void InventoryInfoDaoTest::setApplicationContext(ApplicationContext* context)
{
	this->inventoryInfoDao = context->inventoryInfoDao();
}

void InventoryInfoDaoTest::run()
{
	try
	{
		addAndGet();
		getUserFailure();
		update();
		getUserInventoryInfo();
		deleteInventoryInfo();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void InventoryInfoDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void InventoryInfoDaoTest::assertThat(const char* value, const char* compValue)
{
	if (strcmp(value, compValue))
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void InventoryInfoDaoTest::checkSameInventoryInfo(InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2)
{
	assertThat(inventoryInfo1.getItemName(), inventoryInfo2.getItemName());
	assertThat(inventoryInfo1.getUserName(), inventoryInfo2.getUserName());
	assertThat(inventoryInfo1.getType(), inventoryInfo2.getType());
	assertThat(inventoryInfo1.getXpos(), inventoryInfo2.getXpos());
	assertThat(inventoryInfo1.getYpos(), inventoryInfo2.getYpos());
	assertThat(inventoryInfo1.getFileDir(), inventoryInfo2.getFileDir());
	assertThat(inventoryInfo1.getCount(), inventoryInfo2.getCount());
}

void InventoryInfoDaoTest::addAndGet()
{
	std::cout << "InventoryInfoDaoTest : addAndGet()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);

	inventoryInfoDao->add(*inventoryInfo1);
	inventoryInfoDao->add(*inventoryInfo2);
	assertThat(inventoryInfoDao->getCount(), 2);

	InventoryInfo inventoryInfoget1 = inventoryInfoDao->get(inventoryInfo1->getItemName());
	checkSameInventoryInfo(inventoryInfoget1, *inventoryInfo1);

	InventoryInfo inventoryInfoget2 = inventoryInfoDao->get(inventoryInfo2->getItemName());
	checkSameInventoryInfo(inventoryInfoget2, *inventoryInfo2);
}

void InventoryInfoDaoTest::getUserFailure()
{
	std::cout << "InventoryInfoDaoTest : getUserFailure()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);

	try
	{
		InventoryInfo inventoryInfoget = inventoryInfoDao->get("unknown_id");
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void InventoryInfoDaoTest::update()
{
	std::cout << "InventoryInfoDaoTest : update()" << std::endl;

	inventoryInfoDao->deleteAll();
	inventoryInfoDao->add(*inventoryInfo1);
	inventoryInfoDao->add(*inventoryInfo2);

	inventoryInfo1->setIdx(5);
	inventoryInfo1->setUserName("임꺽정");
	inventoryInfo1->setType("몬스터");
	inventoryInfo1->setXpos(15);
	inventoryInfo1->setYpos(14);
	inventoryInfo1->setFileDir("TileMaps / KonyangUniv.Daejeon / JukhunDigitalFacilitie / floor_08 / floor.tmx15");
	inventoryInfo1->setCount(55);

	inventoryInfoDao->update(*inventoryInfo1);

	InventoryInfo inventoryInfo1Update = inventoryInfoDao->get(inventoryInfo1->getItemName());
	checkSameInventoryInfo(inventoryInfo1Update, *inventoryInfo1);
	InventoryInfo user2Update = inventoryInfoDao->get(inventoryInfo2->getItemName());
	checkSameInventoryInfo(user2Update, *inventoryInfo2);
}

void InventoryInfoDaoTest::getUserInventoryInfo()
{
	std::cout << "InventoryInfoDaoTest : getUserInventoryInfo()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);

	for (int i = 0; i < 20; i++)
	{
		inventoryInfoDao->add(item[i]);
		assertThat(inventoryInfoDao->getCount(), i + 1);
	}

	list<InventoryInfo> inventoryList = inventoryInfoDao->getUserInventoryList("gkf1234");
	list<InventoryInfo>::iterator iter;
	iter = inventoryList.begin();

	for (int i = 0; i < 10; i++)
	{
		checkSameInventoryInfo(*iter, item[i]);
		iter++;
	}
}

void InventoryInfoDaoTest::deleteInventoryInfo()
{
	std::cout << "InventoryInfoDaoTest : deleteInventoryInfo()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);

	for (int i = 0; i < 20; i++)
	{
		inventoryInfoDao->add(item[i]);
		assertThat(inventoryInfoDao->getCount(), i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		inventoryInfoDao->deleteInventoryInfo("gkf1234", item[i].getXpos(), item[i].getYpos());
		assertThat(inventoryInfoDao->getCount(), 19 - i);
	}

	for (int i = 10; i < 20; i++)
	{
		inventoryInfoDao->deleteInventoryInfo("gkf1234", item[i].getXpos(), item[i].getYpos());
		assertThat(inventoryInfoDao->getCount(), 10);
	}
}