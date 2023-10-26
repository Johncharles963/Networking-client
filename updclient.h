#pragma once
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <tchar.h>

class UDPClient {
public:
	bool recieveData();
	bool sendData(sockaddr_in& returnAddress, char* buffer);
	void closeServer();
	bool startServer();
private:
	SOCKET clientSocket;
	WSADATA wsaData;
	bool startWsa();
	bool createClientSocket();
};