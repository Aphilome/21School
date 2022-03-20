#include "User.h"

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
	_user_password_hash = Utils::to_hash(user_password);
}

void User::nick_handler(std::vector<std::string> &args)
{
	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NONICKNAMEGIVEN));
		return;
	}
	_nickname = args.front();
	if (_server.is_nick_exist(_nickname))
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NICKNAMEINUSE));
		return;
	}
	if (!is_valid_nick(_nickname))
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_ERRONEUSNICKNAME));
		return;
	}

	std::cout << "[" << _client_fd << "]: NICK set <" << _nickname << ">" << std::endl;
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
	std::cout << "[" << _client_fd << "]: USER set <" << _username << ">" << std::endl;

	if (!_nickname.empty())
		start_authorization();
}

void User::privmsg_handler(std::vector<std::string> &args)
{
	notice_handler(args);
	_server.send_msg_to_client(_client_fd, fill_placeholders(RPL_AWAY));
}

void User::ison_handler(std::vector<std::string> &args)
{
	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NEEDMOREPARAMS));
		return;
	}

	_online_nicks.clear();
	for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); ++it)
	{
		if (_server.is_nick_exist(*it))
			_online_nicks += (*it) + " ";
	}
	if (!_online_nicks.empty())
		_online_nicks.pop_back();
	std::string msg = fill_placeholders(RPL_ISON);
	_server.send_msg_to_client(_client_fd, msg);
}

void User::notice_handler(std::vector<std::string> &args)
{
	/*
           ERR_CANNOTSENDTOCHAN ???           ERR_NOTOPLEVEL ???
           ERR_WILDTOPLEVEL ???                ERR_TOOMANYTARGETS ???
	 * */

	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NORECIPIENT));
		return;
	}
	if (args.size() == 1)
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NOTEXTTOSEND));
		return;
	}
	std::string target = args.front();
	if (!_server.is_nick_exist(target))
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NOSUCHNICK));
		return;
	}

	_target = target;
	_send_msg = args[1];
	_server.new_messege_for(args[0], fill_placeholders(MESSAGE));
}

void User::join_handler(std::vector<std::string> &args)
{
	// кроме \r, \n, \g, SPACE, \0, ,.
	// Имя канала – строка (начинающаяся с символа & или #) длинной до 200 символов.
	//  ERR_BANNEDFROMCHAN ???
	//        ERR_INVITEONLYCHAN???           ERR_BADCHANNELKEY ???
	//        ERR_CHANNELISFULL ???           ERR_BADCHANMASK ???
	//                   ERR_TOOMANYCHANNELS???
	//        RPL_TOPIC

	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NEEDMOREPARAMS));
		return;
	}
	// ERR_NOSUCHCHANNEL

	//RPL_TOPIC
}