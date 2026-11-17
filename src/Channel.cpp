#include "Channel.hpp"

Channel::Channel(std::string const &name ): name_(name), topicTime_(0), inviteOnly_(false), topicLocked_(false), limit_(0) {}

Channel::~Channel() {}

std::string	const	&Channel::getName() const {
	return this->name_;
}

std::string	const	&Channel::getTopic() const {
	return this->topic_;
}

std::string	const	&Channel::getTopicSetter() const {
	return this->topicSetter_;
}

std::time_t	Channel::getTopicTime() const {
	return this->topicTime_;
}

std::string	const	&Channel::getKey() const {
	return this->key_;
}

size_t	Channel::getLimit() const {
	return this->limit_;
}

std::string	Channel::getModeString() const {
	std::string	modes = "+";
	std::string	params = "";

	if (this->inviteOnly_)
		modes.push_back('i');
	if (this->topicLocked_)
		modes.push_back('t');
	if (!this->key_.empty()) {
		modes.push_back('k');
		params += " " + this->key_;
	}
	if (this->limit_ > 0) {
		modes.push_back('l');
		params += " " + toString(this->limit_);
	}
	if (modes == "+")
		return std::string();
	return modes + params;
}

void	Channel::setTopic(std::string const &topic, std::string const &setter) {
	this->topic_ = topic;
	this->topicSetter_ = setter;
	this->topicTime_ = std::time(NULL);
}

void	Channel::setKey(std::string const &key) {
	this->key_ = key;
}

void	Channel::setLimit(size_t limit) {
	this->limit_ = limit;
}

void	Channel::setInviteOnly(bool status) {
	this->inviteOnly_ = status;
}

void	Channel::setTopicLocked(bool status) {
	this->topicLocked_ = status;
}

void	Channel::addMember(Client *client) {
	this->members_.insert(client);
}

void	Channel::removeMember(Client *client) {
	this->members_.erase(client);
	this->demote(client);
	this->removeInvite(client);
}

bool	Channel::isMember(Client *client) const {
	if (this->members_.find(client) != this->members_.end())
		return true;
	return false;
}

void	Channel::promote(Client *client) {
	this->operators_.insert(client);
}

void	Channel::demote(Client *client) {
	this->operators_.erase(client);
}

bool	Channel::isOperator(Client *client) const {
	if (this->operators_.find(client) != this->operators_.end())
		return true;
	return false;
}

void	Channel::invite(Client *client) {
	this->invited_.insert(client);
}

void	Channel::removeInvite(Client *client) {
	this->invited_.erase(client);
}

bool	Channel::isInvited(Client *client) const {
	if (this->invited_.find(client) != this->invited_.end())
		return true;
	return false;
}

bool	Channel::isFull() const {
	if (limit_ > 0 && this->members_.size() >= limit_)
		return true;
	return false;
}

bool	Channel::isEmpty() const {
	if (this->members_.empty())
		return true;
	return false;
}
