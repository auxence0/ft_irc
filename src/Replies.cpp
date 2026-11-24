#include "../inc/Replies.hpp"
#include <string>

static	std::string	name(std::string const &nickname) {
	if (nickname.empty())
		return "*";
	return nickname;
}

std::string	RPL_WELCOME(std::string const &nickname, std::string const &prefix) {
	return ":ircserv 001 " + name(nickname) + " :Welcome to the IRC Network, " + prefix;
}

std::string	RPL_YOURHOST(std::string const &nickname) {
	return ":ircserv 002 " + name(nickname) + " :Your host is ircserv, running version 1.0";
}

std::string	RPL_CREATED(std::string const &nickname, std::string const &date) {
	return ":ircserv 003 " + name(nickname) + " :This server was created " + date;
}


std::string	RPL_MYINFO(std::string const &nickname) {
	return ":ircserv 004 " + name(nickname) + " ircserv 1.0 - itkol";
}

std::string	RPL_CHANNELMODEIS(std::string const &nickname, std::string const &channel, std::string const &modes) {
	return ":ircserv 324 " + name(nickname) + " " + channel + " " + modes;
}

std::string	RPL_NOTOPIC(std::string const &nickname, std::string const &channel) {
	return ":ircserv 331 " + name(nickname) + " " + channel + " :No topic is set";
}

std::string	RPL_TOPIC(std::string const &nickname, std::string const &channel, std::string const &topic) {
	return ":ircserv 332 " + name(nickname) + " " + channel + " :" + topic;
}

std::string	RPL_INVITING(std::string const &nickname, std::string const &target, std::string const &channel) {
	return ":ircserv 341 " + name(nickname) + " " + target + " " + channel;
}

std::string	RPL_NAMREPLY(std::string const &nickname, std::string const &channel, std::string const &list) {
	return ":ircserv 353 " + name(nickname) + " = " + channel + " :" + list; 
}

std::string	RPL_ENDOFNAMES(std::string const &nickname, std::string const &channel) {
	return ":ircserv 366 " + name(nickname) + " " + channel + " :End of /NAMES list";
}

std::string	ERR_NOSUCHNICK(std::string const &nickname, std::string const &target) {
	return ":ircserv 401 " + name(nickname) + " " + target + " :No such nick/channel";
}

std::string	ERR_NOSUCHCHANNEL(std::string const &nickname,std::string const &channel) {
	return ":ircserv 403 " + name(nickname) + " " + channel + " :No such channel";
}

std::string	ERR_CANNOTSENDTOCHAN(std::string const &nickname, std::string const &channel) {
	return ":ircserv 404 " + name(nickname) + " " + channel + " :Cannot send to channel";
}

std::string	ERR_NORECIPIENT(std::string const &nickname, std::string const &command) {
	return ":ircserv 411 " + name(nickname) + " :No recipient given (" + command + ")";
}

std::string	ERR_NOTEXTTOSEND(std::string const &nickname) {
	return ":ircserv 412 " + name(nickname) + " :No text to send";
}

std::string	ERR_UNKNOWNCOMMAND(std::string const &nickname, std::string const &command) {
	return ":ircserv 421 " + name(nickname) + " " + command + " :Unknown command";
}

std::string	ERR_NONICKNAMEGIVEN(std::string const &nickname) {
	return ":ircserv 431 " + name(nickname) + " :No nickname given";
}

std::string	ERR_ERRONEUSNICKNAME(std::string const &nickname, std::string const &badnickname) {
	return ":ircserv 432 " + name(nickname) + " " + badnickname + " :Erroneus nickname";
}

std::string	ERR_NICKNAMEINUSE(std::string const &nickname, std::string const &badnickname) {
	return ":ircserv 433 " + name(nickname) + " " + badnickname + " :Nickname is already in use";
}

std::string	ERR_USERNOTINCHANNEL(std::string const &nickname, std::string const &target, std::string const &channel) {
	return ":ircserv 441 " + name(nickname) + " " + target + " " + channel + " :They aren't on that channel";
}

std::string	ERR_NOTONCHANNEL(std::string const &nickname, std::string const &channel) {
	return ":ircserv 442 " + name(nickname) + " " + channel + " :You're not on that channel";
}

std::string	ERR_USERONCHANNEL(std::string const &nickname, std::string const &target, std::string const &channel) {
	return ":ircserv 443 " + name(nickname) + " " + target + " " + channel + " :is already on channel";
}

std::string	ERR_NOTREGISTERED(std::string const &nickname) {
	return ":ircserv 451 " + name(nickname) + " :You have not registered";
}

std::string	ERR_NEEDMOREPARAMS(std::string const &nickname, std::string const &command) {
	return ":ircserv 461 " + name(nickname) + " " + command + " :Not enough parameters";
}

std::string	ERR_ALREADYREGISTERED(std::string const &nickname) {
	return ":ircserv 462 " + name(nickname) + " :You may not reregister";
}

std::string	ERR_PASSWDMISMATCH(std::string const &nickname) {
	return ":ircserv 464 " + name(nickname) + " :Password incorrect";
}

std::string	ERR_CHANNELISFULL(std::string const &nickname, std::string const &channel) {
	return ":ircserv 471 " + name(nickname) + " " + channel + " :Cannot join channel (+l)";
}

std::string	ERR_UNKNOWNMODE(std::string const &nickname, std::string const &modechar) {
	return ":ircserv 472 " + name(nickname) + " " + modechar + " :is unknown mode char to me";
}

std::string	ERR_INVITEONLYCHAN(std::string const &nickname, std::string const &channel) {
	return ":ircserv 473 " + name(nickname) + " " + channel + " :Cannot join channel (+i)";
}


std::string	ERR_BADCHANNELKEY(std::string const &nickname, std::string const &channel) {
	return ":ircserv 475 " + name(nickname) + " " +  channel + " :Cannot join channel (+k)";
}

std::string	ERR_CHANOPRIVSNEEDED(std::string const &nickname, std::string const &channel) {
	return ":ircserv 482 " + name(nickname) + " " + channel + " :You're not channel operator";
}
