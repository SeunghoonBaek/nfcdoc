#include "MPAudio/XINGHeader.h"

// for XING VBR Header flags
#define FRAMES_FLAG     0x0001
#define  charS_FLAG      0x0002
#define TOC_FLAG        0x0004
#define VBR_SCALE_FLAG  0x0008

// offset of XING header: after side information in Layer III


XINGHeader* XINGHeader::FindHeader(const MPAFrame* pFrame)
{
	// where does VBR header begin (XING)
	int dwOffset = pFrame->m_dwOffset + MPA_HEADER_SIZE + pFrame->m_pHeader->GetSideInfoSize();// + (pFrame->m_pHeader->m_bCRC?2:0);

	// check for XING header first
	if (!CheckID(pFrame->m_pStream, dwOffset, 'X', 'i', 'n', 'g') && !CheckID(pFrame->m_pStream, dwOffset,'I', 'n', 'f', 'o'))
		return NULL;
	
	return new XINGHeader(pFrame, dwOffset);
}

XINGHeader::XINGHeader(const MPAFrame* pFrame, int dwOffset) :
	VBRHeader(pFrame->m_pStream, dwOffset)
{
	/* XING VBR-Header

	 size	description
	 4		'Xing' or 'Info'
	 4		flags (indicates which fields are used)
	 4		frames (optional)
	 4		unsigned chars (optional)
	 100	toc (optional)
	 4		a VBR quality indicator: 0=best 100=worst (optional)

	*/
	
	// XING ID already checked at this point
	dwOffset += 4;
	int dwFlags;

	// get flags (mandatory in XING header)
	dwFlags = m_pStream->ReadBEValue(4, dwOffset); 

	// extract total number of frames in file
	if(dwFlags & FRAMES_FLAG)
		m_dwFrames = m_pStream->ReadBEValue(4, dwOffset);

	// extract total number of unsigned chars in file
	if(dwFlags &  charS_FLAG) 
		m_dwBytes = m_pStream->ReadBEValue(4, dwOffset);
	
	// extract TOC (for more accurate seeking)
	if (dwFlags & TOC_FLAG) 
	{
		m_dwTableSize = 100;
		m_pnToc = new int[m_dwTableSize];

		if (m_pnToc)
		{
			for(int i=0;i<m_dwTableSize;i++)
				m_pnToc[i] = *m_pStream->ReadBytes(1, dwOffset);
		}
	}

	if (dwFlags & VBR_SCALE_FLAG)
		m_dwQuality = m_pStream->ReadBEValue(4, dwOffset);

	m_pLAMETag = LAMETag::FindTag(m_pStream, true, m_dwOffset, 0);
}

XINGHeader::~XINGHeader(void)
{
	if (m_pLAMETag)
		delete m_pLAMETag;
}

int XINGHeader::SeekPosition(float& fPercent) const
{
	// interpolate in TOC to get file seek point in unsigned chars
	int a;
	float fa, fb, fx;

	a = (int)fPercent;
	fa = (float)m_pnToc[a];
	
	if (a < 99) 
	{
		fb = (float)m_pnToc[a+1];
	}
	else 
	{
		fb = 256.0f;
	}

	fx = fa + (fb-fa)*(fPercent-a);

	return (int)((1.0f/256.0f)*fx*m_dwBytes); 
}
