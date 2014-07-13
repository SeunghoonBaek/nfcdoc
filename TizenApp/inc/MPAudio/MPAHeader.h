#ifndef _MPAHEADER_H_
#define _MPAHEADER_H_

#include "MPAStream.h"

#define MPA_HEADER_SIZE 4	// MPEG-Audio Header Size 32bit
#define MAXTIMESREAD 5

class MPAHeader {
public:
	
	MPAHeader(MPAStream* pStream, int& dwOffset, bool bExactOffset, bool bReverse, MPAHeader* pCompareHeader);
	~MPAHeader();
	
	bool operator==(MPAHeader& DestHeader) const;
	
	// calculate frame size
	int CalcFrameSize() const {	
		return int(((m_dwCoefficients[m_bLSF][m_Layer] * m_dwBitrate / m_dwSamplesPerSec) + m_dwPaddingSize)) * m_dwSlotSizes[m_Layer]; 
	};

	// bitrate is in bit per second, to calculate in bytes => (/ 8)
	int GetBytesPerSecond() const { return m_dwBitrate / 8; };

	// calc number of seconds from number of frames
	int GetLengthSecond(int dwNumFrames) const {
		return dwNumFrames * m_dwSamplesPerFrame / m_dwSamplesPerSec;
	};

	// get per second inside frame bytes
	int GetBytesPerSecond(int dwNumFrames, int dwNumBytes) const { 
		return dwNumBytes / GetLengthSecond( dwNumFrames ); 
	};

	// is this mono?
	bool IsMono() const { 
		return (m_ChannelMode == SingleChannel)?true:false; 
	};

	// true if MPEG2/2.5 otherwise false
	bool IsLSF() const { 
		return m_bLSF;	
	};

	// only layer 3, not usable
	int GetSideInfoSize() const { 
		return m_dwSideInfoSizes[IsLSF()][IsMono()]; 
	};

	// number of each frame channel
	int GetNumChannels() const { 
		return IsMono()?1:2; 
	};

	// real play time
	int GetFrameMillisecond() const;

private:

	// default mpeg layer 1, layer 2 audio table value
	// define implement source files(cpp files) -> go reference of MPAHeader.cpp
	static const int m_dwMaxRange;
	static const int m_dwTolerance;

	static const int m_dwSamplingRates[4][3];
	static const int m_dwPaddingSizes[3];
	static const int m_dwBitrates[2][3][15];
	static const bool m_bAllowedModes[15][2];
	static const int m_dwSamplesPerFrames[2][3];
	static const int m_dwCoefficients[2][3];
	static const int m_dwSlotSizes[3];
	static const int m_dwSideInfoSizes[2][2];

	bool m_bLSF;		// true means lower sampling frequencies (=MPEG2/MPEG2.5)

	void Init( unsigned char* pHeader,  char* szFilename);

public:
	static  char* m_szLayers[];
	static  char* m_szMPEGVersions[];
	static  char* m_szChannelModes[];
	static  char* m_szEmphasis[];

	enum MPAVersion
	{
		MPEG25 = 0,
		MPEGReserved,
		MPEG2,
		MPEG1		
	}m_Version;

	enum MPALayer
	{
		Layer1,
		Layer2,
		Layer3,
		LayerReserved
	}m_Layer;

	enum Emphasis
	{
		EmphNone = 0,
		Emph5015,
		EmphReserved,
		EmphCCITJ17
	}m_Emphasis;

	enum ChannelMode
	{
		Stereo,
		JointStereo,
		DualChannel,
		SingleChannel
	}m_ChannelMode;
	
	int m_dwSamplesPerSec;				// sampling per second, such as 44100KHz 
	int m_dwSamplesPerFrame;			// sampling value
	int m_dwBitrate;							// in bit per second (1 kb = 1000 bit, not 1024)
	int m_dwPaddingSize;					// if frame had a padding bit
	short m_wBound;							// only valid for intensity stereo
	short m_wAllocationTableIndex;		// only valid for MPEG 1 Layer II (0=table a, 1=table b,...)
	
	// copyright flags
	bool m_bCopyright, m_bPrivate, m_bOriginal;
	bool m_bCRC; 
	 unsigned char m_ModeExt;
};

#endif
