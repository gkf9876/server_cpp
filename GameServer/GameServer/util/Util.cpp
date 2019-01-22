#include "Util.h"

struct tm Util::MySQL_DateToTime(const char* date)
{
	time_t     user_time;
	struct tm  user_stime;
	struct tm* ptr_stime;
	char message[1024];
	char year[5];
	char month[3];
	char day[3];
	char hour[3];
	char min[3];
	char second[3];

	strcpy(message, date);
	strncpy(year, &message[0], 4);
	year[4] = '\0';
	strncpy(month, &message[5], 2);
	month[2] = '\0';
	strncpy(day, &message[8], 2);
	day[2] = '\0';
	strncpy(hour, &message[11], 2);
	hour[2] = '\0';
	strncpy(min, &message[14], 2);
	min[2] = '\0';
	strncpy(second, &message[17], 2);
	second[2] = '\0';

	user_stime.tm_year = atoi(year) - 1900;   // 주의 :년도는 1900년부터 시작
	user_stime.tm_mon = atoi(month) - 1;      // 주의 :월은 0부터 시작
	user_stime.tm_mday = atoi(day);
	user_stime.tm_hour = atoi(hour);
	user_stime.tm_min = atoi(min);
	user_stime.tm_sec = atoi(second);

	user_time = mktime(&user_stime);
	ptr_stime = localtime(&user_time);

	return *ptr_stime;
}

vector<Chatting> Util::latest5secondChatting(vector<Chatting> chatting)
{
	time_t now;
	time(&now);
	struct tm chattingTm;
	int chattingTime;
	int i, j;

	vector<Chatting> result;

	for (i = chatting.size() - 1; i >= 0; i--)
	{
		Chatting imsiChatting = chatting.at(i);

		chattingTm = MySQL_DateToTime(imsiChatting.getInputdate());
		chattingTime = mktime(&chattingTm);

		if ((now - chattingTime) < 5)
		{
			for (j = 0; j < result.size(); j++)
			{
				if (!strcmp(result.at(j).getName(), imsiChatting.getName()))
					break;
			}

			if(j >= result.size())
				result.push_back(imsiChatting);
		}
		else
			break;
	}

	return result;
}

void Util::MyPrintDebug(const char* message)
{
	wchar_t pszCharacterString[100000];

	int nLen = (int)strlen(message) + 1;
	mbstowcs(pszCharacterString, message, nLen);

#ifdef _WIN32
	OutputDebugString(pszCharacterString);
#elif __linux__
	printf("%s", message);
#endif
}