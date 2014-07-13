#ifndef _DESCRIPTORRESULT_H_
#define _DESCRIPTORRESULT_H_

#include "Context.h"

// received client data. simple of client state
class DescriptorResult{
public :
	DescriptorResult(Context _context, char* _packetData = NULL, int _packetSize = 0 ) : mContext( _context ), mPacketData( _packetData), mPacketSize( _packetSize ){}
	Context mContext;
	char* mPacketData;
	int mPacketSize;
};

#endif
