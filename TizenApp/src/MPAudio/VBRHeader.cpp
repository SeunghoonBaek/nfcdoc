#include "MPAudio/MPAFrame.h"	// also includes vbrheader.h

#include "MPAudio/XINGHeader.h"
#include "MPAudio/VBRIHeader.h"

// first test with this static method, if it does exist
VBRHeader* VBRHeader::FindHeader(const MPAFrame* pFrame)
{
	if( !pFrame ){
		return NULL;
	}

	// _ASSERTE(pFrame);
	VBRHeader* pVBRHeader = NULL;

	pVBRHeader = XINGHeader::FindHeader(pFrame);
	if (!pVBRHeader)
		pVBRHeader = VBRIHeader::FindHeader(pFrame);
	
	return pVBRHeader;
}

VBRHeader::VBRHeader(MPAStream* pStream, int dwOffset) :
	m_pStream(pStream), m_pnToc(NULL), m_dwOffset(dwOffset), m_dwFrames(0), m_dwBytes(0), m_dwQuality(0), m_dwTableSize(0)
{
}

bool VBRHeader::CheckID(MPAStream* pStream, int dwOffset, unsigned char ch0, unsigned char ch1, unsigned char ch2, unsigned char ch3)
{
	 unsigned char* pBuffer = pStream->ReadBytes(4, dwOffset, false);
	if (pBuffer[0] == ch0 && pBuffer[1] == ch1 && pBuffer[2] == ch2 && pBuffer[3] == ch3)
		return true;
	return false;
}

/*
// currently not used
bool CVBRHeader::ExtractLAMETag( int dwOffset )
{
	// LAME ID found?
	if( !CheckID( m_pMPAFile, dwOffset, 'L', 'A', 'M', 'E' ) && !CheckID( m_pMPAFile, dwOffset, 'G', 'O', 'G', 'O' ) )
		return false;

	return true;
}*/



VBRHeader::~VBRHeader(void)
{
	if (m_pnToc)
		delete[] m_pnToc;
}

// get unsigned char position for percentage value (fPercent) of file
bool VBRHeader::SeekPosition(float& fPercent, int& dwSeekPoint) const
{
	if (!m_pnToc || m_dwBytes == 0)
		return false;

	// check range of fPercent
	if (fPercent < 0.0f)   
		fPercent = 0.0f;
	if (fPercent > 99.0f) 
		fPercent = 99.0f;

	dwSeekPoint = SeekPosition(fPercent);
	return true;
}
