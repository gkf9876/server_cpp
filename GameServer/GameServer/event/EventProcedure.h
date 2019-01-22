#ifndef  _EVENT_PROCEDURE_H_
#define  _EVENT_PROCEDURE_H_

#include <iostream>
#include <vector>

#if defined(_WIN32)
#include <io.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <sys/types.h>
#include <dirent.h>
#endif

#include "../util/cJSON.h"
#include "../util/Util.h"

#include "EventSequence.h"

using namespace std;

class  EventProcedure
{
private:
	Util util;
	vector<EventSequence*> eventList;
	EventSequence* progressEvent = NULL;

	//이벤트 진행 번호
	int procede = 0;

	//이벤트의 대사 음절 진행번호
	int syllableCount = 0;

	//이벤트의 대사가 스토리 대화창을 넘어가면 잘라서 표시해주기 위한 기준값
	int flagSyllableCount = 0;

	bool isRun = false;
public:
	EventProcedure();
	~EventProcedure();

	EventSequence * getEventSequence(int idx);

	bool isSatisfyConditionObject(User user);

	string getPlayingSpeech(float contentSize, float stringHeight);
	void skipPlayingSpeech();

	EventSequence * getProgressEventSequence();

	void setProgress(const char * name, bool value);
};

#endif

