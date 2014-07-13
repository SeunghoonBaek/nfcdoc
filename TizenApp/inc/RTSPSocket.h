#ifndef _RTSPSOCKET_H_
#define _RTSPSOCKET_H_

#include <string.h>
#include <string>

#include <FNet.h>
#include <FBase.h>
#include <FApp.h>

using namespace Tizen::Net;
using namespace Tizen::Net::Sockets;
using namespace Tizen::Base;
using std::string;

class RTSPSocket {

// constant values
private :
	static const int DEFAULT_NON_SOCKET = -1;
	static const int DEFAULT_PORT_NUMBER = 8554;

public :
	RTSPSocket(Socket* _pSocket = NULL, int _portNumber = DEFAULT_PORT_NUMBER, ISocketEventListener* _pListener = 0);
	~RTSPSocket();

	// Socket Operation Method
	bool 							Open();
	bool 							Close();
	bool 							isOpened();

	// Send Data to EndPeer
	int 							WriteData(char* _data, int _length);

	// get Socket Objects or Net Information
	const IpAddress*			getIPAddress();
	int 							getPortNumber();
	Socket* 					getSocket();

	RTSPSocket& 				operator=(const RTSPSocket& rhs);
	void							addSocketListener( Tizen::Net::Sockets::ISocketEventListener* _pListener );

private :
	Socket* 					m_pSocket;				// Socket Objects
	bool 							mIsOpenSocket;		// Is Open Socket Flag
	IpAddress*					m_pIPaddress;			// NetLocal IPAddress Objects
	int 							mPortNumber;			// NetLocal PortNumber
	Tizen::Net::Sockets::ISocketEventListener* m_pISocketListener;		// Socket Listener Pointer, It can point RTSPServer( server slide ),																								// and RTSPContextLogic( client side, after accept method )

};

#endif



// RTSPSocket* 			Accept();
// int 							ReadData(char* _buffer, int _bufSize);
//string 						getIPAddress();
// ISocketEventListener Events
//private :
//	void OnSocketConnected(Socket& socket);
//	void OnSocketClosed(Socket& socket, NetSocketClosedReason reason);
//	void OnSocketReadyToReceive(Socket& socket);
//	void OnSocketReadyToSend(Socket& socket);
//	void OnSocketAccept(Socket& _socket);
