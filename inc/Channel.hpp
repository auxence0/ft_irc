#pragma once

#include <string>
#include <set>
#include <ctime>
#include "Client.hpp"
#include "Utils.hpp"

class Channel
{
	public :
		Channel(std::string const &name);
		~Channel();

		std::string const		&getName() const;
		std::string const		&getTopic() const;
		std::string const		&getTopicSetter() const;
		std::time_t				getTopicTime() const;
		std::string const		&getKey() const;
		size_t					getLimit() const;
		std::string				getModeString() const;
		bool					getInviteOnly() const;
		bool					getTopicLocked() const;

		void					setTopic(std::string const &topic, std::string const &setter);
		void					setKey(std::string const &key);
		void					setLimit(size_t limit);
		void					setInviteOnly(bool status);
		void					setTopicLocked(bool status);

		void					addMember(Client *client);
		void					removeMember(Client *client);
		bool					isMember(Client *client) const;

		void					promote(Client *client);
		void					demote(Client *client);
		bool					isOperator(Client *client) const;

		void					invite(Client *client);
		void					removeInvite(Client *client);
		bool					isInvited(Client *client) const;

		bool					isFull() const;
		bool					isEmpty() const;

		std::set<Client*> const	&getMembers() const;
	
	private :
		std::string			name_;
		std::string			topic_;
		std::string			topicSetter_;
		std::time_t			topicTime_;
		bool				inviteOnly_;
		bool				topicLocked_;
		std::string			key_;
		size_t				limit_;
		std::set<Client*>	members_;
		std::set<Client*>	operators_;
		std::set<Client*>	invited_;
		Channel();
		Channel(Channel const &src);
		Channel	&operator=(Channel const &rhs);
};