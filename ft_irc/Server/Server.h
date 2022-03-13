#ifndef SERVER_H
#define SERVER_H

#define MSG_BUFFER_SIZE	4096

#include <iostream>
#include <vector>
#include <poll.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>
#include <iomanip>
#include <map>
#include "../Utils/Utils.h"
#include "../User/User.h"

class User;

class Server
{
private:
	bool					_ready_to_start;
	int						_server_port;
	int						_server_fd;
	unsigned long			_server_password_hash;
	std::vector<pollfd>		_poll_fds;
	std::map<int, User*>	_users;

	void new_client_handler();
	void old_client_handler(int client_fd, short client_event);
	void show_info() const;
	user_commands command_parser(std::string msg,
								 std::vector<std::string> &args_out);
	void close_client_connection(int client_fd);
public:
	Server(int port, unsigned long password_hash);
	~Server();

	void run();
	bool check_password(unsigned long user_password_hash) const;
	void send_msg_to_client(int client_fd, const std::string& msg);
};


#endif
