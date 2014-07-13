#ifndef _CLIENTDOKU_H_
#define _CLIENTDOKU_H_

#include <FBase.h>
#include <string>

using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;
using std::string;

#include "Context.h"
#include "RTSPSocket.h"
#include "RTPSocket.h"
#include "RTPInfo.h"
#include "TransportInfo.h"
#include "DescriptorResult.h"

class Client{
public :
	Client() : mClientID( ++IncraseClientID ), mDescriptorResult(0),mRTPRemotePortNumber(-1),  mRTPLocalPortNumber(-1), m_pClientRTPThread(0) {}
	~Client(){

		if( mRTSPSocket ){
			delete mRTSPSocket;
			mRTSPSocket = 0;
		}
		
		if( mDescriptorResult ){
			delete mDescriptorResult;
			mDescriptorResult = 0;
		}

		if( m_pClientRTPThread ){
			m_pClientRTPThread->Join();
			delete m_pClientRTPThread;
			m_pClientRTPThread = 0;
		}
	}

	static const int CLIENT_METHOD_COUNT = 8;
	enum ClientMethodState{
		OPTION_ON = 0,
		DESCRIBE_ON,
		SETUP_ON,
		PLAY_ON,
		PLAY_DOWN,
		PAUSE_ON,
		PAUSE_DOWN,
		TEARDOWN_ON
	};
	//=================================================================
	// inline methods, getters
	//=================================================================
	inline int								getClientID(){ return mClientID; }
	inline Context 						getContext(){ return mCurrentContext;}
	inline RTSPSocket* 					getRTSPSocket(){ return mRTSPSocket;}
	inline RTPSocket& 					getRTPSocket() { return mRTPSocket;}
	inline string 							getRemoteIP(){ return mRemoteIP; }
	inline int 								getRTPRemotePortNum(){ return mRTPRemotePortNumber;}
	inline int 								getRTPLocalPortNum(){ return mRTPLocalPortNumber;}
	inline RTPInfo& 						getRTPInfo(){ return mRTPInfo; }
	inline TransportInfo& 				getTransportInfo(){ return mTransportInfo; }
	inline DescriptorResult* 			getRecentDescriptorResult(){ return mDescriptorResult; }
	inline string 							getMP3Path(){ return mMP3Path; }
	inline Thread*							getRTPThread(){ return m_pClientRTPThread; }

	//=================================================================
	// inline methods, setters
	//=================================================================
	inline void setContext(const Context& _context ){ mCurrentContext = _context;}
	inline void setRTSPSocket(RTSPSocket* _rtspSocket) { mRTSPSocket = _rtspSocket; }
	inline void setRTPSocket(const RTPSocket& _rtpSocket) { mRTPSocket = _rtpSocket; }
	inline void setRemoteIP(const string _remoteIP){ mRemoteIP = _remoteIP;}
	inline void setRTPInfo(const RTPInfo& _rtpInfo) { mRTPInfo = _rtpInfo; }
	inline void setTransportInfo(const TransportInfo& _transInfo ){ mTransportInfo = _transInfo; }
	inline void setRTPRemotePortNum(const int _rtpRemotePortNum) { mRTPRemotePortNumber = _rtpRemotePortNum; }
	inline void setRTPLocalPortNum(const int _rtpLocalPortNum ) { mRTPLocalPortNumber = _rtpLocalPortNum; }
	inline void setMP3Path(string _mp3Path ){ mMP3Path = _mp3Path; }
	void setDescriptorResult(DescriptorResult* _recentResult ){
		mDescriptorResult = _recentResult; 

		if( mDescriptorResult )
			mCurrentContext = mDescriptorResult->mContext;
	}

	inline void setRTPThread(Thread* _pThread ){ m_pClientRTPThread = _pThread; }

	// overwriting operator method
	Client& operator=(const Client& rhs){
		mCurrentContext = rhs.mCurrentContext;
		mRTSPSocket = rhs.mRTSPSocket;
		mRTPSocket = rhs.mRTPSocket;
		mRemoteIP = rhs.mRemoteIP;
		mRTPInfo = rhs.mRTPInfo;
		mTransportInfo = rhs.mTransportInfo;
		mRTPRemotePortNumber = rhs.mRTPRemotePortNumber;
		mRTPLocalPortNumber = rhs.mRTPLocalPortNumber;
		mDescriptorResult = rhs.mDescriptorResult;
		return *this;
	}

private :
	// not impl
	void FreeObjects(){}

private :
	static int IncraseClientID;

	const int					mClientID;						// client unique id
	Context						mCurrentContext;				// client current state
	RTSPSocket*				mRTSPSocket;					// client rtsp socket
	RTPSocket					mRTPSocket;					// client rtp socket
	string							mRemoteIP;						// remote ip address
	RTPInfo						mRTPInfo;						// client rtp information( not impl )
	TransportInfo				mTransportInfo;				// client transport info
	DescriptorResult* 		mDescriptorResult;			// client packet result context
	int								mRTPRemotePortNumber;	// remote rtp port number
	int								mRTPLocalPortNumber;		// local rtp port number
	// unsigned char		mClientMethodState[CLIENT_METHOD_COUNT];
	string							mMP3Path;
	bool							mIsConnectRTPThread;
	Thread*						m_pClientRTPThread;

public :
	bool getIsConnectRTPThread(){ return mIsConnectRTPThread; }
	void setIsConnectRTPThread(bool _isConnectRTPThread){ mIsConnectRTPThread = _isConnectRTPThread;}
	
};

#endif
