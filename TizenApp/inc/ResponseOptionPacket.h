#ifndef _RESPONSEOPTIONPACKET_H_
#define _RESPONSEOPTIONPACKET_H_
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

#include "IPacketBase.h"
class ResponseOptionPacket : public IPacketBase{
public :
	ResponseOptionPacket(){}
	~ResponseOptionPacket(){}

	string getPacket(Client& _client);
};


#endif