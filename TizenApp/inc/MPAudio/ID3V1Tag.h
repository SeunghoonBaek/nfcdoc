#ifndef _ID3V1TAG_H_
#define _ID3V1TAG_H_
#include <string.h>
#include "Tag.h"

class ID3V1Tag : public Tag {
public:
	static ID3V1Tag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);
	~ID3V1Tag(void);

private:
	ID3V1Tag(MPAStream* pStream, int dwOffset);
};

#endif
