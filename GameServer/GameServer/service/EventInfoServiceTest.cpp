#include "EventInfoServiceTest.h"

EventInfoServiceTest::EventInfoServiceTest()
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
}

EventInfoServiceTest::~EventInfoServiceTest()
{
	delete this->eventInfo1;
	delete this->eventInfo2;
	delete this->eventInfo3;
}

void EventInfoServiceTest::setApplicationContext(ApplicationContext* context)
{
	eventInfoService = context->eventInfoService();
	eventInfoDao = context->eventInfoDao();
}

void EventInfoServiceTest::assertThat(int value, int compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void EventInfoServiceTest::assertThat(bool value, bool compValue)
{
	if (value != compValue)
		std::cout << "\tExpected is: <" << compValue << "> but: was <" << value << ">" << std::endl;
}

void EventInfoServiceTest::assertThat(string value, string compValue)
{
	if (value.compare(compValue) != 0)
		std::cout << "\tExpected is: <" << compValue.c_str() << "> but: was <" << value.c_str() << ">" << std::endl;
}

void EventInfoServiceTest::checkSameEventInfo(EventInfo eventInfo1, EventInfo eventInfo2)
{
	assertThat(eventInfo1.getName(), eventInfo2.getName());
	assertThat(eventInfo1.getContent(), eventInfo2.getContent());
	assertThat(eventInfo1.getField(), eventInfo2.getField());
	assertThat(eventInfo1.getXpos(), eventInfo2.getXpos());
	assertThat(eventInfo1.getYpos(), eventInfo2.getYpos());
}

void EventInfoServiceTest::run()
{
	try
	{
		isRunEvent();
	}
	catch (const runtime_error& error)
	{
		std::cout << '\t' << error.what() << std::endl;
	}
}

void EventInfoServiceTest::isRunEvent()
{
	std::cout << "EventInfoServiceTest : isRunEvent()" << std::endl;

	eventInfoDao->deleteAll();
	assertThat(eventInfoDao->getCount(), 0);

	eventInfoService->addRunEvent(*eventInfo1);
	assertThat(eventInfoDao->getCount(eventInfo1->getName(), eventInfo1->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 1);
	assertThat(eventInfoService->isRunEvent(eventInfo1->getName(), eventInfo1->getContent()), true);

	eventInfoService->addRunEvent(*eventInfo2);
	assertThat(eventInfoDao->getCount(eventInfo2->getName(), eventInfo2->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 2);
	assertThat(eventInfoService->isRunEvent(eventInfo1->getName(), eventInfo1->getContent()), true);

	eventInfoService->addRunEvent(*eventInfo3);
	assertThat(eventInfoDao->getCount(eventInfo3->getName(), eventInfo3->getContent()), 1);
	assertThat(eventInfoDao->getCount(), 3);
	assertThat(eventInfoService->isRunEvent(eventInfo1->getName(), eventInfo1->getContent()), true);
}