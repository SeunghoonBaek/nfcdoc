#ifndef _RESPONSESETUPPACKET_H_
#define _RESPONSESETUPPACKET_H_

#include <sstream>
#include <string>
#include <string.h>
using std::stringstream;
using std::string;

#include "IPacketBase.h"
#include "PortNum.h"
#include "SingletonManager.h"
#include "ServerResource.h"
class ResponseSetupPacket : public IPacketBase{
public :
	ResponseSetupPacket(){}
	~ResponseSetupPacket(){}

	string getPacket(Client& _client);
	PortNum* getClientPortNumberInformation(char* _data, int _length);
};

#endif