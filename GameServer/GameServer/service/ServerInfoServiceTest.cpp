#include "ServerInfoServiceTest.h"

ServerInfoServiceTest::ServerInfoServiceTest()
{
}

ServerInfoServiceTest::~ServerInfoServiceTest()
{
}

void ServerInfoServiceTest::setApplicationContext(ApplicationContext* context)
{
	serverInfoService = context->serverInfoService();
}

void ServerInfoServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void ServerInfoServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void ServerInfoServiceTest::checkSameServerInfo(ServerInfo serverInfo1, ServerInfo serverInfo2)
{
	assertThat(serverInfo1.getIdx(), serverInfo2.getIdx());
	assertThat(serverInfo1.getInputdate(), serverInfo2.getInputdate());
}

void ServerInfoServiceTest::run()
{
	try
	{
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}