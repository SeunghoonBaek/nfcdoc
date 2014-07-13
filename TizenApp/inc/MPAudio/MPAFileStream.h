#ifndef _MPAFILESTREAM_H_
#define _MPAFILESTREAM_H_

#include <cstdio>
#include <string.h>
#include "MPAStream.h"

class MPAFileStream : public MPAStream {

public:
	MPAFileStream(  char* szFilename);
	MPAFileStream(  char* szFilename, void* hFile);
	virtual ~MPAFileStream(void);

public :
	int getBufferSize() const;			// temp buffer size
	int getBufferDataSize() const;	// return buffer data of frame

private:
	static const int INIT_BUFFERSIZE;		// initialize buffer size
	FILE* m_hFile;									// file handle of mp3 file
	bool m_bMustReleaseFile;					// decide file handle on destroy

	mutable unsigned char* m_pBuffer;		// temp byte buffer
	mutable int m_dwOffset;					// offset (beginning if m_pBuffer)
	mutable int m_dwBufferSize;				// m_pBuffer size
	mutable int m_iBufferDataSize;			// real data size in m_pBuffer

	// initialize MPAFileStream Object
	void Init();

	// Read on the handled file
	int Read(unsigned char* pData, int dwOffset, int dwSize) const;

	// fill buffer data on m_pBuffer
	bool FillBuffer(int dwOffset, int dwSize, bool bReverse) const;

	// move offset using fssek
	void SetPosition(int dwOffset) const;

protected:
	virtual  unsigned char* ReadBytes(int dwSize, int& dwOffset, bool bMoveOffset = true, bool bReverse = false) const;
	virtual int GetSize() const;
};
#endif
