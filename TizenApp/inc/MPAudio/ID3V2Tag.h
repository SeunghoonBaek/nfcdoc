#ifndef _ID3V2TAG_H_
#define _ID3V2TAG_H_

#include <string.h>
#include "Tag.h"

class ID3V2Tag : public Tag {
public:
	static ID3V2Tag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);	
	~ID3V2Tag(void);

private:
	ID3V2Tag(MPAStream* pStream, bool bAppended, int dwOffset);
	static int GetSynchsafeInteger(int dwValue);

};
#endif
