#pragma once

# include <string>
# include <netinet/in.h>
# include <sys/socket.h>
# include <exception>
# include <stdexcept>

class	server {
	public:
		server(int port, std::string& passwrd);
		server( const server& obj );
		server&	operator=( const server& rhs );
		~server();

	private:
		server();
		int			port_;
		std::string	password_;
		int			serverSocket_;
};