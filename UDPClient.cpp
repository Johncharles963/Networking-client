#include "updclient.h"

bool UDPClient::startWsa() {
    int wsaErr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaErr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaErr != 0) {
        std::cout << "The Winsock dll was not found" << std::endl;
        return false;
    }
    else {
        std::cout << "This Winsock dll was found" << std::endl;
        std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
        return true;
    }
}
bool UDPClient::createClientSocket() {
    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == INVALID_SOCKET) {
        std::cout << "Error createServerSocket" << std::endl;
        WSACleanup;
        return false;
    }
    else {
        std::cout << "socket is OK!" << std::endl;
        return true;
    }
}
bool UDPClient::recieveData() {
    char buffer[] = "";
    sockaddr_in returnAddress;

    int recvbuflen = 512;
    int returnAddress_length = (int)sizeof(returnAddress);

    int bytes_received = recvfrom(clientSocket, buffer, recvbuflen, 0, (struct sockaddr*)&returnAddress, &returnAddress_length);
    if (bytes_received < 0) {
        std::cout << "Error recieving datagram:" << std::endl;
        WSACleanup();
        return false;
    }
    else {
        std::cout << "Recieved: " << buffer << std::endl;
        std::cout << "Recieved: " << bytes_received << std::endl;
        return true;
    }
}

bool UDPClient::sendData(sockaddr_in& returnAddress, char* buffer) {

    int bytesSent = sendto(clientSocket, (const char*)buffer, strlen(buffer), 0, (struct sockaddr*)&returnAddress, sizeof(returnAddress));
    if (bytesSent == -1) {
        std::cout << "Error sending data to server: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }
    else {
        std::cout << "Data sent: " << buffer << std::endl;
        std::cout << "Bytes sent: " << bytesSent << std::endl;
        return true;
    }
}

void UDPClient::closeServer() {
    closesocket(clientSocket);
    WSACleanup();
}

bool UDPClient::startServer() {
    if (!startWsa())
        return false;
    if (!createClientSocket())
        return false;
    return true;
}
