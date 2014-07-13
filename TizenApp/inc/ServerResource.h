#ifndef _SERVERRESOURCES_H_
#define _SERVERRESOURCES_H_


#include "PacketManager.h"
// #include "ClientManager.h"
#include "ContentManager.h"
#include "SessionManager.h"
#include "DateManager.h"
#include "PortNumManager.h"
#include "LogManager.h"
#include "ThreadManager.h"

class PacketManager;

class ServerResource{
public :
	ServerResource();
	~ServerResource();

	// inline const ContentManger * const getContentManager(){ return mClientManager; }
	// ClientManager* getClientManager();

	PacketManager* 				getPacketManager();
	SessionManager* 			getSessionManager();
	DateManager* 				getDateManager();
	PortNumManager* 			getPortNumManager();
	LogManager* 					getLogManager();
	ThreadManager* 				getThreadManager();

private :
	// ContentManager* 		mContentManager;
	// ClientManager* 			mClientManager;

	PacketManager* 				m_pPacketManager;
	SessionManager* 			m_pSessionManager;
	DateManager* 				m_pDateManager;
	PortNumManager* 			m_pPortNumManager;
	LogManager* 					m_pLogManager;
	ThreadManager* 				m_pThreadManager;
};

#endif
