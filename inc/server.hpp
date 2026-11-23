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
# include <map> 
# include <iostream>
# include <map>
# include "../inc/Client.hpp"

class Channel;
class Client;

class	server {
	public:
		server(int port, const std::string& passwrd);
		~server();
		void	run();
		std::map<std::string, Channel*> const	&getChannels() const;
		Channel	*getChannel(std::string const &channelName);
		void	quitAllChannel(Client *client);
		void	generalMsg(std::string const &msg, Client *client);

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