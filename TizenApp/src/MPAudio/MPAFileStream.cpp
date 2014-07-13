#include "MPAudio/MPAFileStream.h"
#include "MPAudio/MPAException.h"
#include "MPAudio/MPAEndOfFileException.h"
// 1KB * 1count is inital buffersize
const int MPAFileStream::INIT_BUFFERSIZE = 1024;	


MPAFileStream::MPAFileStream( char* szFilename) :
	MPAStream(szFilename), m_dwOffset(0), m_hFile(0), m_iBufferDataSize(0)
{
	// open with CreateFile (no limitation of 128byte filename length, like in mmioOpen)
	m_hFile = fopen( szFilename, "r+b");
	if( !m_hFile ) {
		throw MPAException(MPAException::ErrOpenFile, szFilename, "CreateFile", true);
	}

	Init();
}

MPAFileStream::MPAFileStream( char* szFilename, void* hFile) :
	MPAStream(szFilename), m_hFile((FILE *)hFile)
{
	Init();
}


void MPAFileStream::Init() 
{
	m_dwBufferSize = INIT_BUFFERSIZE;
	// fill buffer for first time
	m_pBuffer = new  unsigned char[m_dwBufferSize];
	FillBuffer(m_dwOffset, m_dwBufferSize, false);
}

MPAFileStream::~MPAFileStream(void)
{
	if (m_pBuffer){
		delete[] m_pBuffer;
		m_pBuffer= 0;
	}
		
	
	// close file
	if (m_bMustReleaseFile){
		fclose( m_hFile );
	}
}

// VC++6 doesn't contain this definition
#ifndef INVALID_SET_FILE_POINTER
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#endif

 unsigned char* MPAFileStream::ReadBytes(int dwSize, int& dwOffset, bool bMoveOffset, bool bReverse) const
{

	// enough bytes in buffer, otherwise read from file
	if (m_dwOffset > dwOffset || ( ((int)((m_dwOffset + m_dwBufferSize) - dwOffset)) < (int)dwSize))
	{
		if (!FillBuffer(dwOffset, dwSize, bReverse)) 
		{
			throw MPAEndOfFileException(m_szFile);
		}
	}

	 unsigned char* pBuffer = m_pBuffer + (dwOffset-m_dwOffset);
	if (bMoveOffset)
		dwOffset += dwSize;
	
	return pBuffer;
}


#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
int MPAFileStream::GetSize() const
{
	int dwSize = 0;
	struct stat file_info;
		
	if ( stat(m_szFile, &file_info) ){
		throw MPAException(MPAException::ErrReadFile, m_szFile, "GetFileSize", true);
	}
		
	else{
		dwSize = file_info.st_size;
	}
	
	return dwSize;
}

// fills internal buffer, returns false if EOF is reached, otherwise true. Throws exceptions
bool MPAFileStream::FillBuffer(int dwOffset, int dwSize, bool bReverse) const
{
	// calc new buffer size
	if (dwSize > m_dwBufferSize)
	{
		m_dwBufferSize = dwSize;
		
		// release old buffer 
		delete[] m_pBuffer;

		// reserve new buffer
		m_pBuffer = new  unsigned char[m_dwBufferSize];
	}	

	if (bReverse)
	{
		if (dwOffset + dwSize < m_dwBufferSize)
			dwOffset = 0;
		else
			dwOffset = dwOffset + dwSize - m_dwBufferSize;
	}

	// read <m_dwBufferSize> bytes from offset <dwOffset>
	int iReadCount = 0;
	memset( m_pBuffer, 0, m_dwBufferSize );
	iReadCount = Read(m_pBuffer, dwOffset, m_dwBufferSize);

	// set new offset
	m_dwOffset = dwOffset;

	// �����͸� �� ���� ���̹Ƿ� ������ �߻��Ŵ
	if ( iReadCount < dwSize )
		return false;

	return true;
}

// read from file, return number of bytes read
int MPAFileStream::Read(unsigned char* pData, int dwOffset, int dwSize) const
{
	int dwBytesRead = 0;
	
	// set position first
	SetPosition(dwOffset);
	
	dwBytesRead = fread(pData, 1, dwSize, m_hFile);
	m_iBufferDataSize = dwBytesRead;

	if ( dwBytesRead < 0 )
		throw MPAException(MPAException::ErrReadFile, m_szFile, "ReadFile", true);
	
	return dwBytesRead;
} 

// set file position
void MPAFileStream::SetPosition(int dwOffset) const
{
	// convert from unsigned DWORD to signed 64bit long

	int result = fseek( m_hFile, dwOffset, SEEK_SET );

	if (result != 0)
	{ 
		// != NO_ERROR
		// throw error
		throw MPAException(MPAException::ErrSetPosition, m_szFile, "SetFilePointer", true);
	}
}

int MPAFileStream::getBufferSize() const{
	return m_dwBufferSize;
}
int MPAFileStream::getBufferDataSize() const{
	return m_iBufferDataSize;
}
