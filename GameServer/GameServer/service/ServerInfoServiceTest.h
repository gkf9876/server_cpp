#ifndef __SERVER_INFO_SERVICE_TEST_H_
#define __SERVER_INFO_SERVICE_TEST_H_

#include <iostream>
#include "ServerInfoService.h"
#include "../datasource/DataSource.h"
#include "../factory/ApplicationContext.h"

class ServerInfoServiceTest
{
private:
	ServerInfoService* serverInfoService;
public:
	ServerInfoServiceTest();
	~ServerInfoServiceTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameServerInfo(ServerInfo serverInfo1, ServerInfo serverInfo2);
	void run();
};

#endif