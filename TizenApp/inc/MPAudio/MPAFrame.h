#ifndef _MPAFRAME_H_
#define _MPAFRAME_H_


#include "MPAStream.h"
#include "MPAHeader.h"
#include "VBRHeader.h"
#include "VBRIHeader.h"
#include "XINGHeader.h"

class MPAFrame {

public:
	MPAFrame(MPAStream* pStream, int& dwOffset, bool bFindSubsequentFrame, bool bExactOffset, bool bReverse, MPAHeader* pCompareHeader);
	~MPAFrame(void);

	// find vbr header without cbr
	VBRHeader* FindVBRHeader() const;
	
	// return byte buffer pointer
	unsigned char* getFrameBuffer();

	// return current frame offset
	inline int GetSubsequentHeaderOffset() const { return m_dwOffset + m_dwFrameSize; };

	// check crc code for check right frame
	bool CheckCRC() const;

	// is this frame last?
	inline bool IsLast() const { return m_bIsLast; };
	
public:
	MPAHeader* m_pHeader;			// frame's header
	MPAStream* m_pStream;			// read & write stream object
	int m_dwOffset;						// frame offset
	int m_dwFrameSize;					// real frame size

private:

	// Protect value table on the MPEG 1 Layer 2
	static const int m_dwProtectedBitsLayer2[5][2];

	// crc protect value
	static short CalcCRC16( unsigned char* pBuffer, int dwSize);

	// is this lastframe?
	bool m_bIsLast;
};

#endif
