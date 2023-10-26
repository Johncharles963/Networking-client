#include "updclient.h"
#include <thread>

int main() {
	UDPClient clientUDP;
	clientUDP.startServer();
	sockaddr_in server;
	server.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &server.sin_addr.s_addr);
	server.sin_port = htons(55555);
	
	char data[] = "Sending new data to server from the client";

	while (true) {
		Sleep(5000);
		clientUDP.sendData(server, data);
	}
	clientUDP.closeServer();
	return 0;
}
