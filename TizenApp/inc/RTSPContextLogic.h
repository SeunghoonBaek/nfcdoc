#ifndef _RTSPCONTEXTLOGIC_H_
#define _RTSPCONTEXTLOGIC_H_

#define DEFAULT_RECV_BUFFER_SIZE 4096
#define DEFAULT_SEND_BUFFER_SIZE 4096

#include <FBase.h>
#include <FApp.h>
#include <FNet.h>

#include <string>
#include <map>
using std::map;
using std::string;
using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;

#include "Client.h"
#include "ServerResource.h"
#include "SingletonManager.h"
#include "PacketDescriptor.h"
#include "StringConvertor.h"
#include "RTSPThreadData.h"

class RTSPServer;
class PacketDescriptor;


class RTSPContextLogic : public Thread, public ISocketEventListener{
public :
	RTSPContextLogic( RTSPThreadData* _pThreadData );
	virtual ~RTSPContextLogic();

	// Thread function
	result Construct();
	Object* Run();

	// Arguments
	void 								setThreadData( RTSPThreadData* _pRTSPData );
	ISocketEventListener* 		getSocketListener();

private :
	void CloseRTSPLogic();
	void OnReceiveLogic();

// ISocketEventListner
private :
	void OnSocketAccept(Socket& _socket);
	void OnSocketConnected(Socket& socket);
	void OnSocketClosed(Socket& socket, NetSocketClosedReason reason);
	void OnSocketReadyToReceive(Socket& socket);
	void OnSocketReadyToSend(Socket& socket);

private :
	RTPSocket 					mRTPSocket;
	RTSPThreadData* 		m_pThreadData;
	Client 						mServiceClient;

	char 							mRecvBuffer[DEFAULT_RECV_BUFFER_SIZE];
	char 							mSendBuffer[DEFAULT_SEND_BUFFER_SIZE];
	int 							mRecvSize;
	int 							mSendSize;
};

#endif



/*
	// default server - client process logic on one thread
	static void ContextLogic(RTSPThreadData* _pRTSPData){
		if( !m_pTheadData )
			return;

		RTSPSocket* _client = _pRTSPData->mRTSPSocket;

		 StringConvertor stringConvertor;
		 Client serviceClient;
		 serviceClient.setRTSPSocket(_client);
		 serviceClient.setMP3Path(_pRTSPData->mMP3Path); 

		 ServerResource& resource = SingletonManager<ServerResource>::getInstance();
		 // resource.getClientManager()->AddClient(&serviceClient);

		 delete _pRTSPData;

		 // set buffers
		 char recvBuffer[DEFAULT_RECV_BUFFER_SIZE];
		 char sendBuffer[DEFAULT_SEND_BUFFER_SIZE];
		 int recvSize = 0;
		 int sendSize = 0;
		 bool isSafeClient = true;

		 while( isSafeClient ){
			 // ��Ŷ�� Ŭ���̾�Ʈ�κ��� ����( come request packet )
			 recvSize = serviceClient.getRTSPSocket()->ReadData(recvBuffer, sizeof(recvBuffer));

			 // Ŭ���̾�Ʈ ����
			 if( recvSize == -1 ) {
				 isSafeClient = false;
				 serviceClient.setIsConnectRTPThread(false);
				 break;
			 }

			 // ��Ŷ���κ��� Context ȹ��( sessionid, sequence number )
			 DescriptorResult* packetContextResult = PacketDescriptor::getPacketResult( recvBuffer, recvSize );
			 if( packetContextResult == nullptr ) continue;

			 // save context from descriptor result.
			serviceClient.setDescriptorResult( packetContextResult );

			// �޼ҵ� �̸��� ������ ��
			string methodName;
			if( !strcmp("OPTIONS", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_OPTIONS";
			}
			else if( !strcmp("DESCRIBE", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_DESCRIBE";
			} 
			else if( !strcmp("SETUP", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_SETUP";
			}
			else if( !strcmp("PLAY", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_PLAY";
			}
			else if( !strcmp("PAUSE", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_PAUSE";
			}
			else if( !strcmp("TEARDOWN", serviceClient.getContext().getMethodType().c_str()) ){
				methodName = "RES_TEARDOWN";
			}

			// �޼ҵ� �̸��� �´� ��Ŷ ��⸦ ����
			shared_ptr<IPacketBase> packetCreator = resource.getPacketManager()->getPacket(methodName);
			string packet = packetCreator->getPacket(serviceClient);
			packet = stringConvertor.ANSIToUTF8(packet.c_str());

			// ��� ��Ŷ�� ũ�Ⱑ ��۹��ۺ��� ũ�Ⱑ ũ�ٸ� Large ���۸� ���� �����
			if( packet.length() > DEFAULT_SEND_BUFFER_SIZE ){
				char* largeBuffer = new char[ packet.length() + 1 ];
				memcpy( largeBuffer, packet.c_str(), packet.length() );
				sendSize = serviceClient.getRTSPSocket()->WriteData( largeBuffer, packet.length() );
				delete[] largeBuffer;
			}
			else{
				memcpy( sendBuffer, packet.c_str(), packet.length() );
				sendSize = serviceClient.getRTSPSocket()->WriteData(sendBuffer, packet.length() );
			}

			 // free resource
			serviceClient.setDescriptorResult( 0 );
			delete packetContextResult;
		 }

		 // resource.getClientManager()->RemoveClient(&serviceClient);
		 cout << " >> [ContextLogic] Close Client : " << serviceClient.getClientID() << ", Check Socket Error : " << WSAGetLastError() << "\n\n";
	 }
*/
