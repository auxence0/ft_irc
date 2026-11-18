#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

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