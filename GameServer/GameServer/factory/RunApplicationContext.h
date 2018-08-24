#ifndef __RUN_APPLICATION_CONTEXT_H__
#define __RUN_APPLICATION_CONTEXT_H__

#include "ApplicationContext.h"

class RunApplicationContext : public ApplicationContext
{
public:
	RunApplicationContext();

	DataSource* dataSource();
};

#endif
