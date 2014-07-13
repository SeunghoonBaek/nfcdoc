#ifndef _APETAG_H_
#define _APETAG_H_

#include <string.h>
#include "Tag.h"

class APETag : public Tag {
public:
	static APETag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);
	~APETag(void);

	

private:
	APETag(MPAStream* pStream, bool bAppended, int dwOffset);
};

#endif
