#include "MPAudio/Tag.h"

Tag::Tag(MPAStream* pStream,  char* szName, bool bAppended, int dwOffset, int dwSize):
	m_pStream(pStream), m_bAppended(bAppended), m_dwOffset(dwOffset), m_dwSize(dwSize)
{
	if( szName == NULL ) return;

	int nameLength = strlen( szName );
	m_szName = new char[ nameLength + 1 ];
	strcpy( m_szName, szName );
}

Tag::~Tag(void)
{
	delete m_szName;
	m_szName = NULL;
}

void Tag::SetVersion( char bVersion1,  char bVersion2,  char bVersion3)
{
	// only values between 0 and 9 are displayed correctly
	m_fVersion = bVersion1;
	m_fVersion += bVersion2 * 0.1f;
	m_fVersion += bVersion3 * 0.01f;
}
