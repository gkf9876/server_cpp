#include "ChattingServiceTest.h"

ChattingServiceTest::ChattingServiceTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->chattingService = new ChattingService(this->dataSource);
	this->chattingDao = new ChattingDao(this->dataSource);

	this->chatting1 = new Chatting();
	chatting1->setIdx(1);
	chatting1->setInputdate("2018-03-17 00:42:57");
	chatting1->setName("GKF1234");
	chatting1->setContent("¾È³çÇÏ¼¼¿ä ~ !");
	chatting1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");

	this->chatting2 = new Chatting();
	chatting2->setIdx(2);
	chatting2->setInputdate("2018-03-17 10:42:57");
	chatting2->setName("GKF9876");
	chatting2->setContent("¾È³çÇÏ¼¼¿ä ~ ! 123");
	chatting2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");

	this->chatting3 = new Chatting();
	chatting3->setIdx(3);
	chatting3->setInputdate("2018-03-17 20:42:57");
	chatting3->setName("GKF9797");
	chatting3->setContent("¾È³çÇÏ¼¼¿ä ~ ! 456");
	chatting3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
}

ChattingServiceTest::~ChattingServiceTest()
{
	delete this->dataSource;
	delete this->chattingService;
	delete this->chattingDao;

	delete this->chatting1;
	delete this->chatting2;
	delete this->chatting3;
}

void ChattingServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void ChattingServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void ChattingServiceTest::checkSameChatting(Chatting chatting1, Chatting chatting2)
{
	assertThat(chatting1.getName(), chatting2.getName());
	assertThat(chatting1.getContent(), chatting2.getContent());
	assertThat(chatting1.getField(), chatting2.getField());
}

void ChattingServiceTest::run()
{
	addAndGet();
}

void ChattingServiceTest::addAndGet()
{
	std::cout << "ChattingServiceTest : addAndGet()" << std::endl;
	chattingDao->deleteAll();
	assertThat(chattingDao->getCount(), 0);

	chattingDao->add(*chatting1);
	chattingDao->add(*chatting2);
	assertThat(chattingDao->getCount(), 2);

	Chatting chattingget1 = chattingDao->get(chatting1->getIdx());
	checkSameChatting(chattingget1, *chatting1);

	Chatting chattingget2 = chattingDao->get(chatting2->getIdx());
	checkSameChatting(chattingget2, *chatting2);
}