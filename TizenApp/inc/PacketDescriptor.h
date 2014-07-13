#ifndef _PACKETDESCRIPTOR_H_
#define _PACKETDESCRIPTOR_H_

#include <stdlib.h>
#include <string.h>
#include <string>
using std::string;

#include "DescriptorResult.h"
class PacketDescriptor{
public :

	// Ŭ���̾�Ʈ�κ��� ���� data���� SessionID�� SequenceNumber �� ȹ����
	static DescriptorResult* getPacketResult(char* _data, int _dataSize ) {
		static char mCopyableDataField[MAX_COPY_BUFFER_SIZE];
		if( _data == NULL || _data == NULL || _dataSize == 0 )
			return NULL;

		memset( mCopyableDataField, 0, sizeof(mCopyableDataField ) );
		memcpy( mCopyableDataField, _data, _dataSize );

		Context remoteContext;
		
		char* tok = strtok( mCopyableDataField, "\r\n");
		if( tok == NULL  )
			return NULL;

		char* method = strchr( tok, ' ');

		// Method Name
		if( method ){
			int methodStrSize = method - tok;
			char methodName[32] = {0,};
			strncpy( methodName, tok, methodStrSize );
			remoteContext.setMethodType(methodName);
		}

		do{
			
			// Sequence Number
			char* seqStr = strstr( tok, "CSeq: ");
			if( seqStr ){
				int iSeq = atoi( seqStr + 6);
				remoteContext.setSequenceNumber( iSeq );
			}

			// Session ID
			char* sessionStr = strstr( tok, "Session: ");
			if( sessionStr ){
				int tagLength = strlen( "Session: " );
				int sessionDataLength = strlen( sessionStr );
				char* sessionID = new char[ sessionDataLength - tagLength + 1 ];
				strncpy( sessionID, sessionStr + tagLength, sessionDataLength - tagLength );
				sessionID[sessionDataLength - tagLength] = '\0';

				remoteContext.setSessionID( sessionID );
			}

			tok = strtok(NULL, "\r\n");
		}while( tok != NULL);

		DescriptorResult* dResult = new DescriptorResult(remoteContext, _data, _dataSize );
		return dResult;
	}

private:
	static const int MAX_COPY_BUFFER_SIZE = 1024 * 10;
	

	PacketDescriptor(){}
	~PacketDescriptor(){}
};

#endif
