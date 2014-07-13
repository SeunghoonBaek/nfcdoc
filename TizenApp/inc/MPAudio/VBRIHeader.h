#ifndef _VBRIHEADER_H_
#define _VBRIHEADER_H_


#include "MPAFrame.h"
#include "VBRHeader.h"


class VBRIHeader : public VBRHeader {
public:
	static VBRIHeader* FindHeader(const MPAFrame* pFrame);

	VBRIHeader(const MPAFrame* pFrame, int dwOffset);
	virtual ~VBRIHeader(void);

	virtual int SeekPosition(float& fPercent) const;
	int SeekPositionByTime(float fEntryTimeMS) const;

	// these values exist only in VBRI headers
	float m_fDelay;	
	int m_dwTableScale;	// for seeking
	int m_dwBytesPerEntry;;
    int m_dwFramesPerEntry;
	int m_dwVersion;
private:
	int m_dwLengthSec;
};
#endif
