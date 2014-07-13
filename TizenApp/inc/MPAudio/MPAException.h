#ifndef _MPAEXCEPTION_H_
#define _MPAEXCEPTION_H_

#include <string.h>
// exception class
class MPAException {
public:

	enum ErrorIDs {
		ErrOpenFile,
		ErrSetPosition,
		ErrReadFile,
		NoVBRHeader,
		IncompleteVBRHeader,
		NoFrameInTolerance,
		EndOfFile,
		HeaderCorrupt,
		FreeBitrate,
		IncompatibleHeader,
		CorruptLyricsTag,
		NumIDs			// this specifies the total number of possible IDs
	};

	MPAException(ErrorIDs ErrorID,  char* szFile = 0,  char* szFunction = 0, bool bGetLastError=false);

	// copy constructor (necessary because of LPSTR members)
	MPAException(const MPAException& Source);
	virtual ~MPAException(void);

	ErrorIDs GetErrorID() const { return m_ErrorID; };
	char* GetErrorDescription();
	void ShowError();

private:
	ErrorIDs m_ErrorID;
	bool m_bGetLastError;
	char* m_szFunction;
	char* m_szFile;
	char* m_szErrorMsg;

	static char* m_szErrors[MPAException::NumIDs];
};

#endif
