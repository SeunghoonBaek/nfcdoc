#include "ResponsePlayPacket.h"

ResponsePlayPacket::ResponsePlayPacket()
{

}

ResponsePlayPacket::~ResponsePlayPacket(){

}

double ResponsePlayPacket::getNPTTimeAtClientPacket(char* _packet, int _length){
	double nptTime = 0.0;
	char* lineTok = strtok( _packet, "\r\n" );
	if( !lineTok ) 
		return nptTime;

	// find ragne tag while finding '\r\n' characters
	while( lineTok ){
		char* findRangeTag = strstr( lineTok, "Range: ");
		if( !findRangeTag ){
			lineTok = strtok( NULL, "\r\n" );	
			continue;
		}

		char* findNPTTag = strstr(findRangeTag, "npt=" );
		if( !findNPTTag ){
			return nptTime;
		}

		findNPTTag = findNPTTag + strlen( "npt:" );
		char* findHyphenEndTag = strchr( findRangeTag, '-' );
		
		int nptValueSize = findHyphenEndTag - findNPTTag  + 1;
		char* nptValueString = new char[ nptValueSize ];
		strncpy( nptValueString, findNPTTag, nptValueSize -1  );
		nptValueString[ nptValueSize - 1 ] = '\0';

		nptTime = atof( nptValueString );
		delete[] nptValueString;
		break;
	}

	return nptTime;
}

string ResponsePlayPacket::getPacket(Client& _client){
	stringstream packet;
	ServerResource& resource = SingletonManager<ServerResource>::getInstance();

	// RTP �����带 �̸� �غ��� �༭ Ŭ���̾�Ʈ�� ������ ����� �غ���
	// _client.mpRTPThread = new thread( &(ClientThreadWork::SendRTPPacket),  &_client );
	Thread* pThread = new ClientThreadWork(&_client);
	_client.setRTPThread( pThread );
	pThread->Construct();
	pThread->Start();

	double nptTime = getNPTTimeAtClientPacket( _client.getRecentDescriptorResult()->mPacketData, _client.getRecentDescriptorResult()->mPacketSize );

	packet << "RTSP/1.0 200 OK\r\n";
	packet << "Server: DOKU_RTSPServer\r\n";
	packet << "CSeq: " << _client.getContext().getSequenceNumber() << "\r\n";
	packet << "Date: " << resource.getDateManager()->getTodayDate() <<"\r\n";
	packet << "Range: npt=" << nptTime << "-\r\n";
	packet << "Session: " << _client.getContext().getSessionID() <<"\r\n";
	packet << "Content-length: 0\r\n";
	packet << "Cache-Control: no-cache\r\n";
	packet << "\r\n";

	return packet.str();
}
