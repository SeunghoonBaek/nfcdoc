#ifndef _LOGMANAGER_H_
#define _LOGMANAGER_H_

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class LogManager{
public :
	LogManager(){}
	~LogManager(){}
	static void LogLine(string _log){
		cout << _log << "\n";
	}

};

#endif