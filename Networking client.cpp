#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <tchar.h>

bool startWsa(WSADATA& wsaData);
bool createClientSocket(SOCKET& clientSocket);
bool connectSocket(SOCKET& socket, int& port);

int main()
{
    std::cout << "Hello World!\n";
    SOCKET clientSocket;
    int port{ 55555 };
    WSADATA wsaData;
    startWsa(wsaData);
    createClientSocket(clientSocket);
    connectSocket(clientSocket, port);
    system("pause");
    WSACleanup();
    return 0;
}

bool startWsa(WSADATA& wsaData) {
    int wsaErr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaErr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaErr != 0) {
        std::cout << "The Winsock dll was not found" << std::endl;
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "This Winsock dll was found" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
        return true;
    }
}
bool createClientSocket(SOCKET& clientSocket) {
    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cout << "Error createClientSocket" << std::endl;
        WSACleanup;
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "socket is OK!" << std::endl;
        return true;
    }
}
bool connectSocket(SOCKET& socket, int& port) {
    sockaddr_in service;
    service.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
    service.sin_port = htons(port);

    if (connect(socket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
        std::cout << "Error in connect() - Failed to connect" << WSAGetLastError() << std::endl;
        WSACleanup;
        exit(EXIT_FAILURE);
    }
    else {
        std::cout << "The socket was connected ok!" << std::endl;
        std::cout << "Client can now start sending and reciecing data..." << std::endl;
        return true;
    }
}
