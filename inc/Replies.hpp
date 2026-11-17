#pragma once

#include <string> 

std::string	RPL_WELCOME(std::string const &srv, std::string const &nickname, std::string const &prefix); //001
std::string	RPL_YOURHOST(std::string const &srv,std::string const &nickname); //002
std::string	RPL_CREATED(std::string const &srv, std::string const &nickname, std::string const &date); //003
std::string	RPL_MYINFO(std::string const &srv, std::string const &nickname); // 004

std::string	RPL_CHANNELMODEIS(std::string const &srv, std::string const &mickname, std::string const &channel, std::string const &modes); //324
std::string	RPL_NOTOPIC(std::string const &srv, std::string const &nickname, std::string const &channel); //331
std::string	RPL_TOPIC(std::string const &srv, std::string const &nickname, std::string const &channel, std::string const &topic); //332
std::string	RPL_INVITING(std::string const &srv, std::string const &nickname, std::string const &target, std::string const &channel); //341
std::string	RPL_NAMREPLY(std::string const &srv, std::string const &nickname, std::string const &channel, std::string const &list); //353
std::string	RPL_ENDOFNAMES(std::string const &srv, std::string const &nickname, std::string const &channel); //366

std::string	ERR_NOSUCHNICK(std::string const &srv, std::string const &nickname, std::string const &target); //401
std::string	ERR_NOSUCHCHANNEL(std::string const &srv, std::string const &nickname,std::string const &channel); //403
std::string	ERR_CANNOTSENDTOCHAN(std::string const &srv, std::string const &nickname, std::string const &channel); //404
std::string	ERR_NORECIPIENT(std::string const &srv, std::string const &nickname, std::string const &command); //411
std::string	ERR_NOTEXTTOSEND(std::string const &srv, std::string const &nickname); //412
std::string	ERR_UNKNOWNCOMMAND(std::string const &srv, std::string const &nickname, std::string const &command); //421
std::string	ERR_NONICKNAMEGIVEN(std::string const &srv, std::string const &nickname); //431
std::string	ERR_ERRONEUSNICKNAME(std::string const &srv, std::string const &nickname, std::string const &badnickname); //432
std::string	ERR_NICKNAMEINUSE(std::string const &srv, std::string const &nickname, std::string const &badnickname); //433
std::string	ERR_USERNOTINCHANNEL(std::string const &srv, std::string const &nickname, std::string const &target, std::string const &channel); //441
std::string	ERR_NOTONCHANNEL(std::string const &srv, std::string const &nickname, std::string const &channel); //442
std::string	ERR_USERONCHANNEL(std::string const &srv, std::string const &nickname, std::string const &target, std::string const &channel); //443
std::string	ERR_NOTREGISTERED(std::string const &srv, std::string const &nickname); //451
std::string	ERR_NEEDMOREPARAMS(std::string const &srv, std::string const &nickname, std::string const &command); //461
std::string	ERR_ALREADYREGISTERED(std::string const &srv, std::string const &nickname); //462
std::string	ERR_PASSWDMISMATCH(std::string const &srv, std::string const &nickname); //464
std::string	ERR_CHANNELISFULL(std::string const &srv, std::string const &nickname, std::string const &channel); //471
std::string	ERR_UNKNOWNMODE(std::string const &srv, std::string const &nickname, std::string const &modechar); //472
std::string	ERR_INVITEONLYCHAN(std::string const &srv, std::string const &nickname, std::string const &channel); //473
std::string	ERR_BADCHANNELKEY(std::string const &srv, std::string const &nickname, std::string const &channel); //475
std::string	ERR_CHANOPRIVSNEEDED(std::string const &srv, std::string const &nickname, std::string const &channel); //482

