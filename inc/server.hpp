# include <poll.h>
# include <vector>
# include <map> 
# include <iostream>
# include <map>
# include <sstream>
# include "../inc/Client.hpp"
# include "../inc/Channel.hpp"
# include "../inc/Utils.hpp"

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
		Channel    *createChannel(std::string const &channelName);
        void    removeChannel(std::string const &channelName);
        Client    *getClientNickname(std::string const &nickName);

	private:
		server( const server& obj );
		server&	operator=( const server& rhs );
		server();
		void		new_client();
		void		readData(Client& client);
		int			port_;
		std::string	password_;
		int			serverSocket_;
		std::vector<pollfd>		pollfds;
		std::map<int, Client>	clients;
        std::map<std::string, Channel*>    channels_;
};