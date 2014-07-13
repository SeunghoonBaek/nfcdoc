#include "ClientThreadWork.h"

ClientThreadWork::ClientThreadWork(Client* _pClient ) : m_pClient( _pClient ){

}

ClientThreadWork::~ClientThreadWork(){
	// do not delete Client
}
result ClientThreadWork::Construct(){
	return Thread::Construct();
}
Object* ClientThreadWork::Run(){
	TransferMP3Frame();
	return NULL;
}

void ClientThreadWork::setClient(Client* _pClient ){
	m_pClient = _pClient;
}

void ClientThreadWork::TransferMP3Frame(){
	Socket* rtpSocket;
	MPAFile* pFile = NULL;

	PrintMessage( "Start Send RTP Packet Method");

	// ready mp3 file
	string mp3FilePath = m_pClient->getMP3Path();
	char* mp3FilePathNonConstChar = const_cast<char*>(mp3FilePath.c_str());
	pFile = new MPAFile( mp3FilePathNonConstChar );
	if( !pFile ) return;

	// set start rtp sending thread
	m_pClient->setIsConnectRTPThread(true);
	// m_pClient->setRemoteIP( m_pClient->getRTSPSocket()->getIPAddress() );
	const IpAddress* pIpAddr = m_pClient->getRTSPSocket()->getIPAddress();

	// create socket
	rtpSocket = new Socket();
	rtpSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);

	// Enable the synchronous (blocking) mode
	unsigned long arg = 0;
	rtpSocket->Ioctl(NET_SOCKET_FIONBIO, arg);

	// Create a peer end point
	// string clientIP = m_pClient->getRemoteIP();
	// const char* constClientIP = clientIP.c_str();
	// Ip4Address peerAddr( constClientIP ); // Peer socket address
	unsigned short peerPort = m_pClient->getRTPRemotePortNum(); // Port
	NetEndPoint peerEndPoint(*pIpAddr, peerPort);

	//cout << " >> [SendRTPPacket] client Address : " << constClientIP<< ", client Port : " <<  ntohs(rtpClientAddr.sin_port) << "\n";

	// send mp3 frame data
	PrintMessage( "Sending MP3 Frame");
	MPAFrame* getFrame = pFile->GetFrame(MPAFile::First, NULL );

	while( m_pClient->getIsConnectRTPThread() ){
		if( getFrame ){
			unsigned char* pFrameData = getFrame->getFrameBuffer();
			int iFrameSize = getFrame->m_dwFrameSize;

			int sendLen = 0;
			rtpSocket->SendTo( (void *) pFrameData, iFrameSize, peerEndPoint, sendLen );
			getFrame = pFile->GetFrame( MPAFile::Next, getFrame );
		}
		else
			break;

		usleep(100);
	}

	PrintMessage( "End Send RTP Packet Method");
	rtpSocket->Close();

	if( pFile ){
		delete pFile;
		pFile = 0;
	}

	if( rtpSocket ){
		delete rtpSocket;
		rtpSocket = NULL;
	}
}

void ClientThreadWork::PrintMessage( string _message ){
	char message[128] = {0,};
	sprintf( message, " >> [ClientThreadWork] Client ID : %d, %s", m_pClient->getClientID(), _message.c_str() );
	AppLog( message );

}
