#include "SessionManager.h"

SessionManager::SessionManager(){
	srand((unsigned int)time(NULL));
}

string SessionManager::getServerIPAddress(){

/*
	char name[255];
	PHOSTENT hostinfo;

	if( gethostname ( name, sizeof(name)) == 0) {
		if((hostinfo = gethostbyname(name)) != NULL) {
			return string( inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list) );
		}
	}
*/

// 	NetConnectionInfo netInfo;



	return "127.0.0.1";
}

// session id length is total 16 charactor
// but, mixed letter and number
// not have specical rules
// must remove memory area after used it 
char* SessionManager::CreateSessionID(){

	char* pSessionID = new char[MAX_SESSIONID_LENGTH + 1];

	if( !pSessionID ) return 0;

	int nPos = 0;

	while( nPos < MAX_SESSIONID_LENGTH ){
		
		int nChooseCase = (rand() % 2);

		switch( nChooseCase ){
		case 0:
			pSessionID[ nPos ] = getRandomChar();
			break;

		case 1:
			pSessionID[ nPos ] = getRandomNumber();
			break;
		}

		++nPos;
	}

	pSessionID[ nPos ] = '\0';

	if( nPos <= MAX_SESSIONID_LENGTH )
		return pSessionID;

	else
		return 0;
}

char SessionManager::getRandomChar(){
	static int nLetterGap = 'z' - 'a' + 1;
	
	int nRandomValue = rand() % nLetterGap ;

	return (char)(nRandomValue + 'a');
}

char SessionManager::getRandomNumber(){
	int nRandomValue = rand() % 10;
	return (char)(nRandomValue + '0');
}
