#ifndef USER_H
#define USER_H

#include "../Server/Server.h"
#include "../Utils/Replies.h"

class Server;

enum user_state
{
	user_state_new,
	user_state_authorized,
	user_state_need_close,
};

class User
{
private:
	Server						&_server;
	int 						_client_fd;
	std::string					_nickname;
	std::string					_username;
	std::string 				_target;
	std::string 				_send_msg;
	std::string 				_online_nicks;
	unsigned long				_user_password_hash;
	user_state					_state;
	std::vector<std::string>	_new_messages;

	void pass_handler(std::vector<std::string> &args);
	void nick_handler(std::vector<std::string> &args);
	void user_handler(std::vector<std::string> &args);
	void privmsg_handler(std::vector<std::string> &args);
	void ison_handler(std::vector<std::string> &args);
	void notice_handler(std::vector<std::string> &args);

	void send_hello_client();
	void start_authorization();
	std::string fill_placeholders(std::string s);
	bool is_valid_nick(std::string nick);

public:
	User(Server &server, int client_fd);
	~User();

	void	apply(user_commands cmd, std::vector<std::string> &args);
	bool 	is_need_close();
	void 	set_need_close();
	void 	get_new_message(const std::string& msg);
	void 	send_messages_to_client();
	std::string get_nickname();
};

#endif
