#include "MPAudio/Tags.h"
#include "MPAudio/MPAException.h"

#include "MPAudio/ID3V1Tag.h"
#include "MPAudio/ID3V2Tag.h"
#include "MPAudio/Lyrics3Tag.h"
#include "MPAudio/APETag.h"
#include "MPAudio/MusicMatchTag.h"

const Tags::FindTagFunctionPtr Tags::m_appendedTagFactories[] = 
{
	(Tags::FindTagFunctionPtr)&ID3V1Tag::FindTag,
	(Tags::FindTagFunctionPtr)&MusicMatchTag::FindTag,
	(Tags::FindTagFunctionPtr)&ID3V2Tag::FindTag,
	(Tags::FindTagFunctionPtr)&Lyrics3Tag::FindTag,
	(Tags::FindTagFunctionPtr)&APETag::FindTag
};

const Tags::FindTagFunctionPtr Tags::m_prependedTagFactories[] = 
{
	(Tags::FindTagFunctionPtr)&ID3V2Tag::FindTag,
	(Tags::FindTagFunctionPtr)&APETag::FindTag
};

Tags::Tags(MPAStream* pStream) : m_dwBegin(0), m_dwEnd( pStream->GetSize() ){
	// all appended tags
	while (FindAppendedTag(pStream));

	// all prepended tags
	while (FindPrependedTag(pStream));
}

Tags::~Tags(void) {
	for ( int n = 0 ; n < m_Tags.size() ; n++)
	{
		delete m_Tags[n];
	}
}

bool Tags::FindPrependedTag(MPAStream* pStream)
{
	for (int i=0; i < NUMBER_OF_ELEMENTS(m_prependedTagFactories); i++) 
	{
		if (FindTag(m_prependedTagFactories[i], pStream, false))
			return true;
	}
	return false;
}

bool Tags::FindAppendedTag(MPAStream* pStream)
{
	for (int i=0; i < NUMBER_OF_ELEMENTS(m_appendedTagFactories); i++) 
	{
		if (FindTag(m_appendedTagFactories[i], pStream, true))
			return true;
	}
	return false;
}

bool Tags::FindTag(FindTagFunctionPtr pFindTag, MPAStream* pStream, bool bAppended) {
	try {
		Tag* pTag = pFindTag(pStream, bAppended, m_dwBegin, m_dwEnd);
		if (pTag) {
			if (bAppended)
				m_dwEnd = pTag->GetOffset();
			else
				m_dwBegin = pTag->GetEnd();
			m_Tags.push_back(pTag);
			return true;
		}
	}
	catch(MPAException& Exc) {
		Exc.ShowError();
	}
	return false;
}

Tag* Tags::GetNextTag( int& nIndex) const
{
	Tag* pTag;
	if (nIndex < m_Tags.size())
		pTag = m_Tags[nIndex];
	else
		pTag = NULL;

	nIndex++;
	return pTag;
}
