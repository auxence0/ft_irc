#include "../inc/Command.hpp"

void	dispathCommand(server &serv, Client &client, Message &msg) {
	static	std::map<std::string, CommandHandler> commands;
		
	if (commands.empty()) {
		commands["JOIN"] = cmd_join;
		commands["PART"] = cmd_part;
		commands["PRIVMSG"] = cmd_privmsg;
		commands["NOTICE"] = cmd_notice;
		commands["NAMES"] = cmd_names;
		commands["LIST"] = cmd_list;
		commands["KICK"] = cmd_kick;
		commands["INVITE"] = cmd_invite;
		commands["TOPIC"] = cmd_topic;
		commands["MODE"] = cmd_mode;
		commands["PASS"] = cmd_pass;
		commands["NICK"] = cmd_nick;
		commands["USER"] = cmd_user;
		commands["CAP"] = cmd_cap;
		commands["QUIT"] = cmd_quit;
	}

	if (msg.command.empty())
		return;
	if (!client.isRegistered() && (msg.command != "PASS" && msg.command != "NICK" && msg.command != "USER" &&
		msg.command != "CAP" && msg.command != "QUIT")) {
		client.enqueue(ERR_NOTREGISTERED(client.getNickname()));
		return;
	}
	std::map<std::string, CommandHandler>::iterator it = commands.find(msg.command);
	if (it == commands.end()) {
		client.enqueue(ERR_UNKNOWNCOMMAND(client.getNickname(), msg.command));
		return;
	}
	else
		it->second(serv, client, msg);
}
