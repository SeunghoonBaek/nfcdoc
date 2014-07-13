#ifndef _PORTNUM_H_
#define _PORTNUM_H_

class PortNum{
public :
	PortNum( int _portNumStart = -1, int _portNumCount = -1, bool _isUsablePort = false ) 
		: mPortNumStart(_portNumStart), mPortNumCount(_portNumCount), mIsUsablePort(_isUsablePort){}

	inline int getPortNumStart(){return mPortNumStart;}
	inline int getPortNumCount(){ return mPortNumCount;}
	inline bool getIsUablePort(){ return mIsUsablePort;}
	inline PortNum& setUsablePort(bool _isUsable ){ 
		mIsUsablePort = _isUsable;
		return *this; 
	}

	PortNum& operator=(const PortNum& rhs){
		mPortNumStart = rhs.mPortNumStart;
		mPortNumCount = rhs.mPortNumCount;
		mIsUsablePort = rhs.mIsUsablePort;
		return *this;
	}

private :
	int mPortNumStart;
	int mPortNumCount;
	bool mIsUsablePort;
};

#endif