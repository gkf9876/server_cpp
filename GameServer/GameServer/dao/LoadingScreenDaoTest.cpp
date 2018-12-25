#include "LoadingScreenDaoTest.h"

LoadingScreenDaoTest::LoadingScreenDaoTest()
{
	this->loadingScreen1 = new LoadingScreen();
	loadingScreen1->setIdx(1);
	loadingScreen1->setName("GKF1234");
	loadingScreen1->setFilePath("1234");

	this->loadingScreen2 = new LoadingScreen();
	loadingScreen2->setIdx(2);
	loadingScreen2->setName("GKF5678");
	loadingScreen2->setFilePath("5678");

	this->loadingScreen3 = new LoadingScreen();
	loadingScreen3->setIdx(3);
	loadingScreen3->setName("GKF9012");
	loadingScreen3->setFilePath("9012");
}

LoadingScreenDaoTest::~LoadingScreenDaoTest()
{
	delete loadingScreen1;
	delete loadingScreen2;
	delete loadingScreen3;
}

void LoadingScreenDaoTest::setApplicationContext(ApplicationContext* context)
{
	this->loadingScreenDao = context->loadingScreenDao();
}

void LoadingScreenDaoTest::run()
{
	try
	{
		addAndGet1();
		addAndGet2();
		getLoadingScreenFailure();
		duplciateKey();
		update();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void LoadingScreenDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void LoadingScreenDaoTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void LoadingScreenDaoTest::checkSameLoadingScreen(LoadingScreen loadingScreen1, LoadingScreen loadingScreen2)
{
	assertThat(loadingScreen1.getName(), loadingScreen2.getName());
	assertThat(loadingScreen1.getFilePath(), loadingScreen2.getFilePath());
}

void LoadingScreenDaoTest::addAndGet1()
{
	std::cout << "LoadingScreenDaoTest : addAndGet1()" << std::endl;

	loadingScreenDao->deleteAll();
	loadingScreenDao->setIdxAutoIncrement(0);
	assertThat(loadingScreenDao->getCount(), 0);

	loadingScreenDao->add(*loadingScreen1);
	loadingScreenDao->add(*loadingScreen2);
	assertThat(loadingScreenDao->getCount(), 2);

	LoadingScreen LoadingScreenget1 = loadingScreenDao->get(loadingScreen1->getIdx());
	checkSameLoadingScreen(LoadingScreenget1, *loadingScreen1);

	LoadingScreen LoadingScreenget2 = loadingScreenDao->get(loadingScreen2->getIdx());
	checkSameLoadingScreen(LoadingScreenget2, *loadingScreen2);
}

void LoadingScreenDaoTest::addAndGet2()
{
	std::cout << "LoadingScreenDaoTest : addAndGet2()" << std::endl;

	loadingScreenDao->deleteAll();
	loadingScreenDao->setIdxAutoIncrement(0);
	assertThat(loadingScreenDao->getCount(), 0);

	loadingScreenDao->add(*loadingScreen1);
	loadingScreenDao->add(*loadingScreen2);
	assertThat(loadingScreenDao->getCount(), 2);

	LoadingScreen LoadingScreenget1 = loadingScreenDao->get(loadingScreen1->getIdx());
	checkSameLoadingScreen(LoadingScreenget1, *loadingScreen1);

	LoadingScreen LoadingScreenget2 = loadingScreenDao->get(loadingScreen2->getIdx());
	checkSameLoadingScreen(LoadingScreenget2, *loadingScreen2);
}

void LoadingScreenDaoTest::getLoadingScreenFailure()
{
	std::cout << "LoadingScreenDaoTest : getLoadingScreenFailure()" << std::endl;

	loadingScreenDao->deleteAll();
	assertThat(loadingScreenDao->getCount(), 0);

	try
	{
		LoadingScreen LoadingScreenget = loadingScreenDao->get(0);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void LoadingScreenDaoTest::duplciateKey()
{
	std::cout << "LoadingScreenDaoTest : duplciateKey()" << std::endl;

	loadingScreenDao->deleteAll();
	loadingScreenDao->setIdxAutoIncrement(0);

	try
	{
		loadingScreenDao->add(*loadingScreen1);
		loadingScreenDao->add(*loadingScreen1);
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void LoadingScreenDaoTest::update()
{
	std::cout << "LoadingScreenDaoTest : update()" << std::endl;

	loadingScreenDao->deleteAll();
	loadingScreenDao->setIdxAutoIncrement(0);
	loadingScreenDao->add(*loadingScreen1);
	loadingScreenDao->add(*loadingScreen2);

	loadingScreen1->setName("12345");
	loadingScreen1->setFilePath("105");

	loadingScreenDao->update(*loadingScreen1);

	LoadingScreen loadingScreen1Update = loadingScreenDao->get(loadingScreen1->getIdx());
	checkSameLoadingScreen(loadingScreen1Update, *loadingScreen1);
	LoadingScreen loadingScreen2Update = loadingScreenDao->get(loadingScreen2->getIdx());
	checkSameLoadingScreen(loadingScreen2Update, *loadingScreen2);
}
