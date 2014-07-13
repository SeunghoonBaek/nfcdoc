#ifndef _PORTNUMMANAGER_H_
#define _PORTNUMMANAGER_H_

#include <vector>
using std::vector;

#include "PortNum.h"
class PortNumManager{
public :
	PortNumManager() : mLastPortNumber(DEFAULT_START_CLIENT_PORT_NUMBER) {}
	~PortNumManager(){}
	PortNum* getUsableRTPPortNumber();

private :
	PortNum* checkPortNumber(int _checkPortNumber);

	static const int DEFAULT_START_CLIENT_PORT_NUMBER = 33556;
	int mLastPortNumber;
};

#endif
