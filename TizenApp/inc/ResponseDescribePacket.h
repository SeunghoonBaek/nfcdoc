#ifndef _RESPONSEDESCRIBEPACKET_H_
#define _RESPONSEDESCRIBEPACKET_H_

#include <string>
#include <sstream>
#include <time.h>
using std::string;
using std::stringstream;

#include "IPacketBase.h"
#include "SingletonManager.h"
#include "ServerResource.h"
class ResponseDescribePacket : public IPacketBase{
public : 
	ResponseDescribePacket(){}
	~ResponseDescribePacket(){}

	string getPacket(Client& _client);
};

#endif