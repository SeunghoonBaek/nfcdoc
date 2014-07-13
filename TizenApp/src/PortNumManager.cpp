#include "PortNumManager.h"

PortNum* PortNumManager::getUsableRTPPortNumber(){
	PortNum* checkUsablePortNum = NULL;

	while( (checkUsablePortNum = checkPortNumber(mLastPortNumber++)) == NULL );

	return checkUsablePortNum;
}

PortNum* PortNumManager::checkPortNumber(int _checkPortNumber){
	int portNum = _checkPortNumber;
	PortNum* usePortNum = new PortNum(portNum, 1, true);
	return usePortNum;
}
