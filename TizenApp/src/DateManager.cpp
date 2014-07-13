#include "DateManager.h"

char DateManager::week[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
char DateManager::month[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

string DateManager::getTodayDate(){
	time_t timer;
	struct tm* t;

	timer = time(NULL);
	t= localtime( &timer );

	// Date: Fri, 16 May 2014 06:21:53 GMT\r\n
	stringstream ss;
	ss << "" << week[t->tm_wday] << ", " << t->tm_mday << " " << month[t->tm_mon] << " " << t->tm_year + 1900 << " " << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << " GMT";

	return ss.str();
}

int DateManager::getTimeStamp(){
	time_t timeStamp;
	timeStamp = time(NULL);
	return timeStamp;
} 