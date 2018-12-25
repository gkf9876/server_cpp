#include "LoadingScreenServiceTest.h"

LoadingScreenServiceTest::LoadingScreenServiceTest()
{
}

LoadingScreenServiceTest::~LoadingScreenServiceTest()
{
}

void LoadingScreenServiceTest::setApplicationContext(ApplicationContext* context)
{
	loadingScreenService = context->loadingScreenService();
	loadingScreenDao = context->loadingScreenDao();
}

void LoadingScreenServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void LoadingScreenServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void LoadingScreenServiceTest::checkSameLoadingScreen(LoadingScreen loadingScreen1, LoadingScreen loadingScreen2)
{
	assertThat(loadingScreen1.getName(), loadingScreen2.getName());
	assertThat(loadingScreen1.getFilePath(), loadingScreen2.getFilePath());
}

void LoadingScreenServiceTest::run()
{
	try
	{
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}
