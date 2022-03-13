#include "User.h"
#include <iostream>

User::User(Server &server, int client_fd) : _server(server), _client_fd(client_fd)
{
	_nickname.clear();
	_username.clear();
	_state = user_state_new;
	_user_password_hash = 0;
}

User::~User()
{

}

void User::apply(user_commands cmd, std::vector<std::string> &args)
{
//	std::cout << "args: ";
//	for (std::vector<std::string>::iterator it = args.begin();
//		it != args.end(); ++it)
//	{
//		std::cout << "|" << *it << ":" << (*it).size() << "|";
//	}
//	std::cout << std::endl;

	switch (cmd)
	{
		case cmd_none:
			break;
		case cmd_pass:
			pass_handler(args);
			break;
		case cmd_user:
			user_handler(args);
			break;
		case cmd_nick:
			nick_handler(args);
			break;
	}


}

void User::pass_handler(std::vector<std::string> &args)
{
	if (_state != user_state_new)
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_ALREADYREGISTRED));
		return;
	}
	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NEEDMOREPARAMS));
		return;
	}
	std::string user_password = args.front();
	if (user_password.front() == ':')
		user_password = user_password.erase(0, 1);
	_user_password_hash = Utils::to_hash(user_password);
}

void User::nick_handler(std::vector<std::string> &args)
{
	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NONICKNAMEGIVEN));
		return;
	}
	if (false) // check nick is in use with other user
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NICKNAMEINUSE));
		return;
	}
	if (false) // check nick is valid (without forbidden characters)
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_ERRONEUSNICKNAME));
		return;
	}
	_nickname = args.front();
	std::cout << "[" << _client_fd << "]: NICK set <" << _nickname << ">"
			  << std::endl;
	if (!_username.empty())
		start_authorization();
}

void User::user_handler(std::vector<std::string> &args)
{
//	if (_state != user_state_password_accept)
//	{
//		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_ALREADYREGISTRED));
//		return;
//	}
	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NEEDMOREPARAMS));
		return;
	}
	_username = args.front();
	std::cout << "[" << _client_fd << "]: USER set <" << _username << ">"
		<< std::endl;

	if (!_nickname.empty())
		start_authorization();
}

void User::send_hello_client()
{
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTDSTART));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_1));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_2));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_3));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_4));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_5));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_6));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_7));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_8));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_9));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_10));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_11));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_12));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_13));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_14));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_15));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_16));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_17));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_18));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_19));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_20));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_21));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_22));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_23));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_24));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_25));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_26));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_27));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_28));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_29));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_30));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_31));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_32));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_33));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_34));
//	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_MOTD_35));
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_ENDOFMOTD));
}

bool User::is_need_close()
{
	return _state == user_state_need_close;
}

void User::start_authorization()
{
	if (!_server.check_password(_user_password_hash))
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_ALREADYREGISTRED));
		_state = user_state_need_close;
		return;
	}
	std::cout << "[" << _client_fd << "]: PASS accepted" << std::endl;
	_state = user_state_authorized;
	send_hello_client();
}

void User::set_need_close()
{
	_state = user_state_need_close;
}

std::string User::fill_placeholders(std::string s)
{
	std::string msg(s);

	Utils::replace(msg, "<nick>", _nickname);
	Utils::replace(msg, "<user>", _username);
	Utils::replace(msg, "<server>", SERVER_NAME);

	return msg;
}
