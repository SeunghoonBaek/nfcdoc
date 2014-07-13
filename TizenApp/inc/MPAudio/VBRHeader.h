#ifndef _VBRHEADER_H_
#define _VBRHEADER_H_

// class CMPAFrame must be included first and must be known here
class MPAFrame;
class MPAStream;

class VBRHeader {
public:
	static VBRHeader* FindHeader(const MPAFrame* pFrame);
	virtual ~VBRHeader(void);
	bool SeekPosition(float& fPercent, int& dwSeekPoint) const;

	int m_dwBytes;		// total number of unsigned chars
	int m_dwFrames;		// total number of frames

protected:	
	VBRHeader(MPAStream* pStream, int dwOffset);

	static bool CheckID(MPAStream* pStream, int dwOffset, unsigned char ch0, unsigned char ch1, unsigned char ch2, unsigned char ch3);
	virtual int SeekPosition(float& fPercent) const = 0;
	MPAStream* m_pStream;

public:	
	int m_dwOffset;
	int m_dwQuality;		// quality (0..100)
	int* m_pnToc;			// TOC points for seeking (must be freed)
	int m_dwTableSize;	// size of table (number of entries)	


	
};
#endif