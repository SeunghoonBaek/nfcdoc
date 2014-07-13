#ifndef _REQUESTTEARDOWNPACKET_H_
#define _REQUESTTEARDOWNPACKET_H_

#include "IPacketBase.h"
class RequestTeardownPacket : public IPacketBase{
public :
	RequestTeardownPacket(){}
	~RequestTeardownPacket(){}

	string getPacket(Client& _client){
		return "req_teardown";
	}
};

#endif