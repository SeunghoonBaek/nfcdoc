#include "ServerResource.h"

ServerResource::ServerResource() 
	: 
	// mContentManager(nullptr),
	// mClientManager(nullptr),
	m_pSessionManager(NULL),
	m_pDateManager(NULL),
	m_pPortNumManager(NULL),
	m_pLogManager(NULL),
	m_pThreadManager(NULL) {

	// mContentManager = new ContentManager;
	// mClientManager = new ClientManager();

	m_pPacketManager = new PacketManager();
	m_pSessionManager = new SessionManager();
	m_pDateManager = new DateManager();
	m_pPortNumManager = new PortNumManager();
	m_pLogManager = new LogManager();
	m_pThreadManager = new ThreadManager();
}

ServerResource::~ServerResource(){
	// delete mContentManager;
//	if( mClientManager ){
//		delete mClientManager;
//		mClientManager = NULL;
//	}

	if( m_pPacketManager ){
		delete m_pPacketManager;
		m_pPacketManager = NULL;
	}
	
	if( m_pSessionManager ){
		delete m_pSessionManager;
		m_pSessionManager = NULL;
	}

	if( m_pDateManager ){
		delete m_pDateManager;
		m_pDateManager = NULL;
	}
	
	if( m_pPortNumManager ){
		delete m_pPortNumManager;
		m_pPortNumManager = NULL;
	}

	if( m_pLogManager ){
		delete m_pLogManager;
		m_pLogManager = NULL;
	}

	if( m_pThreadManager ){
		delete m_pThreadManager;
		m_pThreadManager = NULL;
	}
}

// inline const ContentManger * const getContentManager(){ return mClientManager; }
// ClientManager* ServerResource::getClientManager(){ return mClientManager; }

PacketManager* ServerResource::getPacketManager(){
	return m_pPacketManager;
}
SessionManager* ServerResource::getSessionManager() {
	return m_pSessionManager;
}
DateManager* ServerResource::getDateManager(){
	return m_pDateManager;
}
PortNumManager* ServerResource::getPortNumManager(){
	return m_pPortNumManager;
}
LogManager* ServerResource::getLogManager(){
	return m_pLogManager;
}
ThreadManager* ServerResource::getThreadManager(){
	return m_pThreadManager;
}
