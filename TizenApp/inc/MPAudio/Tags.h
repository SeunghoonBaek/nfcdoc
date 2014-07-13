#ifndef _TAGS_H_
#define _TAGS_H_

#define NUMBER_OF_ELEMENTS(X) (sizeof X / sizeof X[0])

#include <vector>

#include "MPAStream.h"
#include "Tag.h"

class Tags {
public:
	Tags(MPAStream* pStream);
	~Tags(void);

	Tag* GetNextTag( int& nIndex) const;

	template <class TagClass> 
	bool FindTag(TagClass*& pTag) const;

	// get begin offset after prepended tags
	int GetBegin() const { 
		return m_dwBegin; 
	};

	// get end offset before appended tags
	int GetEnd() const { 
		return m_dwEnd; 
	};

private:
	bool FindAppendedTag(MPAStream* pStream);
	bool FindPrependedTag(MPAStream* pStream);

	// definition of function pointer type
	typedef Tag* (*FindTagFunctionPtr) (MPAStream*, bool, int, int);
	bool FindTag(FindTagFunctionPtr pFindTag, MPAStream* pStream, bool bAppended);

	std::vector <Tag*> m_Tags;
	int m_dwBegin, m_dwEnd;
	static const FindTagFunctionPtr m_appendedTagFactories[];
	static const FindTagFunctionPtr m_prependedTagFactories[];
};

// you need to compile with runtime information to use this method
template <class TagClass>
bool Tags::FindTag(TagClass*& pTag) const
{
	for ( int nIndex = 0; nIndex < m_Tags.size(); nIndex++)
	{
		pTag = dynamic_cast<TagClass*>(m_Tags[nIndex]);
		if (pTag)
			return true;
	}
	return false;
}

#endif
