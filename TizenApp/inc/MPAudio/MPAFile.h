// MPAFile.h
// controls files of mpeg layer 1, layer 2, and have some of frame object, tag data
#ifndef _MPAFILE_H_
#define _MPAFILE_H_

#include "MPAException.h"
#include "MPAFileStream.h"
#include "MPAFrame.h"
#include "Tags.h"

// range of SAFE_PADDING_BIT_FOR_PREV_BIT, searching next bit value
#define SAFE_PADDING_BIT_FOR_PREV_BIT 1

class MPAFile {
public:
	MPAFile( char* szFile);
	MPAFile(MPAStream* pStream);
	~MPAFile(void);

	// begin tag
	int GetBegin() const { return m_pTags->GetBegin(); };

	// end of tag
	int GetEnd() const { return m_pTags->GetEnd(); };

	// except of tag part, return file size
	int GetFileSize() const { return (GetEnd() - GetBegin()); };

	// return length data of having frame data
	int GetLengthSec() const { return (GetFileSize() / m_dwBytesPerSec); };

	// return of play time per millisecond
	int getPlayTimeSec() ;

	int getTotalFrameCount();
	
	// hope to want to get frame type
	enum GetType
	{
		First,
		Last,
		Next,
		Prev,
		Resync
	};

	// get current frame or next frame
	MPAFrame* GetFrame(GetType Type, MPAFrame* pFrame = NULL, bool bDeleteOldFrame = true, int dwOffset = 0);
	
private:
	void CalcBytesPerSec();
	void CalcTotalFrameCount();

	MPAStream* m_pStream;			// controls mp3 files it does move byte or clear buffer function
	int m_dwBytesPerSec;				// byte second
	int m_iTotalFrameCount;			// total frame count
	int m_iEachFrameMillisecond;		// each frame's player time on millisecond

public:	
	Tags* m_pTags;						// tag pointer
	MPAFrame* m_pFirstFrame;		// first frame pointer
	VBRHeader* m_pVBRHeader;		// if they haven't cbr header
};


#endif
