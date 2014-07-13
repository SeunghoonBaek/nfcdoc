#include "PacketManager.h"

PacketManager::PacketManager(){
	CreatePacketMap();
}

PacketManager::~PacketManager(){
	
}

void PacketManager::CreatePacketMap(){
	mPacketMap.erase( mPacketMap.begin(), mPacketMap.end());

	mPacketMap.insert( pair<string, IPacketBase *>("RES_OPTIONS", new ResponseOptionPacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("RES_DESCRIBE", new ResponseDescribePacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("RES_SETUP", new ResponseSetupPacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("RES_PLAY", new ResponsePlayPacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("RES_PAUSE", new ResponsePausePacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("RES_TEARDOWN", new ResponseTeardownPacket()));
	mPacketMap.insert( pair<string, IPacketBase *>("REQ_TEARDOWN", new RequestTeardownPacket()));

}

IPacketBase* PacketManager::getPacket(string& _name){
	map<string, IPacketBase* >::iterator itr;
	itr = mPacketMap.find(_name);

	// not found
	if( itr == mPacketMap.end() )
		return NULL;

	return itr->second;
}
