#include "Command.hpp"

bool	verifNameChannel(std::string &str) {
	if (str.empty())
		return false;
	if (str.size() >= 2 && str[0] == '#') {
		if (str.find(' ') != std::string::npos || str.find(',') != std::string::npos || str.find('\a') != std::string::npos)
			return false;
		return true;
	}
	return false;
}

void	cmd_join(server &serv, Client &client, Message const &msg) {
	if (msg.para.empty()) {
		client.enqueue(ERR_NEEDMOREPARAMS(client.getNickname(), msg.command));
		return;
	}
	std::vector<std::string>	channel = split(msg.para[0], ',');
	std::vector<std::string>	key;
	if (msg.para.size() >= 2)
		key = split(msg.para[1], ',');
	for (size_t i = 0; i < channel.size(); i++) {
		std::string	tmp;
		if (i < key.size())
			tmp = key[i];
		if (!verifNameChannel(channel[i])) {
			client.enqueue(ERR_NOSUCHCHANNEL(client.getNickname(),channel[i]));
			continue;
		}
		serv.getChannel(channel[i]);
	}
}

void	cmd_part(server &serv, Client &client, Message const &msg) {
	if (msg.para.empty()) {
		client.enqueue(ERR_NEEDMOREPARAMS(client.getNickname(), msg.command));
		return;
	}
	std::vector<std::string>	channel = split(msg.para[0], ',');
	std::string	tmp;
	if (msg.para.size() >= 2)
		tmp = msg.para[1];
}

void	cmd_topic(server &serv, Client &client, Message const &msg) {
	if (msg.para.empty()) {
		client.enqueue(ERR_NEEDMOREPARAMS(client.getNickname(), msg.command));
		return;
	}
	// if (msg.para.size() == 1)
	// if (msg.para.size() >= 2)
}

void	cmd_names(server &serv, Client &client, Message const &msg) {

}

void	cmd_list(server &serv, Client &client, Message const &msg) {

}














public
Channel	*createChannel(std::string const &channelName);
		void	removeChannel(std::string const &channelName);
		Client	*getClientNickname(std::string const &nickName);
private
		std::map<std::string, Channel*>	channels_;





Channel	*server::getChannel(std::string const &channelName) {
	std::map<std::string, Channel*>::iterator it = this->channels_.find(ircTolower(channelName));
	if (it == this->channels_.end())
		return NULL;
	return it->second;
}

std::map<std::string, Channel*> const &server::getChannels() const {
	return this->channels_;
}

void	server::quitAllChannel(Client *client) {
	if (!client)
		return;
	std::map<std::string, Channel*>::iterator it = channels_.begin();
	while(it != channels_.end()) {
		std::map<std::string, Channel*>::iterator tmp = it;
		it++;
		if (tmp->second->isMember(client)) {
			tmp->second->removeMember(client);
			if (tmp->second->isEmpty())
				this->removeChannel(tmp->first);
		}
	}
}

Channel	*server::createChannel(std::string const &channelName) {
	if (!this->getChannel(channelName)) {
		Channel	*newChannel = new Channel(channelName);
		channels_[ircTolower(channelName)] = newChannel;
		return newChannel;
	}
	return NULL;
}

void	server::removeChannel(std::string const &channelName) {
	std::map<std::string, Channel*>::iterator it = channels_.find(ircTolower(channelName));
	if (it == channels_.end())
		return;
	delete it->second;
	channels_.erase(it);
}

Client	*server::getClientNickname(std::string const &nickName) {	
	std::map<int, Client>::iterator	it = clients.begin();
	while(it != clients.end()) {
		if ()
	}
}

