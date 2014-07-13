//#include "StringConvertor.h"
//
//char* StringConvertor::UTF8ToANSI(const char * pszCode){
//	int		nLength, nLength2;
//	BSTR	bstrCode;
//	char*	pszUTFCode = NULL;
//
//	nLength = MultiByteToWideChar(CP_ACP, 0, pszCode, strlen(pszCode), NULL, NULL);
//	bstrCode = SysAllocStringLen(NULL, nLength);
//	MultiByteToWideChar(CP_ACP, 0, pszCode, strlen(pszCode), bstrCode, nLength);
//
//	nLength2 = WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, 0, NULL, NULL);
//	pszUTFCode = (char*)malloc(nLength2+1);
//	WideCharToMultiByte(CP_UTF8, 0, bstrCode, -1, pszUTFCode, nLength2, NULL, NULL);
//
//	return pszUTFCode;
//}
//
//// ANSI Code -> UTF8 Code
//char* StringConvertor::ANSIToUTF8(const char *pszCode){
//	BSTR    bstrWide;
//	char*   pszAnsi;
//	int     nLength;
//
//	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
//	bstrWide = SysAllocStringLen(NULL, nLength);
//
//	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);
//
//	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
//	pszAnsi = new char[nLength];
//
//	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
//	SysFreeString(bstrWide);
//
//	return pszAnsi;
//}
