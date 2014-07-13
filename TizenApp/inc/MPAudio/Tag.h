#ifndef _TAG_H_
#define _TAG_H_

#include <string.h>
#include "MPAStream.h"

class Tag {
public:
	int GetOffset() const { 
		return m_dwOffset; 
	};

	int GetEnd() const { 
		return m_dwOffset + m_dwSize; 
	};

	char* GetName() const { 
		return m_szName; 
	};

	int GetSize() const {
		return m_dwSize; 
	};

	float GetVersion() const { 
		return m_fVersion; 
	};
	
	virtual ~Tag(void);

protected:
	MPAStream* m_pStream;

	Tag(MPAStream* pStream,  char* szName, bool bAppended, int dwOffset = 0, int dwSize = 0);

	int m_dwOffset;			// beginning of tag
	int m_dwSize;				// size of tag
	bool m_bAppended;		// true if at the end of file
	float m_fVersion;			// format x.yz
	 char* m_szName;		// name of tag

	void SetVersion( char bVersion1,  char bVersion2=0,  char bVersion3=0);
};

#endif