#include "ChattingDaoTest.h"

ChattingDaoTest::ChattingDaoTest()
{
	this->dataSource = new DataSource("127.0.0.1", "gkf9876", "9109382616@", "test");
	this->chattingDao = new ChattingDao(this->dataSource);

	this->chat1 = new Chatting();
	chat1->setIdx(1);
	chat1->setInputdate("2018-03-17 00:42:57");
	chat1->setName("홍길동");
	chat1->setContent("안녕하세요.");
	chat1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");

	this->chat2 = new Chatting();
	chat2->setIdx(2);
	chat2->setInputdate("2018-03-17 10:42:57");
	chat2->setName("GKF5678");
	chat2->setContent("Hello~");
	chat2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");

	this->chat3 = new Chatting();
	chat3->setIdx(3);
	chat3->setInputdate("2018-03-17 20:42:57");
	chat3->setName("GKF9012");
	chat3->setContent("안녕하세요. 여러분");
	chat3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
}

ChattingDaoTest::~ChattingDaoTest()
{
	delete dataSource;
	delete chattingDao;
	delete chat1;
	delete chat2;
	delete chat3;
}

void ChattingDaoTest::run()
{
	try
	{
		addAndGet();
		getFieldChatting();
		getUserFieldChatting();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void ChattingDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void ChattingDaoTest::assertThat(const char* value, const char* compValue)
{
	if (strcmp(value, compValue))
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void ChattingDaoTest::checkSameChat(Chatting chat1, Chatting chat2)
{
	assertThat(chat1.getName(), chat2.getName());
	assertThat(chat1.getContent(), chat2.getContent());
	assertThat(chat1.getField(), chat2.getField());
}

void ChattingDaoTest::addAndGet()
{
	std::cout << "ChattingDaoTest : addAndGet()" << std::endl;

	chattingDao->deleteAll();
	assertThat(chattingDao->getCount(), 0);

	chattingDao->add(*chat1);
	chattingDao->add(*chat2);
	assertThat(chattingDao->getCount(), 2);

	Chatting chatget1 = chattingDao->get(chat1->getIdx());
	checkSameChat(chatget1, *chat1);

	Chatting chatget2 = chattingDao->get(chat2->getIdx());
	checkSameChat(chatget2, *chat2);
}

void ChattingDaoTest::getFieldChatting()
{
	std::cout << "ChattingDaoTest : getFieldChatting()" << std::endl;

	chattingDao->deleteAll();
	assertThat(chattingDao->getCount(), 0);

	chattingDao->add(*chat1);
	assertThat(chattingDao->getCount(), 1);

	chat2->setField(chat1->getField());
	chattingDao->add(*chat2);
	assertThat(chattingDao->getCount(), 2);

	chat3->setField(chat1->getField());
	chattingDao->add(*chat3);
	assertThat(chattingDao->getCount(), 3);

	chattingDao->add(*chat2);
	assertThat(chattingDao->getCount(), 4);

	list<Chatting> fieldLoginUserList = chattingDao->getFieldChatting(chat1->getField());
	list<Chatting>::iterator iter;
	iter = fieldLoginUserList.begin();
	checkSameChat(*iter, *chat1);

	iter++;
	checkSameChat(*iter, *chat2);

	iter++;
	checkSameChat(*iter, *chat3);
}

void ChattingDaoTest::getUserFieldChatting()
{
	std::cout << "ChattingDaoTest : getUserFieldChatting()" << std::endl;

	chattingDao->deleteAll();
	assertThat(chattingDao->getCount(), 0);

	chat1->setContent("안녕하십니까.");
	chattingDao->add(*chat1);
	assertThat(chattingDao->getCount(), 1);

	chat1->setContent("Hello World1");
	chattingDao->add(*chat1);
	assertThat(chattingDao->getCount(), 2);

	chat1->setContent("안녕하세요.");
	chattingDao->add(*chat1);
	assertThat(chattingDao->getCount(), 3);

	chat2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");
	chattingDao->add(*chat2);
	assertThat(chattingDao->getCount(), 4);

	chat3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
	chattingDao->add(*chat3);
	assertThat(chattingDao->getCount(), 5);

	list<Chatting> fieldLoginUserList = chattingDao->getFieldChatting(chat1->getField());
	list<Chatting>::iterator iter;
	iter = fieldLoginUserList.begin();

	chat1->setContent("안녕하십니까.");
	checkSameChat(*iter, *chat1);

	iter++;
	chat1->setContent("Hello World1");
	checkSameChat(*iter, *chat1);

	iter++;
	chat1->setContent("안녕하세요.");
	checkSameChat(*iter, *chat1);
}