#ifndef __LOADING_SCREEN_DAO_TEST_H_
#define __LOADING_SCREEN_DAO_TEST_H_

#include<iostream>
#include "LoadingScreenDao.h"
#include "../factory/ApplicationContext.h"

using namespace std;

class LoadingScreenDaoTest
{
private:
	LoadingScreenDao * loadingScreenDao;

	LoadingScreen * loadingScreen1;
	LoadingScreen * loadingScreen2;
	LoadingScreen * loadingScreen3;
public:
	LoadingScreenDaoTest();
	~LoadingScreenDaoTest();
	void setApplicationContext(ApplicationContext* context);
	void run();

	void assertThat(int value, int compValue);
	void assertThat(string value, string compValue);
	void checkSameLoadingScreen(LoadingScreen loadingScreen1, LoadingScreen loadingScreen2);

	void addAndGet();
	void getLoadingScreenFailure();
	void duplciateKey();
	void update();
};

#endif