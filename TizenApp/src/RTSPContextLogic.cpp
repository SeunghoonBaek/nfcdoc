#include "RTSPContextLogic.h"

RTSPContextLogic::RTSPContextLogic( RTSPThreadData* _pThreadData ) : m_pThreadData( _pThreadData ) {

}

RTSPContextLogic::~RTSPContextLogic(){
	CloseRTSPLogic();
}

void RTSPContextLogic::CloseRTSPLogic(){
	if( m_pThreadData ){
		delete m_pThreadData;
		m_pThreadData = 0;
	}
}

result RTSPContextLogic::Construct(){
	return Thread::Construct();
}

void RTSPContextLogic::setThreadData( RTSPThreadData* _pRTSPData ){
	m_pThreadData = _pRTSPData;
}

ISocketEventListener* RTSPContextLogic::getSocketListener(){
	return this;
}

Object* RTSPContextLogic::Run(){
	if( m_pThreadData == NULL )
		return NULL;

	RTSPSocket* _pClient = m_pThreadData->m_pRTSPSocket;
	if( !_pClient )
		return NULL;

	Socket* _pSocket = _pClient->getSocket();
	if( !_pSocket ){
		return NULL;
	}

	// Add socket listener to listen to socket event
	_pSocket->AddSocketListener(*this);

	// Set the socket to select an interesting event
	_pSocket->AsyncSelectByListener( NET_SOCKET_EVENT_READ | NET_SOCKET_EVENT_CLOSE);


	mServiceClient.setRTSPSocket(_pClient);
	mServiceClient.setMP3Path(m_pThreadData->mMP3Path);
	return NULL;
}

void RTSPContextLogic::OnReceiveLogic(){
	mRecvSize = 0;
	mSendSize = 0;
	ServerResource& resource = SingletonManager<ServerResource>::getInstance();

	// ��Ŷ�� Ŭ���̾�Ʈ�κ��� ����( come request packet )

	mServiceClient.getRTSPSocket()->getSocket()->Receive(mRecvBuffer, sizeof(mRecvBuffer), mRecvSize);
	// ReadData(mRecvBuffer, sizeof(mRecvBuffer));

	// Ŭ���̾�Ʈ ����
	if( mRecvSize == -1 ) {
		mServiceClient.setIsConnectRTPThread(false);
		return;
	}

	// ��Ŷ���κ��� Context ȹ��( sessionid, sequence number )
	DescriptorResult* packetContextResult = PacketDescriptor::getPacketResult( mRecvBuffer, mRecvSize );
	if( packetContextResult == NULL )
		return;

	// save context from descriptor result.
	mServiceClient.setDescriptorResult( packetContextResult );

	// �޼ҵ� �̸��� ������ ��
	string methodName;
	if( !strcmp("OPTIONS", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_OPTIONS";
	}
	else if( !strcmp("DESCRIBE", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_DESCRIBE";
	}
	else if( !strcmp("SETUP", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_SETUP";
	}
	else if( !strcmp("PLAY", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_PLAY";
	}
	else if( !strcmp("PAUSE", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_PAUSE";
	}
	else if( !strcmp("TEARDOWN", mServiceClient.getContext().getMethodType().c_str()) ){
		methodName = "RES_TEARDOWN";
	}

	// �޼ҵ� �̸��� �´� ��Ŷ ��⸦ ����
	IPacketBase* packetCreator = resource.getPacketManager()->getPacket(methodName);
	if(! packetCreator ){
		return;
	}

	string packet = packetCreator->getPacket( mServiceClient );

//	StringConvertor stringConvertor;
//	packet = stringConvertor.ANSIToUTF8(packet.c_str());

	// ��� ��Ŷ�� ũ�Ⱑ ��۹��ۺ��� ũ�Ⱑ ũ�ٸ� Large ���۸� ���� �����
	if( packet.length() > DEFAULT_SEND_BUFFER_SIZE ){
		char* largeBuffer = new char[ packet.length() + 1 ];
		memcpy( largeBuffer, packet.c_str(), packet.length() );
		mSendSize = mServiceClient.getRTSPSocket()->WriteData( largeBuffer, packet.length() );
		delete[] largeBuffer;
	}
	else{
		memcpy( mSendBuffer, packet.c_str(), packet.length() );
		mSendSize = mServiceClient.getRTSPSocket()->WriteData(mSendBuffer, packet.length() );
	}

	// free resource
	mServiceClient.setDescriptorResult( 0 );
	delete packetContextResult;
}

void RTSPContextLogic::OnSocketConnected(Socket& socket){
	AppLog( " >> RTSPCntextLogic, OnSocketConnected");
}
void RTSPContextLogic::OnSocketClosed(Socket& socket, NetSocketClosedReason reason){
	AppLog( " >> RTSPCntextLogic, OnSocketClosed");
	CloseRTSPLogic();

	// AppLog(L"RTSPContextLogic", L"OnSocketClosed, Close Client");
}
void RTSPContextLogic::OnSocketReadyToReceive(Socket& socket){
	AppLog( " >> RTSPCntextLogic, OnSocketReadyToReceive");
	OnReceiveLogic();
}
void RTSPContextLogic::OnSocketReadyToSend(Socket& socket){
	AppLog( " >> RTSPCntextLogic, OnSocketReadyToSend");
}
void RTSPContextLogic::OnSocketAccept(Socket& _socket){
	AppLog( " >> RTSPCntextLogic, OnSocketAccept");
}
