#ifndef _XINGHEADER_H_
#define _XINGHEADER_H_

#include "MPAFrame.h"
#include "VBRHeader.h"
#include "LameTag.h"


class XINGHeader : public VBRHeader {
public:
	static XINGHeader* FindHeader(const MPAFrame* pFrame);

	XINGHeader(const MPAFrame* pFrame, int dwOffset);
	virtual ~XINGHeader(void);

	virtual int SeekPosition(float& fPercent) const;

	LAMETag* m_pLAMETag;
};

#endif
