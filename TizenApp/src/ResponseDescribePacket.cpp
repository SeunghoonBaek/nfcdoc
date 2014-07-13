#include "ResponseDescribePacket.h"

string ResponseDescribePacket::getPacket(Client& _client){
	stringstream packet;
	stringstream sdpPacket;
	ServerResource& resource = SingletonManager<ServerResource>::getInstance();

	// first, create sdp packet, because describe packet must be get sdp length
	sdpPacket << "v=0" << "\r\n";
	int curTimeStamp = resource.getDateManager()->getTimeStamp();
	sdpPacket << "o=- " << curTimeStamp << " " << curTimeStamp << " IN " << "IP4 DokuServerPC\r\n";
	sdpPacket << "s=Unnamed\r\n";
	sdpPacket << "i=N/A\r\n";
	sdpPacket << "c=IN IP4 " << resource.getSessionManager()->getServerIPAddress() << "\r\n";
	sdpPacket << "t=0 0\r\n";
	sdpPacket << "a=recvonly\r\n";
	sdpPacket << "a=type:broadcast\r\n";
	sdpPacket << "a=charset:UTF-8\r\n";

	// 파일에 따라 수정되야 함
	PortNum* localPort = resource.getPortNumManager()->getUsableRTPPortNumber();
	if( localPort ){
		_client.setRTPLocalPortNum( localPort->getPortNumStart() );
		delete localPort;
	}

	sdpPacket << "m=audio " << _client.getRTPLocalPortNum() << "RTP/AVP 14\r\n";
	sdpPacket << "b=AS:320\r\n";
	sdpPacket << "b=RR:0\r\n";
	sdpPacket << "rtpmap:14 MPA/90000/2\r\n";
	// 여기까지

	sdpPacket << "\r\n";

	packet << "RTSP/1.0 200 OK \r\nServer: DOKU_RTSPServer\r\nCSeq: " << _client.getContext().getSequenceNumber() << "\r\n";
	packet << "Content-type: " << "application/sdp" << "\r\n";
	packet << "Content-Base: " << "rtsp://" << resource.getSessionManager()->getServerIPAddress() << ":8554\r\n";
	packet << "Content-length: " << sdpPacket.str().length() << "\r\n";
	packet << "\r\n";
	packet << sdpPacket.str();

	return packet.str();	
}

	// sdpPacket << "control:rtsp://127.0.0.1:8554\r\n";
	/*
	v=0
	o=- 15501439399845077832 15501439399845077832 IN IP4 Baek-PC
	s=Unnamed
	i=N/A
	c=IN IP4 0.0.0.0
	t=0 0
	a=tool:vlc 2.1.3
	a=recvonly
	a=type:broadcast
	a=charset:UTF-8
	a=control:rtsp://127.0.0.1:8554/
	m=audio 0 RTP/AVP 14
	b=AS:320
	b=RR:0
	a=rtpmap:14 MPA/90000/2
	a=control:rtsp://127.0.0.1:8554/trackID=3

	*/



/*
An example SDP description is:

v=0
o=jdoe 2890844526 2890842807 IN IP4 10.47.16.5
s=SDP Seminar
i=A Seminar on the session description protocol
u=http://www.example.com/seminars/sdp.pdf
e=j.doe@example.com (Jane Doe)
c=IN IP4 224.2.17.12/127
t=2873397496 2873404696
a=recvonly
m=audio 49170 RTP/AVP 0
m=video 51372 RTP/AVP 99
a=rtpmap:99 h263-1998/90000
*/


// RFC 4566 http://tools.ietf.org/html/rfc4566
// define session description protocol
// v
// o
// c
// t= 
// a=recvonly\r\n
// m=<media> <port> <proto> <fmt> ...
//		m=video 49170/2 RTP/AVP 31
// m=audio 33445 RTP/AVP 14
// b
// b
// a
// a