#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <string>
using std::string;

class Context{
private :
	static const int DEFAULT_VALUE = -1;

public :
	Context( int _seqNumber = 0, char* _pSessionID = 0, string _methodType = "", void* _extensionData = NULL )
	: mSequenceNumber(_seqNumber),  mMethodType(_methodType), mExtensionData(NULL)
	{
		setSessionID( _pSessionID );
	}

	~Context(){
		//if( mpSessionID ){
		//	delete[] mpSessionID;
		//	mpSessionID = NULL;
		//}
	}

	void operator=(const Context& _context){

		// copy sequence number
		this->mSequenceNumber = _context.mSequenceNumber;

		// copy session id
		mSessionID = _context.mSessionID;

		// copy method type
		this->mMethodType = _context.mMethodType;

		// copy extension data
		this->mExtensionData = _context.mExtensionData;
	}

	inline int						getSequenceNumber(){ return mSequenceNumber; }
	inline void						setSequenceNumber(int _seqNumber ) { mSequenceNumber = _seqNumber; }
	inline const char*			getSessionID(){ return mSessionID.c_str(); }
	inline void						setSessionID(char* _pSessionID ){
		// deep copy
		/*if( _pSessionID ){
			if( mpSessionID ){
				delete[] mpSessionID;
				mpSessionID = NULL;
			}

			mpSessionID = new char[ strlen(_pSessionID) + 1 ];
			strcpy( mpSessionID, _pSessionID );
		}*/

		if( _pSessionID )
			mSessionID = _pSessionID;
	}
	inline string		getMethodType(){ return mMethodType; }
	inline void			setMethodType(string _methodType) { mMethodType = _methodType;}
	inline void*		getExtensionData(){ return mExtensionData; }
	inline void			setExtensionData(void* _extData){ mExtensionData = _extData;}

private :
	int						mSequenceNumber;
	// char*				mpSessionID;
	string					mSessionID;
	string					mMethodType;
	void*				mExtensionData;
};

#endif
