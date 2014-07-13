#include "RTSPSocket.h"

// _pSocket : socket number, default value is -1
// _portNumber : want to open socket's port number, maybe rtsp port is 8554(default port number )
RTSPSocket::RTSPSocket(Socket* _pSocket, int _portNumber, ISocketEventListener* _pListener )
			: m_pSocket(_pSocket), mPortNumber(_portNumber ), mIsOpenSocket(false), m_pISocketListener(_pListener) {

	mIsOpenSocket = (m_pSocket == NULL ) ? false : true;
}

RTSPSocket::~RTSPSocket(){
	if( isOpened() ){
		Close();
	}
}

bool RTSPSocket::Open(){
	if( isOpened() || !m_pISocketListener )
		return false;

    result res = E_SUCCESS;

	// create socket object
	m_pSocket = new Socket();
	res = m_pSocket->Construct(NET_SOCKET_AF_IPV4, NET_SOCKET_TYPE_STREAM, NET_SOCKET_PROTOCOL_TCP);

	// set non-blocking mode
	unsigned long arg = 1;
	res = m_pSocket->Ioctl(NET_SOCKET_FIONBIO, arg);

	// add select model socket, setting listener of accept event and close event
	res = m_pSocket->AddSocketListener(*m_pISocketListener );
	res = m_pSocket->SetSockOpt(NET_SOCKET_SOL_SOCKET, NET_SOCKET_SO_REUSEADDR, 1);
	res = m_pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_CONNECT | NET_SOCKET_EVENT_WRITE | NET_SOCKET_EVENT_READ | NET_SOCKET_EVENT_CLOSE | NET_SOCKET_EVENT_ACCEPT);

	// setting ip address
	unsigned short peerPort = mPortNumber;
	Ip4Address peerAddr(NET_SOCKET_INADDR_ANY);
	NetEndPoint* peerEndPoint = new (std::nothrow) NetEndPoint(peerAddr, peerPort);

	res = m_pSocket->Bind(*peerEndPoint);
	res = m_pSocket->Listen(0);
	delete peerEndPoint;

	AppLog("Socket Return %s", GetErrorMessage(res));

	return true;
}

bool RTSPSocket::Close(){

	if( !isOpened() ) return false;

	m_pSocket->Close();
	mIsOpenSocket = false;
	return true;
}

bool RTSPSocket::isOpened(){
	return mIsOpenSocket;
}

int RTSPSocket::getPortNumber(){
	return mPortNumber;
}

Socket* RTSPSocket::getSocket(){
	return m_pSocket;
}

int RTSPSocket::WriteData(char* _data, int _length){
	if( !isOpened()) return -1;

	int successfulLength = 0;
	m_pSocket->Send( (void *)_data, _length, successfulLength );
	return successfulLength;
}

const IpAddress*	RTSPSocket::getIPAddress(){
	return m_pSocket->GetLocalEndPoint()->GetAddress();
}

void	RTSPSocket::addSocketListener( Tizen::Net::Sockets::ISocketEventListener* _pListener ){

	// for client socket, its time is after accept function.
	m_pISocketListener = _pListener;
	m_pSocket->AsyncSelectByListener(NET_SOCKET_EVENT_WRITE | NET_SOCKET_EVENT_READ | NET_SOCKET_EVENT_CLOSE);
}
