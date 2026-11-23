# include "Client.hpp"

Client::Client(int fd, const std::string& address): fd_(fd), address_(address) {}

Client::~Client() {}
