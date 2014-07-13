#include "ResponseSetupPacket.h"

string ResponseSetupPacket::getPacket(Client& _client){
	stringstream packet;
	ServerResource& resource = SingletonManager<ServerResource>::getInstance();

	packet << "RTSP/1.0 200 OK\r\nServer: DOKU_RTSPServer\r\nCSeq: " << _client.getContext().getSequenceNumber() << "\r\n";
	packet << "Date: " << resource.getDateManager()->getTodayDate() << "\r\n";

	// get client port number at the received client packet
	PortNum* clientPortNumber = getClientPortNumberInformation( _client.getRecentDescriptorResult()->mPacketData, _client.getRecentDescriptorResult()->mPacketSize );
	if( !clientPortNumber ){
		clientPortNumber = new PortNum( 33445, 1, true);
	}
	_client.setRTPRemotePortNum( clientPortNumber->getPortNumStart() );

	// transport information
	// important things are client_port number and server_port number
	// [Transport Information]
	// - RTP/AVP/UDP		; transport type
	// - unicast				; transport method
	// - client_port		; client port number, start - end
	// - serer_port			; server port number, start - end
	// - mode				; after method
	packet << "Transport: RTP/AVP/UDP;unicast;client_port=" << clientPortNumber->getPortNumStart() << "-" << clientPortNumber->getPortNumStart() + clientPortNumber->getPortNumCount() <<";server_port=" << _client.getRTPLocalPortNum() << "-" << _client.getRTPLocalPortNum() << ";mode=play\r\n";

	// second important thing is session id,
	// we can distinct each client using session id
	char* sessionID = resource.getSessionManager()->CreateSessionID();
	packet << "Session: " << sessionID << ";timeout=60\r\n";
	packet << "Content-length: 0\r\n";
	packet << "Cache-Control: no-cache\r\n";
	packet << "CSeq: " << _client.getContext().getSequenceNumber() << "\r\n";
	packet << "\r\n";

	delete sessionID;
	delete clientPortNumber;
	return packet.str();
}

// get client port number in client packet data
// _data : client packet data
// _length : packet's length
PortNum* ResponseSetupPacket::getClientPortNumberInformation(char* _data, int _length){
	if( !_data || !_length )
		return 0;

	char* portStr = 0;

 	char* findTransSection = strtok( _data, "\r\n");
	if( !findTransSection ) 
		return 0;

	do{

		char* checkTransportTag = strstr( findTransSection, "Transport: ");
		if( !checkTransportTag ){
			findTransSection = strtok( NULL, "\r\n" );

			if(	!findTransSection )
				break;

			continue;
		}

		do{
			// get client port number 
			portStr = strstr(findTransSection, "client_port");

			if( portStr ){

				// packet data is below style.
				// client Start Port Number - client End port Number
				// so first, search hyphen char
				// second, sprate left string, right string so that get client number on integer
				portStr = strchr( portStr, '=');
				portStr = portStr + 1;

				// copy same string value for get integer value
				char tempPortString[12];
				strcpy( tempPortString, portStr );

				char* hyphenPosition = strchr( tempPortString, '-' );

				// insert '\0' value instance of hyphen char
				// so that distinct two character value
				if( hyphenPosition ){
					*hyphenPosition = '\0';
					hyphenPosition++;
				}
				else
					break;

				int iStartPort = atoi( tempPortString );
				int iEndPort = atoi( hyphenPosition );
				return new PortNum( iStartPort, iEndPort - iStartPort, true );;
			}
		}while( portStr != NULL);

	} while( findTransSection );

	return 0;
}