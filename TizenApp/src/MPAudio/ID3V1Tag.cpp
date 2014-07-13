#include "MPAudio/ID3V1Tag.h"


ID3V1Tag* ID3V1Tag::FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd)
{
	if (bAppended)
	{
		// stands 128 byte before file end
		int dwOffset = dwEnd - 128;
		 unsigned char* pBuffer = pStream->ReadBytes(3, dwOffset, false);
		if (memcmp("TAG", pBuffer, 3)==0)
			return new ID3V1Tag(pStream, dwOffset);
	}
	return NULL;
}


ID3V1Tag::ID3V1Tag(MPAStream* pStream, int dwOffset) :
	Tag(pStream, "ID3", true, dwOffset, 128)
{
	dwOffset += 125;
	 unsigned char* pBuffer = pStream->ReadBytes(2, dwOffset, false);

	bool bIsV11 = false;
	// check if V1.1 tag (byte 125 = 0 and byte 126 != 0)
	if (pBuffer[0] == '\0' && pBuffer[1] != '\0')
		bIsV11 = true;
	SetVersion(1,(bIsV11?1:0));
}

ID3V1Tag::~ID3V1Tag(void)
{
}
