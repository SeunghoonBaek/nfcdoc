#include "MPAudio/MPAException.h"

/// CMPAException: exception class
//////////////////////////////////////////////

MPAException::MPAException(ErrorIDs ErrorID,  char* szFile,  char* szFunction, bool bGetLastError) :
	m_ErrorID(ErrorID), m_bGetLastError(bGetLastError), m_szErrorMsg(0), m_szFunction(0)
{
	if( szFile ){
		m_szFile = new char[ strlen( szFile) + 1];
		strcpy( m_szFile, szFile );
	}
	
	if( szFunction ){
		m_szFunction = new char[ strlen( szFunction ) + 1 ];
		strcpy( m_szFunction, szFunction );
	}
}

// copy constructor (necessary for exception throwing without pointers)
MPAException::MPAException(const MPAException& Source)
{
	m_ErrorID = Source.m_ErrorID;
	m_bGetLastError = Source.m_bGetLastError;

	if( Source.m_szFile ){
		m_szFile = new char[ strlen( Source.m_szFile) + 1];
		strcpy( m_szFile, Source.m_szFile);
	}

	if( Source.m_szFunction ){
		m_szFunction = new char[ strlen( Source.m_szFunction) + 1 ];
		strcpy( m_szFunction, Source.m_szFunction );
	}
}


// destructor
MPAException::~MPAException()
{

	//if (m_szFile){
	//	delete m_szFile;
	//	m_szFile = 0;
	//}
		
	if (m_szFunction){
		delete m_szFunction;
		m_szFunction = 0;
	}
		
	if (m_szErrorMsg){
		delete[] m_szErrorMsg;
		m_szErrorMsg = 0;
	}
		
}

// should be in resource file for multi language applications
 char* MPAException::m_szErrors[MPAException::NumIDs] = 
{
	"Can't open the file.", 
	"Can't set file position.",
	"Can't read from file.",
	"No VBR Header found.",
	"Incomplete VBR Header.",
	"No frame found within tolerance range.",
	"No frame found before end of file was reached.",
	"Header corrupt",
	"Free Bitrate currently not supported",
	"Incompatible Header",
	"Corrupt Lyrics3 Tag"
};

#define MAX_ERR_LENGTH 256
#include <iostream>
void MPAException::ShowError()
{
	 char* pErrorMsg = GetErrorDescription();
	// show error message
	 std::cout << pErrorMsg << "\n";
}

#include <stdio.h>
 char* MPAException::GetErrorDescription()
{
	if (!m_szErrorMsg)
	{
		m_szErrorMsg = new char[MAX_ERR_LENGTH];
		m_szErrorMsg[0] = '\0';
		char szHelp[MAX_ERR_LENGTH];

		// this is not buffer-overflow-proof!
		if (m_szFunction)
		{
			sprintf(szHelp, "%s: ", m_szFunction);
			strcat(m_szErrorMsg, szHelp );
		}
		if (m_szFile)
		{
			sprintf(szHelp, "'%s'\n", m_szFile);
			strcat(m_szErrorMsg, szHelp);
		}
		strcat(m_szErrorMsg, m_szErrors[m_ErrorID]);

		// make sure string is null-terminated
		m_szErrorMsg[MAX_ERR_LENGTH-1] = '\0';
	}
	return m_szErrorMsg;
}
