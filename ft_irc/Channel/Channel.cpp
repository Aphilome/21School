#include "Channel.h"

std::string Channel::get_topic()
{
	return _topic;
}

Channel::Channel(Server &server, std::string name, User *admin)
	: _server(server)
{
	_admin = admin;
	_topic = DEFAULT_TOPIC;
	_name = name;
	_users.push_back(admin);
	(void)_server;
}

Channel::~Channel()
{

}

void Channel::leave_user(User *user)
{
	_users.erase(std::find(_users.begin(), _users.end(), user));
	if (user == _admin)
	{
		if (!_users.empty())
			_admin = _users.front();
		else
			_admin = nullptr;
	}
}

bool Channel::is_empty_channel()
{
	return _users.empty();
}

std::string Channel::get_name()
{
	return _name;
}

std::string Channel::get_user_nicks()
{
	std::string users;
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); ++it)
		users += (*it)->get_nickname() + " ";
	if (!users.empty())
		users.pop_back();
	return users;
}

void Channel::add_new_user(User *user)
{
	if (std::find(_users.begin(), _users.end(), user) != _users.end())
		return;
	_users.push_back(user);
}
