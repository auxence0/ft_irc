#pragma once

#include <string>
 class Client
 {
	public:
		Client(int fd, const std::string& address);
		Client(Client const &obj);
		~Client();

		int					getFD() const;
		bool				isRegistered() const;
		bool				hasPass() const;
		const std::string&	getNickname() const;
		const std::string&	getUsername() const;
		const std::string&	getAddress() const;
		const std::string&	getPrefix() const;
		
		void				setNickname(const std::string& nickname);
		void				setUsername(const std::string& user);
		void				setPass(bool status);

		void				enqueue(const std::string& line);
		void				requestDisconnect(const std::string& quitMsg);

		std::string&		getEntryBuffer();
		std::string&		getExitBuffer();
		bool				isToDisconnect() const;
		const std::string&	getQuitMsg() const;

	private:
		int			fd_;
		std::string	nickName_;
		std::string	userName_;
		std::string	address_;
		bool		hasPass_;
		std::string	entryBuffer_;
		std::string	exitBuffer_;
		bool		toDisconnect_;
		std::string	quitMsg_;

		Client();
		Client	&operator=(Client const &rhs);
};