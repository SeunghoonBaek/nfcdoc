#ifndef _RTSPSERVER_H_
#define _RTSPSERVER_H_

#include <string>
#include <FBase.h>
#include <FApp.h>
#include <FSystem.h>
#include <FUi.h>
#include <FBaseLog.h>

using namespace Tizen::Base;
using namespace Tizen::Net::Sockets;

using std::string;

#include "RTSPSocket.h"
#include "SingletonManager.h"
#include "RTSPContextLogic.h"
#include "ServerResource.h"
#include "RTSPThreadData.h"

class RTSPServer : public Tizen::Net::Sockets::ISocketEventListener{
public :
	RTSPServer(string _mp3Path = "");
	~RTSPServer();

	bool					StartServer();
	void					CloseServer();

	static void			setMP3Path(string _path);
	static string		getMP3Path();
	
	RTSPSocket*		getListenSocket();
	bool					getIsStartServer();
	void					setIsStartServer(bool _isServerServer);


// ISocketEvenetListener Methods
private :
	virtual void OnSocketConnected(Socket& socket);
	virtual void OnSocketClosed(Socket& socket, NetSocketClosedReason reason);
	virtual void OnSocketReadyToReceive(Socket& socket);
	virtual void OnSocketReadyToSend(Socket& socket);
	virtual void OnSocketAccept(Socket& _socket);
	
private :
	RTSPSocket mListenRTSPSocket;
	static string mMP3Path;
	bool mIsStartServer;
};

#endif
