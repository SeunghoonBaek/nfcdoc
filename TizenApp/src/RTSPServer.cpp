#include "RTSPServer.h"

// initialize singleton
// ServerResource* SingletonManager<ServerResource>::mpInstance = new ServerResource();
ServerResource gInstance = SingletonManager<ServerResource>::getInstance();
string RTSPServer::mMP3Path = "";
// thread* gServerThread;


// open server with one thread
// passing by this pointer for controls accepting work
// void OpenServer( RTSPServer* _pServer );
RTSPServer::RTSPServer(string _mp3Path) : mIsStartServer(false){
	mMP3Path = _mp3Path;

	// gServerThread = NULL;
}

RTSPServer::~RTSPServer(){
	CloseServer();
}

bool RTSPServer::StartServer(){
	if( mIsStartServer )
		return false;

	mListenRTSPSocket.addSocketListener( this );
	mListenRTSPSocket.Open();
	mIsStartServer = true;
	return true;
}
void RTSPServer::setMP3Path(string _path){
	mMP3Path = _path;
}

string RTSPServer::getMP3Path(){
	return mMP3Path;
}

void RTSPServer::CloseServer(){
	if(! mIsStartServer )
		return;

	mIsStartServer = false;

	// delete all client thread.
	SingletonManager<ServerResource>::getInstance().getThreadManager()->CloseAllThread();
	SingletonManager<ServerResource>::freeInstance();	

	mListenRTSPSocket.Close();
}

RTSPSocket*	RTSPServer::getListenSocket(){
	return &mListenRTSPSocket;
}

bool	RTSPServer::getIsStartServer(){
	return mIsStartServer;
}

void	RTSPServer::setIsStartServer(bool _isServerServer){
	mIsStartServer = _isServerServer;
}

void RTSPServer::OnSocketConnected(Socket& socket){
	AppLog( " >> RTSPServer, OnSocketConnect " );
	// AppLogTag(L"RTSPServer", L"OnSocketConnected, Nothing");
}
void RTSPServer::OnSocketClosed(Socket& socket, NetSocketClosedReason reason){
	AppLog( " >> RTSPServer, OnSocketClosed " );
	CloseServer();
}

void RTSPServer::OnSocketReadyToReceive(Socket& socket){
	AppLog( " >> RTSPServer, OnSocketReadyToReceive " );
}
void RTSPServer::OnSocketReadyToSend(Socket& socket){
	AppLog( " >> RTSPServer, OnSocketReadyToSend " );
}

void RTSPServer::OnSocketAccept(Socket& _socket){
	AppLog( " >> RTSPServer, OnSocketAccept " );
	Socket* _pNewSocket = _socket.AcceptN();
	if( !_pNewSocket ){
		return;
	}

	// SocketUtility converts network short to host short values. for ntohs function
	SocketUtility sockUtils;
	sockUtils.Construct();
	const NetEndPoint* pClientNetEndPoint = _pNewSocket->GetLocalEndPoint();
	unsigned short clientPort = sockUtils.NtoHS( pClientNetEndPoint->GetPort() );

	// create one rtsp socket
	RTSPSocket* clientRTSPSocket = new RTSPSocket( _pNewSocket, clientPort );
	RTSPThreadData* pThreadData = new RTSPThreadData( getMP3Path(), clientRTSPSocket );

	// 1client = 1thread, this RTSP Logic instance is managed with Threadmanager.
	// start thread
	RTSPContextLogic* pRTSPLogic = new RTSPContextLogic( pThreadData );
	clientRTSPSocket->addSocketListener( pRTSPLogic->getSocketListener() );

	SingletonManager<ServerResource>::getInstance().getThreadManager()->RegisterThread( pRTSPLogic );
	pRTSPLogic->Construct();
	pRTSPLogic->Start();

}
