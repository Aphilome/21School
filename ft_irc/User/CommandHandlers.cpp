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
	//  ERR_BANNEDFROMCHAN ???
	//        ERR_INVITEONLYCHAN???           ERR_BADCHANNELKEY ???
	//        ERR_CHANNELISFULL ???           ERR_BADCHANMASK ???
	//                   ERR_TOOMANYCHANNELS???
	//

	if (args.empty())
	{
		_server.send_msg_to_client(_client_fd, fill_placeholders(ERR_NEEDMOREPARAMS));
		return;
	}
	std::string channel = args[0];
	if (channel.empty() || channel[0] != '#' || channel.size() >= 200)
	{
		std::string msg = ERR_BADCHANNELKEY;
		Utils::replace(msg, "<channel>", channel);
		_server.send_msg_to_client(_client_fd, msg);
		return;
	}
	if (channel == "0")
	{
		leave_all_channels();
		return;
	}

	if (channel.find('\r') != std::string::npos
		|| channel.find('\n') != std::string::npos
		|| channel.find(29) != std::string::npos
		|| channel.find(' ') != std::string::npos
		|| channel.find('\0') != std::string::npos
		|| channel.find(',') != std::string::npos)
	{
		std::string msg = ERR_BADCHANNELKEY;
		Utils::replace(msg, "<channel>", channel);
		_server.send_msg_to_client(_client_fd, msg);
		return;
	}

	Channel *new_channel = _server.join_to_channel(channel, _client_fd);
	_channels.push_back(new_channel);

	std::string msg = fill_placeholders(JOIN, channel);
	_server.send_msg_to_client(_client_fd, msg);

	msg = RPL_TOPIC;
	Utils::replace(msg, "<channel>", channel);
	Utils::replace(msg, "<topic>", new_channel->get_topic());
	std::cout << "Join [" << _client_fd << "] to channel " << new_channel->get_name() << std::endl;
	_server.send_msg_to_client(_client_fd, msg);

	msg = RPL_NAMREPLY;
	Utils::replace(msg, "<channel>", channel);
	Utils::replace(msg, "<comment>", new_channel->get_user_nicks());
	_server.send_msg_to_client(_client_fd, msg);

	msg = RPL_ENDOFNAMES;
	Utils::replace(msg, "<channel>", channel);
	_server.send_msg_to_client(_client_fd, msg);
}
