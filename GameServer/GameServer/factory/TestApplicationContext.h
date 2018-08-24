#ifndef __TEST_APPLICATION_CONTEXT_H__
#define __TEST_APPLICATION_CONTEXT_H__

#include "ApplicationContext.h"

class TestApplicationContext : public ApplicationContext
{
public:
	TestApplicationContext();

	DataSource* dataSource();
};

#endif