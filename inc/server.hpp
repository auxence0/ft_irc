#pragma once

# include <string>
# include <netinet/in.h>
# include <sys/socket.h>
# include <exception>
# include <stdexcept>
# include <sys/types.h>
# include <cstdlib>
# include <poll.h>
# include <vector>
# include <iostream>
# include <map>
# include "../inc/Client.hpp"

class	server {
	public:
		server(int port, const std::string& passwrd);
		~server();
		void	run();

	private:
		server( const server& obj );
		server&	operator=( const server& rhs );
		server();
		void		new_client();
		void		readData(Client client);
		int			port_;
		std::string	password_;
		int			serverSocket_;
		std::vector<pollfd>		pollfds;
		std::map<int, Client>	clients;
};