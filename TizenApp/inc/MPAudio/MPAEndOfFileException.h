#ifndef _MPAENDOFFILEEXCEPTION_H_
#define _MPAENDOFFILEEXCEPTION_H_
#include "MPAException.h"

class MPAEndOfFileException : public MPAException {
public:
	MPAEndOfFileException( char* szFile);
	virtual ~MPAEndOfFileException(void);
};
#endif
