#include "MPAudio/MPAEndOfFileException.h"

MPAEndOfFileException::MPAEndOfFileException( char* szFile) :
	MPAException(MPAException::EndOfFile, szFile)
{
}

MPAEndOfFileException::~MPAEndOfFileException(void)
{
}
