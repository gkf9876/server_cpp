#include "EventProcedure.h"

EventProcedure::EventProcedure()
{

	string path = "Story/*.json";

#if defined(_WIN32)

	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
		util.MyPrintDebug("No file in directory!\n");

#elif defined(__linux__) || defined(__APPLE__)

	DIR* dp = NULL;
	struct dirent* entry = NULL;

	if ((dp = opendir("Resources/Story")) == NULL)
	{
		printf("/Story를 열수 없습니다..\n");
		return;
	}
#endif

	do
	{
		//시나리오 불러오기.
		FILE *f; long len; char *data;
		int recvLen;
		char filePath[1024];

		cJSON *scenario = NULL;													//시나리오.

#if defined(_WIN32)
		sprintf(filePath, "Story/%s", fd.name);
#elif defined(__linux__) || defined(__APPLE__)
		sprintf(filePath, "Story/%s", entry->d_name);
#endif

		if ((f = fopen(filePath, "rb")) != NULL)
		{
			fseek(f, 0, SEEK_END);
			len = ftell(f);
			fseek(f, 0, SEEK_SET);

			data = (char*)malloc(len + 1);
			if ((recvLen = fread(data, 1, len, f)) == len)
			{
				char arr[1024];
				util.MyPrintDebug("recv success!\n");
				fclose(f);
			}
			else
				util.MyPrintDebug("recv error\n");
		}
		else
			util.MyPrintDebug("Error opening myfile\n");

		scenario = cJSON_Parse(data);
		if (!scenario)
		{
			char arr[1024];
			const char * a = cJSON_GetErrorPtr();
			sprintf(arr, "Error before: [%s]\n", a);
			util.MyPrintDebug(arr);
		}
		free(data);

		EventSequence * eventSequence = new EventSequence();
		string name;
		char* jsonName = cJSON_Print(cJSON_GetObjectItem(scenario, "name"));

		for (int i = 1; i < (int)strlen(jsonName) - 1; i++)
		{
			name += jsonName[i];
		}

		eventSequence->setName(name);

		EventCondition * eventCondition = new EventCondition();
		cJSON * conditionJSON = cJSON_GetObjectItem(scenario, "condition");
		cJSON * periodJSON = cJSON_GetObjectItem(conditionJSON, "period");
		cJSON * everyJSON = cJSON_GetObjectItem(periodJSON, "every");
		cJSON * timeJSON = cJSON_GetObjectItem(periodJSON, "time");

		if (strcmp(cJSON_Print(everyJSON), "\"none\""))
		{
			const char * timeString = cJSON_Print(timeJSON);
			int yy, month, dd, hh, mm, ss, wd;
			time_t timeValue = time(0);
			struct tm tm;
			tm = *localtime(&timeValue);

			if (!strcmp(cJSON_Print(everyJSON), "\"day\""))
			{
				sscanf(timeString, "\"%d:%d:%d\"", &hh, &mm, &ss);
				tm.tm_hour = hh;
				tm.tm_min = mm;
				tm.tm_sec = ss;

				eventCondition->setPeriod(EVERY_DAY);
				eventCondition->setTime(mktime(&tm));  // t is now your desired time_t
			}
			else if (!strcmp(cJSON_Print(everyJSON), "\"week\""))
			{
				sscanf(timeString, "\"%d %d:%d:%d\"", &wd, &hh, &mm, &ss);
				tm.tm_wday = wd;
				tm.tm_hour = hh;
				tm.tm_min = mm;
				tm.tm_sec = ss;

				eventCondition->setPeriod(EVERY_WEEK);
				eventCondition->setTime(mktime(&tm));  // t is now your desired time_t
			}
			else if (!strcmp(cJSON_Print(everyJSON), "\"month\""))
			{
				sscanf(timeString, "\"%d %d:%d:%d\"", &dd, &hh, &mm, &ss);
				tm.tm_mday = dd;
				tm.tm_hour = hh;
				tm.tm_min = mm;
				tm.tm_sec = ss;

				eventCondition->setPeriod(EVERY_MONTH);
				eventCondition->setTime(mktime(&tm));  // t is now your desired time_t
			}
			else if (!strcmp(cJSON_Print(everyJSON), "\"date\""))
			{
				sscanf(timeString, "\"%d.%d.%d %d:%d:%d\"", &yy, &month, &dd, &hh, &mm, &ss);
				tm.tm_year = yy - 1900;
				tm.tm_mon = month - 1;
				tm.tm_mday = dd;
				tm.tm_hour = hh;
				tm.tm_min = mm;
				tm.tm_sec = ss;

				eventCondition->setPeriod(ONE_DATE);
				eventCondition->setTime(mktime(&tm));  // t is now your desired time_t
			}
		}
		else
			eventCondition->setPeriod(NONE);

		cJSON * placeJSON = cJSON_GetObjectItem(conditionJSON, "place");
		cJSON * mapNameJSON = cJSON_GetObjectItem(placeJSON, "mapName");
		cJSON * xposJSON = cJSON_GetObjectItem(placeJSON, "xpos");
		cJSON * yposJSON = cJSON_GetObjectItem(placeJSON, "ypos");

		if (strcmp(cJSON_Print(placeJSON), "\"none\""))
		{
			string mapName;
			char* jsonMapName = cJSON_Print(mapNameJSON);

			for (int i = 1; i < (int)strlen(jsonMapName) - 1; i++)
			{
				mapName += jsonMapName[i];
			}

			string xpos;
			char* jsonXpos = cJSON_Print(xposJSON);
			for (int i = 1; i < (int)strlen(jsonXpos) - 1; i++)
			{
				xpos += jsonXpos[i];
			}

			string ypos;
			char* jsonYpos = cJSON_Print(yposJSON);
			for (int i = 1; i < (int)strlen(jsonYpos) - 1; i++)
			{
				ypos += jsonYpos[i];
			}

			eventCondition->setMapName(mapName);
			eventCondition->setXpos(atoi(xpos.c_str()));
			eventCondition->setYpos(atoi(ypos.c_str()));
		}
		else
			eventCondition->setMapName("NONE");

		cJSON * procedeEventJSON = cJSON_GetObjectItem(conditionJSON, "procedeEvent");

		if (strcmp(cJSON_Print(procedeEventJSON), "\"none\""))
		{
			string procedeEvent;
			char* jsonProcedeEvent = cJSON_Print(procedeEventJSON);

			for (int i = 1; i < (int)strlen(jsonProcedeEvent) - 1; i++)
			{
				procedeEvent += jsonProcedeEvent[i];
			}

			eventCondition->setProcedeEventName(procedeEvent);
		}
		else
			eventCondition->setProcedeEventName("NONE");

		eventSequence->setEventCondition(eventCondition);

		cJSON * scriptJSON = cJSON_GetObjectItem(scenario, "script");
		int sceanNumber = 0;

		while (1)
		{
			char sceanName[1024];
			sceanNumber++;
			sprintf(sceanName, "scean%d", sceanNumber);

			cJSON * sceanJSON = cJSON_GetObjectItem(scriptJSON, sceanName);
			if (sceanJSON != NULL)
			{
				EventObject * eventObject = new EventObject();

				cJSON * sceanTimeJSON = cJSON_GetObjectItem(sceanJSON, "time");
				const char * timeString = cJSON_Print(sceanTimeJSON);
				int yy, month, dd, hh, mm, ss, wd;
				time_t timeValue = time(0);
				struct tm tm;
				tm = *localtime(&timeValue);

				sscanf(timeString, "\"%d:%d:%d\"", &hh, &mm, &ss);
				tm.tm_hour = hh;
				tm.tm_min = mm;
				tm.tm_sec = ss;

				eventObject->setTime(mktime(&tm));

				string sceanPlace;
				cJSON * sceanPlaceJSON = cJSON_GetObjectItem(sceanJSON, "place");
				char* jsonSceanPlace = cJSON_Print(sceanPlaceJSON);

				for (int i = 1; i < (int)strlen(jsonSceanPlace) - 1; i++)
				{
					sceanPlace += jsonSceanPlace[i];
				}
				eventObject->setPlace(sceanPlace);

				string sceanSpeaker;
				cJSON * sceanSpeakerJSON = cJSON_GetObjectItem(sceanJSON, "speaker");
				char* jsonSceanSpeaker = cJSON_Print(sceanSpeakerJSON);

				for (int i = 1; i < (int)strlen(jsonSceanSpeaker) - 1; i++)
				{
					sceanSpeaker += jsonSceanSpeaker[i];
				}
				eventObject->setSpeaker(sceanSpeaker);

				string sceanLines;
				cJSON * sceanLinesJSON = cJSON_GetObjectItem(sceanJSON, "lines");
				char* jsonSceanLines = cJSON_Print(sceanLinesJSON);

				for (int i = 1; i < (int)strlen(jsonSceanLines) - 1; i++)
				{
					sceanLines += jsonSceanLines[i];
				}
				eventObject->setLines(sceanLines);

				eventSequence->setEventObject(eventObject);
			}
			else
				break;
		}

		cJSON_Delete(scenario);
		eventList.push_back(eventSequence);
#if defined(_WIN32)
	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
#elif defined(__linux__) || defined(__APPLE__)
	} while ((entry = readdir(dp)) != NULL);
	closedir(dp);
#endif
}

