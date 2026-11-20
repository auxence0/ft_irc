#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "server.hpp"
#include "Client.hpp"
#include "Replies.hpp"
#include "Utils.hpp"

class server;
class Client;

struct Message
{
	std::string	prefix;
	std::string	command;
	std::vector<std::string>	para;	
};

typedef	void	(*CommandHandler)(server&, Client&, const Message&);


void	dispathCommand(server &serv, Client &client, Message &msg);

void	cmd_join(server &serv, Client &client, Message const &msg);
void	cmd_part(server &serv, Client &client, Message const &msg);
void	cmd_privmsg(server &serv, Client &client, Message const &msg);
void	cmd_notice(server &serv, Client &client, Message const &msg);
void	cmd_names(server &serv, Client &client, Message const &msg);
void	cmd_list(server &serv, Client &client, Message const &msg);
void	cmd_kick(server &serv, Client &client, Message const &msg);
void	cmd_invite(server &serv, Client &client, Message const &msg);
void	cmd_topic(server &serv, Client &client, Message const &msg);
void	cmd_mode(server &serv, Client &client, Message const &msg);
void	cmd_pass(server &serv, Client &client, Message const &msg);
void	cmd_nick(server &serv, Client &client, Message const &msg);
void	cmd_user(server &serv, Client &client, Message const &msg);
void	cmd_cap(server &serv, Client &client, Message const &msg);
void	cmd_quit(server &serv, Client &client, Message const &msg);