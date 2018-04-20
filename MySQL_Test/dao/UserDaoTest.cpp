#include "UserDaoTest.h"

UserDaoTest::UserDaoTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->userDao = new UserDao(this->dataSource);

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
}

UserDaoTest::~UserDaoTest()
{
	delete dataSource;
	delete userDao;
	delete user1;
	delete user2;
	delete user3;
}

void UserDaoTest::run()
{
	try
	{
		addAndGet1();
		addAndGet2();
		getUserFailure();
		duplciateKey();
		update();
		getUserInfo();
		updateLogout();
		updateLogin();
		getLoginUserAll();
		getFieldLoginUserAll();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void UserDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void UserDaoTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void UserDaoTest::checkSameUser(User user1, User user2)
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
	assertThat(user1.getLastLogin(), user2.getLastLogin());
	assertThat(user1.getLastLogout(), user2.getLastLogout());
	assertThat(user1.getJoinDate(), user2.getJoinDate());
}

void UserDaoTest::addAndGet1()
{
	std::cout << "UserDaoTest : addAndGet1()" << std::endl;

	userDao->deleteAll();
	assertThat(userDao->getCount(), 0);

	userDao->add(*user1);
	userDao->add(*user2);
	assertThat(userDao->getCount(), 2);

	User userget1 = userDao->get(user1->getName());
	checkSameUser(userget1, *user1);

	User userget2 = userDao->get(user2->getName());
	checkSameUser(userget2, *user2);
}

void UserDaoTest::addAndGet2()
{
	std::cout << "UserDaoTest : addAndGet2()" << std::endl;

	userDao->deleteAll();
	assertThat(userDao->getCount(), 0);

	userDao->add(*user1);
	userDao->add(*user2);
	assertThat(userDao->getCount(), 2);

	User userget1 = userDao->get(user1->getSock());
	checkSameUser(userget1, *user1);

	User userget2 = userDao->get(user2->getSock());
	checkSameUser(userget2, *user2);
}

void UserDaoTest::getUserFailure()
{
	std::cout << "UserDaoTest : getUserFailure()" << std::endl;

	userDao->deleteAll();
	assertThat(userDao->getCount(), 0);

	try
	{
		User userget = userDao->get("unknown_id");
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void UserDaoTest::duplciateKey()
{
	std::cout << "UserDaoTest : duplciateKey()" << std::endl;

	userDao->deleteAll();

	try
	{
		userDao->add(*user1);
		userDao->add(*user1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void UserDaoTest::update()
{
	std::cout << "UserDaoTest : update()" << std::endl;

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

	userDao->update(*user1);

	User user1Update = userDao->get(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userDao->get(user2->getName());
	checkSameUser(user2Update, *user2);
}

void UserDaoTest::getUserInfo()
{
	std::cout << "UserDaoTest : getUserInfo()" << std::endl;

	try
	{
		userDao->deleteAll();
		userDao->add(*user1);
		userDao->add(*user2);

		user1->setSock(15);

		User user1Update = userDao->get(user1->getSock());
		checkSameUser(user1Update, *user1);
		User user2Update = userDao->get(user2->getSock());
		checkSameUser(user2Update, *user2);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void UserDaoTest::updateLogout()
{
	std::cout << "UserDaoTest : updateLogout()" << std::endl;

	userDao->deleteAll();
	userDao->add(*user1);
	userDao->add(*user2);
	userDao->add(*user3);

	userDao->updateLogout(user1->getName());
	user1->setLogin(0);
	user1->setSock(0);
	userDao->updateLogout(user3->getName());
	user3->setLogin(0);
	user3->setSock(0);

	User user1Update = userDao->get(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userDao->get(user2->getName());
	checkSameUser(user2Update, *user2);
	User user3Update = userDao->get(user3->getName());
	checkSameUser(user3Update, *user3);
}

void UserDaoTest::updateLogin()
{
	std::cout << "UserDaoTest : updateLogin()" << std::endl;

	userDao->deleteAll();

	user1->setLogin(0);
	userDao->add(*user1);
	user1->setLogin(1);

	userDao->add(*user2);

	user3->setLogin(0);
	userDao->add(*user3);
	user3->setLogin(1);

	userDao->updateLogin(user1->getSock(), user1->getName());
	userDao->updateLogin(user3->getSock(), user3->getName());

	User user1Update = userDao->get(user1->getName());
	checkSameUser(user1Update, *user1);
	User user2Update = userDao->get(user2->getName());
	checkSameUser(user2Update, *user2);
	User user3Update = userDao->get(user3->getName());
	checkSameUser(user3Update, *user3);
}

void UserDaoTest::getLoginUserAll()
{
	std::cout << "UserDaoTest : getLoginUserAll()" << std::endl;

	userDao->deleteAll();

	user1->setLogin(1);
	userDao->add(*user1);

	user2->setLogin(1);
	userDao->add(*user2);

	user3->setLogin(1);
	userDao->add(*user3);

	list<User> loginUserList = userDao->getLoginUserAll();
	list<User>::iterator iter;
	iter = loginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user2);

	iter++;
	checkSameUser(*iter, *user3);

	user2->setLogin(0);
	userDao->updateLogout(user2->getName());

	loginUserList = userDao->getLoginUserAll();
	iter = loginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user3);
}

void UserDaoTest::getFieldLoginUserAll()
{
	std::cout << "UserDaoTest : getFieldLoginUserAll()" << std::endl;

	userDao->deleteAll();
	assertThat(userDao->getCount(user1->getField()), 0);

	user1->setLogin(1);
	userDao->add(*user1);
	assertThat(userDao->getCount(user1->getField()), 1);

	user2->setLogin(1);
	user2->setField(user1->getField());
	userDao->add(*user2);
	assertThat(userDao->getCount(user1->getField()), 2);

	user3->setLogin(1);
	user3->setField(user1->getField());
	userDao->add(*user3);
	assertThat(userDao->getCount(user1->getField()), 3);

	list<User> fieldLoginUserList = userDao->getFieldLoginUserAll(user1->getField());
	list<User>::iterator iter;
	iter = fieldLoginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user2);

	iter++;
	checkSameUser(*iter, *user3);

	user2->setLogin(0);
	user2->setField("abc");
	userDao->updateLogout(user2->getName());

	fieldLoginUserList = userDao->getFieldLoginUserAll(user1->getField());
	iter = fieldLoginUserList.begin();
	checkSameUser(*iter, *user1);

	iter++;
	checkSameUser(*iter, *user3);
}