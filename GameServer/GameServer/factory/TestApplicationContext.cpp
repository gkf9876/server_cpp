#include "TestApplicationContext.h"

TestApplicationContext::TestApplicationContext()
	:ApplicationContext()
{
}

DataSource* TestApplicationContext::dataSource()
{
	if (this->dataSourceInstance != NULL)
		return this->dataSourceInstance;
	else
	{
		this->dataSourceInstance = new DataSource("127.0.0.1", "yona", "yonadan", "test");
		return this->dataSourceInstance;
	}
}