EventProcedure::~EventProcedure()
{
	for (int i = 0; i < eventList.size(); i++)
	{
		delete eventList.at(i);
	}
}

EventSequence * EventProcedure::getEventSequence(int idx)
{
	return this->eventList.at(idx);
}

bool EventProcedure::isSatisfyConditionObject(User user)
{
	EventSequence * resultEventSequence = NULL;

	if (isRun == true)
		return false;

	for (int i = 0; i < eventList.size(); i++)
	{
		EventSequence* imsiEventSequence = eventList.at(i);
		if(imsiEventSequence->getProgress() != true && imsiEventSequence->isConfirmCondition(user))
		{
			resultEventSequence = imsiEventSequence;
			isRun = true;
			break;
		}
	}

	progressEvent = resultEventSequence;

	if (progressEvent == NULL)
		return false;
	else
		return true;
}

string EventProcedure::getPlayingSpeech(float contentSize, float stringHeight)
{
	if (progressEvent != NULL)
	{
		while (1)
		{
			EventObject* imsiEventObject = NULL;

			if (procede < progressEvent->getEventSize())
			{
				imsiEventObject = progressEvent->getEventObject(procede);
				string lines = imsiEventObject->getLines();

				if (syllableCount < lines.size())
				{
					syllableCount++;
					if (contentSize < stringHeight)
						flagSyllableCount = syllableCount - 1;
					return lines.substr(flagSyllableCount, syllableCount);
				}
				else
				{
					syllableCount = 0;
					flagSyllableCount = 0;
					procede++;
				}
			}
			else
			{
				procede = 0;
				progressEvent->setProgress(true);
				progressEvent = NULL;
				return "";
			}
		}
	}
	else
		return "";
}

void EventProcedure::skipPlayingSpeech()
{
	if(progressEvent != NULL)
		procede = progressEvent->getEventSize();
}

EventSequence * EventProcedure::getProgressEventSequence()
{
	return progressEvent;
}

void EventProcedure::setProgress(const char * name, bool value)
{
	EventSequence * resultEventSequence = NULL;

	for (int i = 0; i < eventList.size(); i++)
	{
		EventSequence* imsiEventSequence = eventList.at(i);
		if (!strcmp(imsiEventSequence->getName().c_str(), name))
		{
			resultEventSequence = imsiEventSequence;
			imsiEventSequence->setProgress(value);
			break;
		}
	}
}