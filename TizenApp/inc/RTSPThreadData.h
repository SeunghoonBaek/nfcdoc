#ifndef _RTSPTHREAD_DATA_H_
#define _RTSPTHREAD_DATA_H_

#include "RTSPSocket.h"
#include <string>
using std::string;

class RTSPThreadData{
public :
	RTSPThreadData( string _mp3Path, RTSPSocket* _pRTSPSocket ) : mMP3Path(_mp3Path), m_pRTSPSocket(_pRTSPSocket ){}
	~RTSPThreadData(){
		if( m_pRTSPSocket ){
			delete m_pRTSPSocket;
			m_pRTSPSocket = 0;
		}
	}

public :
	string 			mMP3Path;
	RTSPSocket* 	m_pRTSPSocket;
};

#endif
