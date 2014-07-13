// main.cpp
// server_addr.sin_addr.s_addr = inet_addr( "172.20.10.3" );
// server_addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
// server_addr.sin_addr.s_addr = inet_addr( "223.62.179.40" );



#include <iostream>
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

//const char g_szIpAddress[16+1] = "223.62.179.40";
//const unsigned short g_uPort = 33446;

int AttemptTCPClient(char* _pIPAddress, int _portNumber){
	int nReturn = 0;
	char temp[1024] = {0};
	WSADATA wsadata = {0};
	SOCKET clientsock = INVALID_SOCKET;
	sockaddr_in addr = {0};
	int addrlen = sizeof(addr);

	nReturn = WSAStartup(WORD(2.0), &wsadata);
	if (nReturn != 0) {
		printf("WSAStartup failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	clientsock = socket(AF_INET, SOCK_STREAM, 0);
	if (clientsock == INVALID_SOCKET) {
		printf("socket failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(_pIPAddress);
	addr.sin_port = htons(_portNumber);

	nReturn = connect(clientsock, (sockaddr *)&addr, addrlen);
	if (nReturn == SOCKET_ERROR) {
		printf("connect failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	printf("서버접속 성공...\n");

	if (clientsock != INVALID_SOCKET) {
		closesocket(clientsock);
	}
	WSACleanup();
	return GetLastError();
}

int AttemptTCPServer( int _port ){
	int nReturn = 0;
	char temp[1024] = {0};
	WSADATA wsadata = {0};
	SOCKET serverSocket = INVALID_SOCKET;
	sockaddr_in addr = {0};
	int addrlen = sizeof(addr);

	nReturn = WSAStartup(WORD(2.0), &wsadata);
	if (nReturn != 0) {
		printf("WSAStartup failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		printf("socket failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(_port);

	nReturn = bind(serverSocket, (sockaddr *)&addr, sizeof(sockaddr));
	if (nReturn == SOCKET_ERROR) {
		printf("bind failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	listen(serverSocket, 1);

	struct sockaddr_in client_addr;
	int client_addr_size = sizeof( client_addr );

	printf(" wait client \n");
	SOCKET clientSocket = accept( serverSocket, (struct sockaddr *) &client_addr, &client_addr_size );

	if( clientSocket == INVALID_SOCKET ){
		printf("accept failed. Error No. %d\n", WSAGetLastError());
		return 0;
	}

	printf(" hello ! \n");

	
	closesocket( clientSocket );
	closesocket( serverSocket );
	WSACleanup();
	return GetLastError();
}


int main()
{
	AttemptTCPClient("172.20.10.6", 8554);
	// AttemptTCPClient("10.0.2.16", 33445);
	// AttemptTCPServer(33445);
	return 0;
}