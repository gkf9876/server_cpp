#include "UserServiceTest.h"

UserServiceTest::UserServiceTest()
{
	this->user1 = new User();
	user1->setSock(1);
	user1->setName("GKF1234");
	user1->setPassword("1234");
	user1->setXpos(10);
	user1->setYpos(12);
	user1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");
	user1->setSeeDirection(29);
	user1->setAction(ACTION_MAP_IN);
	user1->setLogin(1);
	user1->setLastLogin("2018-03-17 00:42:57");
	user1->setLastLogout("2018-03-17 00:43:00");
	user1->setJoinDate("2018-01-01 00:00:00");

	this->user2 = new User();
	user2->setSock(2);
	user2->setName("GKF5678");
	user2->setPassword("5678");
	user2->setXpos(27);
	user2->setYpos(4);
	user2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");
	user2->setSeeDirection(29);
	user2->setAction(ACTION_MAP_IN);
	user2->setLogin(1);
	user2->setLastLogin("2018-03-17 10:42:57");
	user2->setLastLogout("2018-03-17 10:43:00");
	user2->setJoinDate("2018-01-01 10:00:00");

	this->user3 = new User();
	user3->setSock(3);
	user3->setName("GKF9012");
	user3->setPassword("9012");
	user3->setXpos(37);
	user3->setYpos(3);
	user3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
	user3->setSeeDirection(29);
	user3->setAction(ACTION_MAP_IN);
	user3->setLogin(1);
	user3->setLastLogin("2018-03-17 00:42:57");
	user3->setLastLogout("2018-03-17 00:43:00");
	user3->setJoinDate("2018-01-01 00:00:00");

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

UserServiceTest::~UserServiceTest()
{
	delete this->user1;
	delete this->user2;
	delete this->user3;
}

void UserServiceTest::setApplicationContext(ApplicationContext* context)
{
	userService = context->userService();
	userDao = context->userDao();
	inventoryInfoDao = context->inventoryInfoDao();
}

void UserServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void UserServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void UserServiceTest::checkSameUser(User user1, User user2)
{
	assertThat(user1.getSock(), user2.getSock());
	assertThat(user1.getName(), user2.getName());
	assertThat(user1.getPassword(), user2.getPassword());
	assertThat(user1.getXpos(), user2.getXpos());
	assertThat(user1.getYpos(), user2.getYpos());
	assertThat(user1.getField(), user2.getField());
	assertThat(user1.getSeeDirection(), user2.getSeeDirection());
	assertThat(user1.getAction(), user2.getAction());
	assertThat(user1.getLogin(), user2.getLogin());
}

void UserServiceTest::checkSameInventoryInfo(InventoryInfo inventoryInfo1, InventoryInfo inventoryInfo2)
{
	assertThat(inventoryInfo1.getItemName(), inventoryInfo2.getItemName());
	assertThat(inventoryInfo1.getUserName(), inventoryInfo2.getUserName());
	assertThat(inventoryInfo1.getType(), inventoryInfo2.getType());
	assertThat(inventoryInfo1.getXpos(), inventoryInfo2.getXpos());
	assertThat(inventoryInfo1.getYpos(), inventoryInfo2.getYpos());
	assertThat(inventoryInfo1.getFileDir(), inventoryInfo2.getFileDir());
	assertThat(inventoryInfo1.getCount(), inventoryInfo2.getCount());
}

void UserServiceTest::run()
{
	try
	{
		getUserInfo1();
		getUserInfo2();
		updateLogout();
		updateLogin();
		getLoginUserAll();
		getFieldLoginUserAll();
		getUserInventoryInfo();
		updateUserInfo();
		deleteInventoryItem();
		insertUserInfo();
		moveInventoryItem();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void UserServiceTest::getUserInfo1()
{
	std::cout << "UserServiceTest : getUserInfo1()" << std::endl;

	userDao->deleteAll();
	userDao->add(*user1);
	userDao->add(*user2);
	userDao->add(*user3);

	User getUser1 = userService->getUserInfo(user1->getName());
	checkSameUser(getUser1, *user1);
	User getUser2 = userService->getUserInfo(user2->getName());
	checkSameUser(getUser2, *user2);
	User getUser3 = userService->getUserInfo(user3->getName());
	checkSameUser(getUser3, *user3);
}

void UserServiceTest::getUserInfo2()
{
	std::cout << "UserServiceTest : getUserInfo2()" << std::endl;

	userDao->deleteAll();
	userDao->add(*user1);
	userDao->add(*user2);
	userDao->add(*user3);

	User getUser1 = userService->getUserInfo(user1->getSock());
	checkSameUser(getUser1, *user1);
	User getUser2 = userService->getUserInfo(user2->getSock());
	checkSameUser(getUser2, *user2);
	User getUser3 = userService->getUserInfo(user3->getSock());
	checkSameUser(getUser3, *user3);
}

void UserServiceTest::updateLogout()
{
	std::cout << "UserServiceTest : updateLogout()" << std::endl;

	userDao->deleteAll();
	userDao->add(*user1);
	userDao->add(*user2);
	userDao->add(*user3);

	userService->updateLogout(user1->getName());
	user1->setLogin(0);
	user1->setSock(0);
	userService->updateLogout(user3->getName());
	user3->setLogin(0);
	user3->setSock(0);

	User user1Update = userService->getUserInfo(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userService->getUserInfo(user2->getName());
	checkSameUser(user2Update, *user2);
	User user3Update = userService->getUserInfo(user3->getName());
	checkSameUser(user3Update, *user3);
}

void UserServiceTest::updateLogin()
{
	std::cout << "UserServiceTest : updateLogin()" << std::endl;

	userDao->deleteAll();

	user1->setLogin(0);
	userDao->add(*user1);
	user1->setLogin(1);

	userDao->add(*user2);

	user3->setLogin(0);
	userDao->add(*user3);
	user3->setLogin(1);

	userService->updateLogin(user1->getSock(), user1->getName());
	userService->updateLogin(user3->getSock(), user3->getName());

	User user1Update = userService->getUserInfo(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userService->getUserInfo(user2->getName());
	checkSameUser(user2Update, *user2);
	User user3Update = userService->getUserInfo(user3->getName());
	checkSameUser(user3Update, *user3);
}

void UserServiceTest::getLoginUserAll()
{
	std::cout << "UserServiceTest : getLoginUserAll()" << std::endl;

	userDao->deleteAll();

	user1->setLogin(1);
	userDao->add(*user1);

	user2->setLogin(1);
	userDao->add(*user2);

	user3->setLogin(1);
	userDao->add(*user3);

	list<User> loginUserList = userService->getLoginUserAll();
	list<User>::iterator iter;
	iter = loginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user2);

	iter++;
	checkSameUser(*iter, *user3);

	user2->setLogin(0);
	userService->updateLogout(user2->getName());

	loginUserList = userService->getLoginUserAll();
	iter = loginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user3);
}

void UserServiceTest::getFieldLoginUserAll()
{
	std::cout << "UserServiceTest : getFieldLoginUserAll()" << std::endl;

	userDao->deleteAll();
	assertThat(userService->getUserCount(user1->getField()), 0);

	user1->setLogin(1);
	userDao->add(*user1);
	assertThat(userService->getUserCount(user1->getField()), 1);

	user2->setLogin(1);
	user2->setField(user1->getField());
	userDao->add(*user2);
	assertThat(userService->getUserCount(user1->getField()), 2);

	user3->setLogin(1);
	user3->setField(user1->getField());
	userDao->add(*user3);
	assertThat(userService->getUserCount(user1->getField()), 3);

	list<User> fieldLoginUserList = userService->getFieldLoginUserAll(user1->getField());
	list<User>::iterator iter;
	iter = fieldLoginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user2);

	iter++;
	checkSameUser(*iter, *user3);

	user2->setLogin(0);
	user2->setField("abc");
	userService->updateLogout(user2->getName());

	fieldLoginUserList = userService->getFieldLoginUserAll(user1->getField());
	iter = fieldLoginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user3);
}

void UserServiceTest::getUserInventoryInfo()
{
	std::cout << "UserServiceTest : getUserInventoryInfo()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);
	assertThat(inventoryInfoDao->getUserInventoryList("gkf1234").size(), 0);

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

void UserServiceTest::updateUserInfo()
{
	std::cout << "UserServiceTest : updateUserInfo()" << std::endl;

	userDao->deleteAll();
	userDao->add(*user1);
	userDao->add(*user2);

	user1->setSock(5);
	user1->setPassword("12345");
	user1->setXpos(105);
	user1->setYpos(125);
	user1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx15");
	user1->setSeeDirection(295);
	user1->setAction(ACTION_MAP_IN);
	user1->setLogin(1);
	user1->setLastLogin("2018-03-17 00:42:55");
	user1->setLastLogout("2018-03-17 00:43:05");
	user1->setJoinDate("2018-01-01 00:00:05");

	userService->updateUserInfo(*user1);

	User user1Update = userDao->get(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userDao->get(user2->getName());
	checkSameUser(user2Update, *user2);
}

void UserServiceTest::deleteInventoryItem()
{
	std::cout << "UserServiceTest : deleteInventoryItem()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);

	for (int i = 0; i < 20; i++)
	{
		userService->addInventoryItem(item[i]);
		assertThat(inventoryInfoDao->getCount(), i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		userService->deleteInventoryItem("gkf1234", item[i].getXpos(), item[i].getYpos());
		assertThat(inventoryInfoDao->getCount(), 19 - i);
	}

	for (int i = 10; i < 20; i++)
	{
		userService->deleteInventoryItem("gkf1234", item[i].getXpos(), item[i].getYpos());
		assertThat(inventoryInfoDao->getCount(), 10);
	}
}

void UserServiceTest::insertUserInfo()
{
	std::cout << "UserServiceTest : insertUserInfo()" << std::endl;

	userDao->deleteAll();
	assertThat(userDao->getAllUser().size(), 0);

	assertThat(userService->insertUserInfo(*user1), true);
	assertThat(userDao->getAllUser().size(), 1);
	checkSameUser(userService->getUserInfo(user1->getName()), *user1);

	assertThat(userService->insertUserInfo(*user2), true);
	assertThat(userDao->getAllUser().size(), 2);
	checkSameUser(userService->getUserInfo(user2->getName()), *user2);

	assertThat(userService->insertUserInfo(*user1), false);
	assertThat(userDao->getAllUser().size(), 2);
	checkSameUser(userService->getUserInfo(user1->getName()), *user1);

	assertThat(userService->insertUserInfo(*user2), false);
	assertThat(userDao->getAllUser().size(), 2);
	checkSameUser(userService->getUserInfo(user2->getName()), *user2);
}

void UserServiceTest::moveInventoryItem()
{
	std::cout << "UserServiceTest : moveInventoryItem()" << std::endl;

	inventoryInfoDao->deleteAll();
	assertThat(inventoryInfoDao->getCount(), 0);
	assertThat(inventoryInfoDao->getUserInventoryList("gkf1234").size(), 0);

	for (int i = 0; i < 20; i++)
	{
		inventoryInfoDao->add(item[i]);
		assertThat(inventoryInfoDao->getCount(), i + 1);
	}

	item[7].setXpos(100);
	item[7].setYpos(200);
	userService->moveInventoryItem(item[7], 100, 200);

	item[8].setXpos(200);
	item[8].setYpos(400);
	userService->moveInventoryItem(item[8], 200, 400);

	item[9].setXpos(400);
	item[9].setYpos(800);
	userService->moveInventoryItem(item[9], 400, 800);

	list<InventoryInfo> inventoryList = inventoryInfoDao->getUserInventoryList("gkf1234");
	list<InventoryInfo>::iterator iter;
	iter = inventoryList.begin();

	for (int i = 0; i < 10; i++)
	{
		checkSameInventoryInfo(*iter, item[i]);
		iter++;
	}
}