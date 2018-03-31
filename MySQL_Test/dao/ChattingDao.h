#ifndef __CHATTING_DAO_H_
#define __CHATTING_DAO_H_

#include <iostream>
#include <sstream>
#include <stdio.h>
#include "../datasource/DataSource.h"
#include "../domain/Chatting.h"

using namespace std;

class ChattingDao
{
private:
	DataSource* dataSource;
public:
	ChattingDao(DataSource* dataSource);
	~ChattingDao();

	void add(Chatting chatting);
	void deleteAll();
	void initAutoIncrement();
	int getCount();
	Chatting get(int idx);
};

#endif
