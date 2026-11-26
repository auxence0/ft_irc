# include "../inc/server.hpp"
# include "../inc/Utils.hpp"

/// @brief initialisation du server
server::server(int port, const std::string& password): port_(port), password_(password) {
	serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket_ == -1)
		throw	std::runtime_error("Erorr: create socket");

	sockaddr_in	ServerAddr;

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(port_);
	ServerAddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(serverSocket_, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == -1)
		throw	std::runtime_error("Erorr: associate the socket with a local address and a port");
	if (listen(serverSocket_, 21) == -1)
		throw	std::runtime_error("Error: listen()");

	pollfd	servpoll;

	servpoll.fd = serverSocket_;
	servpoll.events = POLLIN;
	servpoll.revents = 0;
	pollfds.push_back(servpoll);
}

server::~server() {}

/// @brief Creation d'un client venant d'etre ajoute 
void	server::new_client() {
	pollfd		new_client;
	sockaddr_in	tmp_sock;
	socklen_t	len_sock = sizeof(tmp_sock);

	new_client.fd = accept(serverSocket_, (struct sockaddr*)&tmp_sock, &len_sock);
	new_client.events = POLLIN;
	new_client.revents = 0;
	if (new_client.fd == -1) {
		std::cerr << "Error: accept()\n";
		return ;
	}
	pollfds.push_back(new_client);
	clients.insert(std::pair<int, Client>(new_client.fd, Client(new_client.fd, "")));
}


/// @brief Verification du mot de passe entre par le client
void	server::handlePass(const std::string& msg, Client& client) {
	if (client.hasPass() == true)
		return ;
	std::istringstream	iss(msg.substr(4));
	std::string			password;

	iss >> std::ws;
	std::getline(iss, password);
	if (password == password_)
		client.setPass(true);
}

/// @brief Changer le nickname si il n'est pas utilise
void	server::handleNick(const std::string& msg, Client& client) {
	std::istringstream	iss(msg.substr(4));
	std::string			nickname;

	iss >> std::ws;
	std::getline(iss, nickname);
	nickname = ircTolower(nickname);
	bool	has_nickname = false;
	for (size_t i = 1; i < pollfds.size(); ++i) {
		if (clients[i].getNickname() == nickname) {
			has_nickname = true;
			break ;
		}
	}
	if (has_nickname == false)
		client.setNickname(nickname);
	else
		std::cerr << "Error: nickname already taken\n";
}

/// @brief recuperation de la cmd trouver par readData pour la traiter
void	server::handleCommand(const std::string& msg, Client& client) {
	std::string	cmd;
	std::istringstream	iss(msg);

	iss >> cmd;
	if (cmd == "PASS")
		handlePass(msg, client);
	else if (cmd == "NICK")
		handleNick(msg, client);
	std::cout << "Fonctionne ? : " << client.hasPass() << "\n";
}

Channel    *server::getChannel(std::string const &channelName) {
    std::map<std::string, Channel*>::iterator it = this->channels_.find(ircTolower(channelName));
    if (it == this->channels_.end())
        return NULL;
    return it->second;
}

std::map<std::string, Channel*> const &server::getChannels() const {
    return this->channels_;
}

void    server::quitAllChannel(Client *client) {
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

Channel    *server::createChannel(std::string const &channelName) {
    if (!this->getChannel(channelName)) {
        Channel    *newChannel = new Channel(channelName);
        channels_[ircTolower(channelName)] = newChannel;
        return newChannel;
    }
    return NULL;
}

void    server::removeChannel(std::string const &channelName) {
    std::map<std::string, Channel*>::iterator it = channels_.find(ircTolower(channelName));
    if (it == channels_.end())
        return;
    delete it->second;
    channels_.erase(it);
}

Client    *server::getClientNickname(std::string const &nickName) {    
    if (nickName.empty())
        return NULL;
    for(std::map<int, Client>::iterator    it = clients.begin(); it != clients.end(); it++)
        if (ircTolower(it->second.getNickname()) == ircTolower(nickName))
            return &it->second;
    return NULL;
}

/// @brief Sert a lire les donnees entree et les recuperer via le socket voulu
void	server::readData(Client& client) {
	char	read_buffer[100];
	ssize_t	bytes_read(0);
	bytes_read = recv(client.getFD(), read_buffer, 100, 0);
	if (bytes_read == -1) {
		std::cerr << "Error: recv failed()\n";
		return ;
	}
	std::string&	new_buffer = client.getEntryBuffer();
	if (bytes_read > 0)
		new_buffer.append(read_buffer, bytes_read);
	size_t	find_end_cmd(0);
	while (1) {
		find_end_cmd = new_buffer.find("\r\n");
		if (find_end_cmd == std::string::npos)
			return ;
		handleCommand(new_buffer.substr(0, find_end_cmd), client);
		new_buffer.erase(0, find_end_cmd + 2);
	}
}

/// @brief boucle principal en attente de donnees par poll()
void	server::run() {
	std::map<int, Client>::iterator it;
	while (1) {
		poll(&pollfds[0], pollfds.size(), 0);
		if (pollfds[0].revents & POLLIN)
			new_client();
		for (size_t i = 1; i < pollfds.size(); ++i) {
			if (pollfds[i].revents & POLLIN) {
				it = clients.find(pollfds[i].fd);
				if (it != clients.end()) {
				std::cout << "test\n";
					readData(it->second);
				}
			}
		}
	}
}
