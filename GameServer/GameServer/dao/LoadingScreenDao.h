#ifndef __LOADING_SCREEN_DAO_H_
#define __LOADING_SCREEN_DAO_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <list>
#include "../datasource/DataSource.h"
#include "../domain/LoadingScreen.h"

using namespace std;

class LoadingScreenDao
{
private:
	DataSource* dataSource;
public:
	LoadingScreenDao();
	~LoadingScreenDao();
	void setDataSource(DataSource* dataSource);

	void setIdxAutoIncrement(int value);
	void add(LoadingScreen loadingScreen);
	void update(LoadingScreen loadingScreen);
	void deleteAll();
	int getCount();
	LoadingScreen get(int idx);

	void showLog(char* qurey);
};

#endif
