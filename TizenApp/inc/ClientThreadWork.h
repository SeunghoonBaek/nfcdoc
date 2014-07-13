#ifndef _CLIENTTHREADWORK_H_
#define _CLIENTTHREADWORK_H_

#include <iostream>
#include <stdio.h>

#include <FNet.h>
#include <FBase.h>
#include <FApp.h>

using std::cout;
using namespace Tizen::Net;
using namespace Tizen::Net::Sockets;
using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;

#include "MPAudio/MPAFile.h"
#include "Client.h"

#define DEBUG 1

class ClientThreadWork : public Thread{
public :

	// constructor and destructor
	ClientThreadWork(Client* _pClient = 0);
	virtual ~ClientThreadWork();					// do not delete client pointer

	// thread inheritance method
	result 			Construct();
	Object* 			Run();
	void 				setClient(Client* _pClient );

private :
	void TransferMP3Frame();
	void PrintMessage( string _message );

private :
	Client* m_pClient;

};


#endif



/*
static void PrintMessage( Client* _pClient, string _message ){
	if( DEBUG )
		cout << " >> [ClientThreadWork, Client ID : " << _pClient->getClientID() << "] " << _message << "\n";
}

static void SendRTPPacket(Client* _pClient ){

	Socket* rtpSocket;
	MPAFile* pFile = NULL;

	PrintMessage(_pClient, "Start Send RTP Packet Method");

	// ready mp3 file
	string mp3FilePath = _pClient->getMP3Path();
	char* mp3FilePathNonConstChar = const_cast<char*>(mp3FilePath.c_str());
	pFile = new MPAFile( mp3FilePathNonConstChar );
	if( !pFile ) return;

	// set start rtp sending thread
	_pClient->setIsConnectRTPThread(true);
	_pClient->setRemoteIP( _pClient->getRTSPSocket()->getIPAddress() );

	// create socket
	rtpSocket = new Socket();
	rtpSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_DATAGRAM, NET_SOCKET_PROTOCOL_UDP);

	// Enable the synchronous (blocking) mode
	unsigned long arg = 0;
	rtpSocket->Ioctl(NET_SOCKET_FIONBIO, arg);

	// Create a peer end point
	string clientIP = _pClient->getRemoteIP();
	const char* constClientIP = clientIP.c_str();
	Ip4Address peerAddr( constClientIP ); // Peer socket address
	unsigned short peerPort = _pClient->getRTPRemotePortNum(); // Port
	NetEndPoint peerEndPoint(peerAddr, peerPort);

	//cout << " >> [SendRTPPacket] client Address : " << constClientIP<< ", client Port : " <<  ntohs(rtpClientAddr.sin_port) << "\n";

	// send mp3 frame data
	PrintMessage(_pClient, "Sending MP3 Frame");
	MPAFrame* getFrame = pFile->GetFrame(MPAFile::First, NULL );

	while( _pClient->getIsConnectRTPThread() ){
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

	PrintMessage(_pClient, "End Send RTP Packet Method");
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
*/
