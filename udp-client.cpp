//#include <iostream>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <string>
//#include <tchar.h>
//
//bool startWsa(WSADATA& wsaData);
//bool createClientSocket(SOCKET& clientSocket);
//bool sendData(SOCKET& socket, int& port);
//bool recieveData(SOCKET& socket);
//bool sendData(SOCKET& socket, int& port);
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    SOCKET clientSocket;
//    int port{ 55555 };
//    WSADATA wsaData;
//    startWsa(wsaData);
//    createClientSocket(clientSocket);
//    sendData(clientSocket, port);
//    recieveData(clientSocket);
//    system("pause");
//    WSACleanup();
//    return 0;
//}
//
//bool startWsa(WSADATA& wsaData) {
//    int wsaErr;
//    WORD wVersionRequested = MAKEWORD(2, 2);
//    wsaErr = WSAStartup(wVersionRequested, &wsaData);
//    if (wsaErr != 0) {
//        std::cout << "The Winsock dll was not found" << std::endl;
//        exit(EXIT_FAILURE);
//    }
//    else {
//        std::cout << "This Winsock dll was found" << std::endl;
//        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
//        return true;
//    }
//}
//bool createClientSocket(SOCKET& clientSocket) {
//    clientSocket = INVALID_SOCKET;
//    clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//    if (clientSocket == INVALID_SOCKET) {
//        std::cout << "Error createClientSocket" << std::endl;
//        WSACleanup;
//        exit(EXIT_FAILURE);
//    }
//    else {
//        std::cout << "socket is OK!" << std::endl;
//        return true;
//    }
//}
//
//bool sendData(SOCKET& socket, int& port) {
//    sockaddr_in service;
//    service.sin_family = AF_INET;
//    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
//    service.sin_port = htons(port);
//
//    char buffer[200] = "P1p.H10p.m10p.s20";
//    int bytesSent = sendto(socket,(const char*)buffer, strlen(buffer),0,(struct sockaddr*)&service, sizeof(service));
//    if (bytesSent == -1) {
//        std::cout << "Error sending data to server: " << WSAGetLastError() << std::endl;
//        WSACleanup();
//        return false;
//    }
//    else {
//        std::cout << "Data sent: " << buffer << std::endl;
//        std::cout << "Bytes sent: " << bytesSent << std::endl;
//        return true;
//    }
//}
//
//bool recieveData(SOCKET& socket) {
//    char buffer[200] = "";
//    char testing[200] = "";
//    sockaddr_in clientAddress;
//
//    int clientAddress_length = (int)sizeof(clientAddress);
//
//    int bytes_received = recvfrom(socket, buffer, 200, 0, (struct sockaddr*)&clientAddress, &clientAddress_length);
//    if (bytes_received < 0) {
//        std::cout << "Error recieving datagram from client:" << std::endl;
//        WSACleanup();
//        return false;
//    }
//    else {
//        std::cout << "Recieved: " << buffer << std::endl;
//        std::cout << "Recieved: " << bytes_received << std::endl;
//        std::cout << "Recieved: " << inet_ntop(AF_INET, &clientAddress, testing, 200) << std::endl;
//        return true;
//    }
//}