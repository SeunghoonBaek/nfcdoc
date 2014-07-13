#ifndef _LAMETAG_H_
#define _LAMETAG_H_

#include <FBase.h>

#include <string.h>
#include <string>

using Tizen::Base::Float;
using Tizen::Base::String;
using std::string;

#include "Tag.h"


class LAMETag : public Tag {
public:
	static LAMETag* FindTag(MPAStream* pStream, bool bAppended, int dwBegin, int dwEnd);
	~LAMETag(void);

	std::string m_strEncoder;
	int m_dwLowpassFilterHz;
	unsigned char m_bBitrate;	// in kbps
	unsigned char m_bRevision;

	bool IsVBR() const;
	bool IsABR() const;
	bool IsCBR() const;
	char* GetVBRInfo() const;
	bool IsSimpleTag() const { return m_bSimpleTag; };

private:
	LAMETag(MPAStream* pStream, bool bAppended, int dwOffset);

	unsigned char m_bVBRInfo;
	bool m_bSimpleTag;
	static char* m_szVBRInfo[10];
};
#endif
