# include "../inc/server.hpp"
# include "../inc/Client.hpp"

server::server( int port, const std::string& password): port_(port), password_(password) {
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
		throw	std::runtime_error("Error: listen()");

	pollfd	servpoll;

	servpoll.fd = serverSocket_;
	servpoll.events = POLLIN;
	servpoll.revents = 0;
	pollfds.push_back(servpoll);
}

server::~server() {}

void	server::new_client() {
	pollfd	new_client;

	new_client.fd = accept(serverSocket_, NULL, NULL);
	new_client.events = POLLIN;
	new_client.revents = 0;
	if (new_client.fd == -1) {
		std::cerr << "Error: accept()\n";
		return ;
	}
	pollfds.push_back(new_client);
}

void	server::readData() {

}

void	server::run() {
	while (1) {
		poll(&pollfds[0], pollfds.size(), 0);
		if (pollfds[0].revents & POLLIN)
			new_client();
		for (int i = 1; i < pollfds.size(); ++i) {
			if (pollfds[i].revents & POLLIN)
				readData();
		}
	}
}
