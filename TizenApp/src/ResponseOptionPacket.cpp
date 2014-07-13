#include "ResponseOptionPacket.h"

string ResponseOptionPacket::getPacket(Client& _client){
	stringstream packet;
	packet << "RTSP/1.0 200 OK\r\nServer: DOKU_RTSPServer\r\nCSeq: " << _client.getContext().getSequenceNumber() << "\r\nPublic: ";
	packet << "DESCRIBE, SETUP, TEARDOWN, PLAY, PAUSE\r\n\r\n";

	return packet.str();
}