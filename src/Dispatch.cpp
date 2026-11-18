#include "../inc/Command.hpp"
#include "../inc/server.hpp"
#include "../inc/Client.hpp"
#include "../inc/Replies.hpp"

void	dispathCommand(server &serv, Client &client, Message &msg) {
	static	std::map<std::string, CommandHandler> commands;
		
	if (commands.empty()) {
		commands["JOIN"] = &cmd_join;
		commands["PART"] = &cmd_part;
		commands["PRIVMSG"] = &cmd_privmsg;
		commands["NOTICE"] = &cmd_notice;
		commands["NAMES"] = &cmd_names;
		commands["LIST"] = &cmd_list;
		commands["KICK"] = &cmd_kick;
		commands["INVITE"] = &cmd_invite;
		commands["TOPIC"] = &cmd_topic;
	}

	std::map<std::string, CommandHandler>::iterator it = commands.find(msg.command);
	if (it == commands.end()) {
		std::cerr << ERR_UNKNOWNCOMMAND(client.nickName_) << std::endl;
		return;
	}
	if (!client.isRegistered()) {
		std::cerr << ERR_NOTREGISTERED()
	}
}
