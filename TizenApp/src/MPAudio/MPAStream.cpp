#include "MPAudio/MPAStream.h"
#include "MPAudio/MPAException.h"

// constructor
MPAStream::MPAStream( char* szFilename)
{
	// save filename
	if( szFilename == NULL ) return;

	int filenameLength = strlen( szFilename );
	m_szFile = new char[ filenameLength + 1 ];
	strcpy( m_szFile, szFilename );
}

MPAStream::~MPAStream(void)
{
	if( m_szFile ){
		delete(m_szFile);
		m_szFile = 0;
	}
}

int MPAStream::ReadLEValue(int dwNumBytes, int& dwOffset, bool bMoveOffset) const
{
	 unsigned char* pBuffer = ReadBytes(dwNumBytes, dwOffset, bMoveOffset);

	int dwResult = 0;

	// little endian extract (least significant byte first) (will work on little and big-endian computers)
	int dwNumByteShifts = 0;

	for (int n=0; n < dwNumBytes; n++)
	{
		dwResult |= pBuffer[n] << 8 * dwNumByteShifts++;
	}
	
	return dwResult;
}

// convert from big endian to native format (Intel=little endian) and return as DWORD (32bit)
int MPAStream::ReadBEValue(int dwNumBytes, int& dwOffset,  bool bMoveOffset) const
{
	unsigned char* pBuffer = ReadBytes(dwNumBytes, dwOffset, bMoveOffset);

	int dwResult = 0;

	// big endian extract (most significant byte first) (will work on little and big-endian computers)
	int dwNumByteShifts = dwNumBytes - 1;

	for (int n=0; n < dwNumBytes; n++)
	{
		dwResult |= pBuffer[n] << 8*dwNumByteShifts--; // the bit shift will do the correct byte order for you                                                           
	}
	
	return dwResult;
}
