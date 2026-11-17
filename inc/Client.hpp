#pragma once

#include <string>
 class Client
 {
	public:
		Client(int fd, std::string const &address);
		~Client();

		int					getFD() const;
		bool				isRegistered() const;
		bool				hasPass() const;
		std::string const	&getNickname() const;
		std::string const	&getUsername() const;
		std::string const	&getAddress() const;
		std::string const	&getPrefix() const;
		
		void				setNickname(std::string const &nickname);
		void				setUsername(std::string const &user);
		void				setPass(bool status);

		void				enqueue(std::string const &line);
		void				requestDisconnect(std::string const &quitMsg);

		std::string			&getEntryBuffer();
		std::string			&getExitBuffer();
		bool				isToDisconnect() const;
		std::string const	&getQuitMsg() const;

	private:
		int			fd_;
		std::string	nickName_;
		std::string	userName_;
		std::string	address_;
		bool		hasPass_;
		bool		isRegistered;
		std::string	entryBuffer_;
		std::string	exitBuffer_;
		bool	toDisconnect_;
		std::string	quitMsg_;

		Client();
		Client(Client const &src);
		Client	&operator=(Client const &rhs);
};