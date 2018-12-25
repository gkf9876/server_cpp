#ifndef __LOADING_SCREEN_SERVICE_H_
#define __LOADING_SCREEN_SERVICE_H_

#include <iostream>
#include <list>
#include "../dao/LoadingScreenDao.h"

using namespace std;

class LoadingScreenService
{
private:
	LoadingScreenDao* loadingScreenDao;
	DataSource* dataSource;
public:
	LoadingScreenService();
	~LoadingScreenService();
	void setLoadingScreenDao(LoadingScreenDao* loadingScreenDao);
};

#endif