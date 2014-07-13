#include "MPAudio/LameTag.h"

char* LAMETag::m_szVBRInfo[10] = 
{
	"Unknown",
	"CBR",
	"ABR",
	"VBR1",
	"VBR2",
	"VBR3",
	"VBR4",
	"Reserved",
	"CBR2Pass",
	"ABR2Pass"
};


LAMETag* LAMETag::FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd)
{
	// check for LAME Tag extension (always 120 bytes after XING ID)
	int dwOffset = dwBegin + 120;

	 unsigned char* pBuffer = pStream->ReadBytes(9, dwOffset, false);
	if (memcmp(pBuffer, "LAME", 4) == 0)
		return new LAMETag(pStream, bAppended, dwOffset);

	return NULL;
}

LAMETag::LAMETag(MPAStream* pStream, bool bAppended, int dwOffset) :
	Tag(pStream, "LAME", bAppended, dwOffset)
{
	 unsigned char* pBuffer = pStream->ReadBytes(20, dwOffset, false);

	std::string strVersion = std::string((char*)pBuffer+4, 4);

	// m_fVersion = (float)stof(strVersion);
	const char* tempStrVersionAtStd = strVersion.c_str();
	String tizenStrVersion( tempStrVersionAtStd );
	Float::Parse( tizenStrVersion, m_fVersion );


	// LAME prior to 3.90 writes only a 20 byte encoder string
	if (m_fVersion < 3.90)
	{
		m_bSimpleTag = true;
		m_strEncoder = std::string((char*)pBuffer, 20);
	}
	else
	{
		m_bSimpleTag = false;
		m_strEncoder = std::string((char*)pBuffer, 9);
		dwOffset += 9;

		// cut off last period
		if (m_strEncoder[8] == '.'){
			std::string::iterator itr = m_strEncoder.begin();
			for( int i = 0; i < 8 ; i++, ++itr);
			m_strEncoder.erase( itr );
		}

		// version information
		 unsigned char bInfoAndVBR = *(pStream->ReadBytes(1, dwOffset));

		// revision info in 4 MSB
		m_bRevision = bInfoAndVBR & 0xF0;
		// invalid value
		if (m_bRevision == 15)
			throw NULL;

		// VBR info in 4 LSB
		m_bVBRInfo = bInfoAndVBR & 0x0F;

		// lowpass information
		m_dwLowpassFilterHz = *(pStream->ReadBytes(1, dwOffset)) * 100;

		// skip replay gain values
		dwOffset += 8;

		// skip encoding flags
		dwOffset += 1;

		// average bitrate for ABR, bitrate for CBR and minimal bitrat for VBR [in kbps]
		// 255 means 255 kbps or more
		m_bBitrate = *(pStream->ReadBytes(1, dwOffset)); 
	}
}

LAMETag::~LAMETag(void)
{
}

bool LAMETag::IsVBR() const
{
	if (m_bVBRInfo >= 3 && m_bVBRInfo <= 6)
		return true;
	return false;
}

bool LAMETag::IsABR() const
{
	if (m_bVBRInfo == 2 || m_bVBRInfo == 9)
		return true;
	return false;
}

bool LAMETag::IsCBR() const
{
	if (m_bVBRInfo == 1 || m_bVBRInfo == 8)
		return true;
	return false;
}

 char* LAMETag::GetVBRInfo() const
{
	if (m_bVBRInfo > 9)
		return m_szVBRInfo[0];

	return m_szVBRInfo[m_bVBRInfo];
}
