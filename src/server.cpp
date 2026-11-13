# include "server.hpp"

server::server( int port, std::string& password): port_(port), password_(password) {
	serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket_ < 0)
		throw	std::runtime_error("Erorr: create socket");

	sockaddr_in	ServerAddr;

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(port_);
	ServerAddr.sin_addr.s_addr = INADDR_ANY;
	bind(serverSocket_, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	
}
