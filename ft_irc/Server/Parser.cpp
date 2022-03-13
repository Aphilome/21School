#include "Server.h"

user_commands	Server::command_parser(std::string msg, std::vector<std::string> &args_out)
{
	if (msg.empty())
		return cmd_none;
	msg = msg.erase(msg.size() - 1, 1);
	std::vector<std::string> s = Utils::split(msg, ' ');
	if (s.empty())
		return cmd_none;
	std::string cmd_raw = s.front();
	std::transform(cmd_raw.begin(), cmd_raw.end(), cmd_raw.begin(), ::toupper);

	user_commands cmd = cmd_none;
	if (cmd_raw == "PASS")
		cmd = cmd_pass;
	else if (cmd_raw == "USER")
		cmd = cmd_user;
	else if (cmd_raw == "NICK")
		cmd = cmd_nick;

	if (cmd != cmd_none)
		for (std::vector<std::string>::iterator it = s.begin() + 1; it != s
		.end();
			 ++it)
		{
			if (!it->empty())
				args_out.push_back(*it);
		}
	return cmd;
}
