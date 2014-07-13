#ifndef _RESPONSEPAUSEPACKET_H_
#define _RESPONSEPAUSEPACKET_H_

#include "IPacketBase.h"
class ResponsePausePacket : public IPacketBase{
public :
	ResponsePausePacket(){}
	~ResponsePausePacket(){}

	string getPacket(Client& _client){
		return "res_pause";
	}
};

#endif