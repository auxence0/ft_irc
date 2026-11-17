# include "server.hpp"

server::server( int port, std::string& password): port_(port), password_(password) {
	serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket_ == -1)
		throw	std::runtime_error("Erorr: create socket");

	sockaddr_in	ServerAddr;

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(port_);
	ServerAddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(serverSocket_, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == -1)
		throw	std::runtime_error("Erorr: associate the socket with a local address and a port");
	if (listen(serverSocket_, 21) == -1)
		throw	std::runtime_error("Error: listen() failed");
}

void	server::run() {
	std::vector<pollfd>	pollfds;

	pollfds[0].fd = serverSocket_;
	pollfds[0].events = POLLIN;
	while (1) {
		poll(&pollfds[0], pollfds.size(), 0);
	}
}
