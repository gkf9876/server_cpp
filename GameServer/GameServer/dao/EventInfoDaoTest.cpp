#include "EventInfoDaoTest.h"

EventInfoDaoTest::EventInfoDaoTest()
{
	this->eventInfo1 = new EventInfo();
	eventInfo1->setName("abcd0");
	eventInfo1->setContent("/Story/NewsGisa1.json");
	eventInfo1->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1");
	eventInfo1->setXpos(1);
	eventInfo1->setYpos(2);

	this->eventInfo2 = new EventInfo();
	eventInfo2->setName("abcd1");
	eventInfo2->setContent("/Story/NewsGisa2.json");
	eventInfo2->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2");
	eventInfo2->setXpos(3);
	eventInfo2->setYpos(4);

	this->eventInfo3 = new EventInfo();
	eventInfo3->setName("abcd2");
	eventInfo3->setContent("/Story/NewsGisa3.json");
	eventInfo3->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3");
	eventInfo3->setXpos(5);
	eventInfo3->setYpos(6);

	this->eventInfo4 = new EventInfo();
	eventInfo4->setName("abcd0");
	eventInfo4->setContent("/Story/NewsGisa4.json");
	eventInfo4->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx11");
	eventInfo4->setXpos(11);
	eventInfo4->setYpos(21);

	this->eventInfo5 = new EventInfo();
	eventInfo5->setName("abcd0");
	eventInfo5->setContent("/Story/NewsGisa5.json");
	eventInfo5->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx12");
	eventInfo5->setXpos(12);
	eventInfo5->setYpos(22);

	this->eventInfo6 = new EventInfo();
	eventInfo6->setName("abcd0");
	eventInfo6->setContent("/Story/NewsGisa6.json");
	eventInfo6->setField("TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx13");
	eventInfo6->setXpos(13);
	eventInfo6->setYpos(23);
}

EventInfoDaoTest::~EventInfoDaoTest()
{
	delete eventInfo1;
	delete eventInfo2;
	delete eventInfo3;
	delete eventInfo4;
	delete eventInfo5;
	delete eventInfo6;
}

void EventInfoDaoTest::setApplicationContext(ApplicationContext* context)
{
	this->eventInfoDao = context->eventInfoDao();
}

void EventInfoDaoTest::run()
{
	try
	{
		addAndGet();
		getList();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void EventInfoDaoTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void EventInfoDaoTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void EventInfoDaoTest::checkSameEventInfo(EventInfo eventInfo1, EventInfo eventInfo2)
{
	assertThat(eventInfo1.getName(), eventInfo2.getName());
	assertThat(eventInfo1.getContent(), eventInfo2.getContent());
	assertThat(eventInfo1.getField(), eventInfo2.getField());
	assertThat(eventInfo1.getXpos(), eventInfo2.getXpos());
	assertThat(eventInfo1.getYpos(), eventInfo2.getYpos());
}

void EventInfoDaoTest::addAndGet()
{
	std::cout << "EventInfoDaoTest : addAndGet()" << std::endl;

	eventInfoDao->deleteAll();
	assertThat(eventInfoDao->getCount(), 0);

	eventInfoDao->add(*eventInfo1);
	assertThat(eventInfoDao->getCount(eventInfo1->getName(), eventInfo1->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 1);
	eventInfoDao->add(*eventInfo2);
	assertThat(eventInfoDao->getCount(eventInfo2->getName(), eventInfo2->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 2);
	eventInfoDao->add(*eventInfo3);
	assertThat(eventInfoDao->getCount(eventInfo3->getName(), eventInfo3->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 3);

	EventInfo eventInfoGet1 = eventInfoDao->get(eventInfo1->getName(), eventInfo1->getContent());
	checkSameEventInfo(eventInfoGet1, *eventInfo1);

	EventInfo eventInfoGet2 = eventInfoDao->get(eventInfo2->getName(), eventInfo2->getContent());
	checkSameEventInfo(eventInfoGet2, *eventInfo2);

	EventInfo eventInfoGet3 = eventInfoDao->get(eventInfo3->getName(), eventInfo3->getContent());
	checkSameEventInfo(eventInfoGet3, *eventInfo3);
}

void EventInfoDaoTest::getList()
{
	std::cout << "EventInfoDaoTest : getList()" << std::endl;

	eventInfoDao->deleteAll();
	assertThat(eventInfoDao->getCount(), 0);

	eventInfoDao->add(*eventInfo1);
	assertThat(eventInfoDao->getCount(eventInfo1->getName(), eventInfo1->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 1);
	eventInfoDao->add(*eventInfo2);
	assertThat(eventInfoDao->getCount(eventInfo2->getName(), eventInfo2->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 2);
	eventInfoDao->add(*eventInfo3);
	assertThat(eventInfoDao->getCount(eventInfo3->getName(), eventInfo3->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 3);
	eventInfoDao->add(*eventInfo4);
	assertThat(eventInfoDao->getCount(eventInfo4->getName(), eventInfo4->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 4);
	eventInfoDao->add(*eventInfo5);
	assertThat(eventInfoDao->getCount(eventInfo5->getName(), eventInfo5->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 5);
	eventInfoDao->add(*eventInfo6);
	assertThat(eventInfoDao->getCount(eventInfo6->getName(), eventInfo6->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 6);

	list<EventInfo> eventInfoList = eventInfoDao->getEventList(eventInfo1->getName());
	list<EventInfo>::iterator iter;
	iter = eventInfoList.begin();
	checkSameEventInfo(*iter, *eventInfo1);

	iter++;
	checkSameEventInfo(*iter, *eventInfo4);

	iter++;
	checkSameEventInfo(*iter, *eventInfo5);

	iter++;
	checkSameEventInfo(*iter, *eventInfo6);
}
