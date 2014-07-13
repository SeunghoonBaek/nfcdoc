#ifndef _RESPONSETEARDOWNPACKET_H_
#define _RESPONSETEARDOWNPACKET_H_

#include "IPacketBase.h"
class ResponseTeardownPacket : public IPacketBase{
public :
	ResponseTeardownPacket(){}
	~ResponseTeardownPacket(){}

	string getPacket(Client& _client){
		return "res_teardown";
	}
};

#endif