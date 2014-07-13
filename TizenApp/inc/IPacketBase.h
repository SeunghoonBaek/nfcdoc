#ifndef _IPACKETBASE_H_
#define _IPACKETBASE_H_

#include <string>
using std::string;

#include "Client.h"
class IPacketBase{
public :
	IPacketBase(){}
	virtual ~IPacketBase(){}

	virtual string getPacket(Client& _client) = 0;
};

#endif