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
	if (_users.empty())
		return;
	std::vector<User*>::iterator it = std::find(_users.begin(), _users.end(), user);
	if (it != _users.end())
	{
		_users.erase(it);
		if (user == _admin)
		{
			if (!_users.empty())
				_admin = _users.front();
			else
				_admin = nullptr;
		}
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

void Channel::new_channel_member_come()
{
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); ++it)
	{
		std::string msg = RPL_NAMREPLY;
		Utils::replace(msg, "<channel>", _name);
		Utils::replace(msg, "<comment>", get_user_nicks());
		_server.send_msg_to_client((*it)->get_client_fd(), msg);

		msg = RPL_ENDOFNAMES;
		Utils::replace(msg, "<channel>", _name);
		_server.send_msg_to_client((*it)->get_client_fd(), msg);
	}
}

