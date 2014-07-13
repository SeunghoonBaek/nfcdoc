#include "MPAudio/ID3V2Tag.h"

ID3V2Tag* ID3V2Tag::FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd)
{
	char* szID;
	int dwOffset;

	if (!bAppended)
	{
		// stands at the beginning of file (complete header is 10 bytes)
		dwOffset = dwBegin;
		szID = "ID3";
	}
	else
	{
		// stands at the end of the file (complete footer is 10 bytes)
		dwOffset = dwEnd - 10;
		szID = "3DI";
		
	}
	 unsigned char* pBuffer = pStream->ReadBytes(10, dwOffset, false);

	if (memcmp(szID, pBuffer, 3) == 0)
		return new ID3V2Tag(pStream, bAppended, dwOffset);
	return NULL;
}


ID3V2Tag::ID3V2Tag(MPAStream* pStream, bool bAppended, int dwOffset) :
	Tag(pStream, "ID3", false, dwOffset)
{
	dwOffset += 3;

	// read out version info
	 unsigned char* pBuffer = m_pStream->ReadBytes(3, dwOffset);
	SetVersion(2, pBuffer[0], pBuffer[1]);
	 unsigned char bFlags = pBuffer[3];
	/*m_bUnsynchronization = (bFlags & 0x80)?true:false;	// bit 7
	m_bExtHeader = (bFlags & 0x40)?true:false;			// bit 6
	m_bExperimental = (bFlags & 0x20)?true:false;		// bit 5*/
	bool bFooter = (bFlags & 0x10)?true:false;				// bit 4

	// convert synchsafe integer
	m_dwSize = GetSynchsafeInteger(m_pStream->ReadBEValue(4, dwOffset)) + (bFooter?20:10);

	// for appended tag: calculate new offset
	if (bAppended)
		m_dwOffset -= m_dwSize - 10;
}

// return for each byte only lowest 7 bits (highest bit always zero)
int ID3V2Tag::GetSynchsafeInteger(int dwValue)
{
	// masks first 7 bits
	const int dwMask = 0x7F000000;
	int dwReturn = 0;
	for (int n=0; n < sizeof(int); n++)
	{
		dwReturn = (dwReturn << 7) | ((dwValue & dwMask) >> 24);
		dwValue <<= 8;
	}
	return dwReturn;
}

ID3V2Tag::~ID3V2Tag(void)
{
}
