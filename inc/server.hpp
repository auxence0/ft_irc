#pragma once

# include <string>
# include <netinet/in.h>
# include <sys/socket.h>
# include <exception>
# include <stdexcept>
# include <sys/types.h>
# include <cstring>
# include <poll.h>
# include <vector>

class	server {
	public:
		server(int port, std::string& passwrd);
		~server();
		void	run();

	private:
		server( const server& obj );
		server&	operator=( const server& rhs );
		server();
		int			port_;
		std::string	password_;
		int			serverSocket_;
};