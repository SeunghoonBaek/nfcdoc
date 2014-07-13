#ifndef _PACKETMANAGER_H_
#define _PACKETMANAGER_H_

#include <map>
#include <string>

using std::map;
using std::string;
using std::pair;

#include "IPacketBase.h"
#include "PacketHeader.h"
class PacketManager{
public :

	PacketManager();
	~PacketManager();
	IPacketBase* getPacket(string& _name);

private :
	void CreatePacketMap();

private :
	map<string, IPacketBase* > mPacketMap;
};

#endif
