# include "../inc/Client.hpp"

Client::Client(int fd, const std::string& address): fd_(fd), address_(address) {
	hasPass_ = false;
	toDisconnect_ = false;
}
Client::Client(Client const &obj): fd_(obj.fd_), nickName_(obj.nickName_), userName_(obj.userName_), address_(obj.address_), hasPass_(obj.hasPass_), entryBuffer_(obj.entryBuffer_), exitBuffer_(obj.exitBuffer_), toDisconnect_(obj.toDisconnect_),quitMsg_(obj.quitMsg_) {}

Client::~Client() {}

int	Client::getFD() const{
	return fd_;
}

std::string&	Client::getEntryBuffer() {
	return entryBuffer_;
}

bool	Client::hasPass() const {
	return hasPass_;
}

void	Client::setPass(bool status) {
	hasPass_ = status;
}
