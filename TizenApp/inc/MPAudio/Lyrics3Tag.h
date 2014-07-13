#ifndef _LYRICS3TAG_H_
#define _LYRICS3TAG_H_

#include <string.h>
#include <stdlib.h>
#include "Tag.h"

class Lyrics3Tag : public Tag {
public:
	static Lyrics3Tag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);
	~Lyrics3Tag(void);

private:
	Lyrics3Tag(MPAStream* pStream, int dwOffset, bool bVersion2);
};

#endif
