#ifndef _SESSIONMANAGER_H_
#define _SESSIONMANAGER_H_

#include <FBase.h>
#include <FNet.h>

#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace Tizen::Net;
using namespace Tizen::Net::Sockets;
using namespace Tizen::Base;
using std::string;

class SessionManager{
public :
	SessionManager();
	~SessionManager(){}

	char* CreateSessionID();

	string getServerIPAddress();

private :
	char getRandomChar();
	char getRandomNumber();
	static unsigned long state[16];
	static unsigned int index;

public :
	static const int MAX_SESSIONID_LENGTH = 16;
};

#endif
