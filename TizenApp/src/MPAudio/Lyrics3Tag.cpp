#include "MPAudio/Lyrics3Tag.h"
#include "MPAudio/MPAException.h"

Lyrics3Tag* Lyrics3Tag::FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd)
{
	// stands at the end of file
	int dwOffset = dwEnd - 9;
	 unsigned char* pBuffer = pStream->ReadBytes(9, dwOffset, false, true);

	// is it Lyrics 2 Tag
	if (memcmp("LYRICS200", pBuffer, 9) == 0)
		return new Lyrics3Tag(pStream, dwOffset, true);
	else if (memcmp("LYRICSEND", pBuffer, 9) == 0)
		return new Lyrics3Tag(pStream, dwOffset, false);
	
	return NULL;
}

Lyrics3Tag::Lyrics3Tag(MPAStream* pStream, int dwOffset, bool bVersion2) :
	Tag(pStream, "Lyrics3", true, dwOffset)
{
	 unsigned char* pBuffer;
	if (bVersion2)
	{
		SetVersion(2);
		
		// look for size of tag (stands before dwOffset)
		dwOffset -= 6;
		pBuffer = pStream->ReadBytes(6, dwOffset, false); 

		// add null termination
		char szSize[7];
		memcpy(szSize, pBuffer, 6);
		szSize[6] = '\0';

		// convert string to integer
		m_dwSize = atoi(szSize); 
		m_dwOffset = dwOffset - m_dwSize;
		m_dwSize += 6 + 9;	// size must include size info and end string
	}
	else
	{
		SetVersion(1);

		// seek back 5100 bytes and look for LYRICSBEGIN
		m_dwOffset -= 5100;
		pBuffer = pStream->ReadBytes(11, m_dwOffset, false);

		while (memcmp("LYRICSBEGIN", pBuffer, 11) != 0)
		{
			if (dwOffset >= m_dwOffset)
				throw MPAException(MPAException::CorruptLyricsTag);
		}
		m_dwSize = (dwOffset - m_dwOffset) + 9;
	}
}


Lyrics3Tag::~Lyrics3Tag(void)
{
}
