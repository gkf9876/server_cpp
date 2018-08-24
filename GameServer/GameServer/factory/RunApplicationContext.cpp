#include "RunApplicationContext.h"

RunApplicationContext::RunApplicationContext()
	:ApplicationContext()
{
}

DataSource* RunApplicationContext::dataSource()
{
	if (this->dataSourceInstance != NULL)
		return this->dataSourceInstance;
	else
	{
		this->dataSourceInstance = new DataSource("127.0.0.1", "yona", "yonadan", "gameServer");
		return this->dataSourceInstance;
	}
}