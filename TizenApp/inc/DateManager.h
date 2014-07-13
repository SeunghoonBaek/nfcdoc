#ifndef _DATEMANAGER_H_
#define _DATEMANAGER_H_

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <time.h>
#include <sstream>
using std::stringstream;
using std::string;

class DateManager{
private :
	static char week[][4];
	static char month[][4];

public :
	DateManager(){}
	~DateManager(){}
	string getTodayDate();
	int getTimeStamp();
};

#endif


//string today = "";
//today += week[t->tm_wday];
//today += ", ";
//today += t->tm_mday;
//today += " ";
//today += month[t->tm_mon];
//today += " ";
//today += t->tm_year + 1900;
//today += " ";
//today += t->tm_hour;
//today += ":";
//today += t->tm_min;
//today += ":";
//today += t->tm_sec;
//today += "  GMT";
// return today;