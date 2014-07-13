#ifndef _MPASTREAM_H_
#define _MPASTREAM_H_


#include <string.h>
// interface of file stream
class MPAStream {
public:

	virtual ~MPAStream(void);

	virtual int GetSize() const = 0;
	// read interface
	virtual  unsigned char* ReadBytes(int dwSize, int& dwOffset, bool bMoveOffset = true, bool bReverse = false) const = 0;

	// read big endian method
	int ReadBEValue(int dwNumBytes, int& dwOffset, bool bMoveOffset = true) const;

	// read little endian method
	int ReadLEValue(int dwNumBytes, int& dwOffset, bool bMoveOffset = true) const;

	// get file name
	 char* GetFilename() const { return m_szFile; };

protected:
	 char* m_szFile;
	MPAStream( char* szFilename);
};
#endif