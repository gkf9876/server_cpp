#ifndef __LOADING_SCREEN_SERVICE_TEST_H_
#define __LOADING_SCREEN_SERVICE_TEST_H_

#include <iostream>
#include "LoadingScreenService.h"
#include "../datasource/DataSource.h"
#include "../factory/ApplicationContext.h"

class LoadingScreenServiceTest
{
private:
	LoadingScreenService* loadingScreenService;
	LoadingScreenDao* loadingScreenDao;
public:
	LoadingScreenServiceTest();
	~LoadingScreenServiceTest();
	void setApplicationContext(ApplicationContext* context);

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameLoadingScreen(LoadingScreen loadingScreen1, LoadingScreen loadingScreen2);
	void run();
};

#endif