#ifndef _MUSICMATCHTAG_H_
#define _MUSICMATCHTAG_H_

#include <cstdlib>
#include <string.h>
#include "Tag.h"

class MusicMatchTag : public Tag {
public:
	static MusicMatchTag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);
	~MusicMatchTag(void);

private:
	MusicMatchTag(MPAStream* pStream, int dwOffset);
	
};
#endif
