#include "Server.h"

Server::Server(int port, unsigned long password_hash)
		: _ready_to_start(false), _server_port(port), _server_password_hash(password_hash)
{
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd == -1)
		Utils::error_exit(ERROR_NEW_SOCKET);

	sockaddr_in hint = {};
	hint.sin_family = AF_INET;
	hint.sin_port = htons(_server_port);
	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
	if (bind(_server_fd, (sockaddr*)&hint, sizeof(hint)) == -1)
		Utils::error_exit(ERROR_BIND_PORT);

	if (listen(_server_fd, SOMAXCONN) == -1)
		Utils::error_exit(ERROR_PORT_LISTENING);

	pollfd pfd = {};
	pfd.fd = _server_fd;
	pfd.events = POLLIN;
	_poll_fds.push_back(pfd);

	_ready_to_start = true;

	(void)_server_password_hash; // for clients will be used
}

Server::~Server()
{
	close(_server_fd);
	(void)_server_port; // NEED free port
}

void Server::run()
{
	if (!_ready_to_start)
		Utils::error_exit(ERROR_SERVER_READY);
	show_info();
	while (true)
	{
		if (poll(&(_poll_fds[0]), _poll_fds.size(), 1000) == -1)
		{
			Utils::error_print(ERROR_POLL);
			usleep(POLL_SLEEP_TIME_MS);
			continue;
		}
		if (_poll_fds[0].revents == POLLIN)
			new_client_handler();
		else
		{
			std::vector<int> need_to_del;
			for (std::vector<pollfd>::iterator it = _poll_fds.begin(); it != _poll_fds.end(); ++it)
			{
				if ((*it).fd == _server_fd)
					continue;
				if (_users[(*it).fd]->is_need_close())
				{
					//close_client_connection((*it).fd);

					need_to_del.push_back((*it).fd);

					//(*it).revents = POLLIN | POLLHUP;
				}
				else
					old_client_handler((*it).fd, (*it).revents);

			}

			for (std::vector<int>::iterator it = need_to_del.begin(); it !=
					need_to_del.end(); ++it)
			{
				close_client_connection((*it));
			}
		}
	}
}

void Server::new_client_handler()
{
	sockaddr_in address = {};
	socklen_t csin_len = sizeof(address);
	int new_client_fd = accept(_server_fd, (struct sockaddr *)&address, &csin_len);
	if (new_client_fd == -1)
	{
		Utils::error_print(ERROR_CLIENT_NEW_SOCKET);
		return;
	}

	std::cout << "[" << new_client_fd  << "]: new connection" << std::endl;
	pollfd client_pfd = {};
	client_pfd.fd = new_client_fd;
	client_pfd.events = POLLIN;
	_poll_fds.push_back(client_pfd);
	User *user = new User(*this, new_client_fd);
	_users[new_client_fd] = user;
	//std::string buffer = "Hello [" + std::to_string(new_client_fd) + "]!\r\n";
	//send_msg_to_client(new_client_fd, buffer);
}

void Server::old_client_handler(int client_fd, short client_event)
{
	_users[client_fd]->send_messages_to_client();
	if (client_event == (POLLIN | POLLHUP))
	{

		_users[client_fd]->set_need_close();
		//close_client_connection(client_fd);
		return;
	}
	if (client_event == POLLIN)
	{
		char buffer[MSG_BUFFER_SIZE + 1];
		memset(buffer, 0, MSG_BUFFER_SIZE);
		ssize_t size = recv(client_fd, &buffer, MSG_BUFFER_SIZE, 0);
		if (size == -1)
		{
			std::cerr << "[" << client_fd << "]: break receive msg" <<
				std::endl;
			return;
		}
		if (size == 0)
		{
			std::cout << "[" << client_fd << "]: empty msg. Need delete  "
											 "connection "
											 <<	std::endl;
			close(client_fd);
			return;
		}
		buffer[size] = 0;
		std::cout << "[" << client_fd << "]: " << buffer;
		std::string s_buffer(buffer);

		// PARSE MSG FROM CLIENT
		std::vector<std::string> messages = Utils::split(s_buffer, '\n');
		for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it)
		{
			std::vector<std::string> args;
			user_commands cmd = command_parser(*it, args);
			if (cmd != cmd_none)
				_users[client_fd]->apply(cmd, args);
		}
	}
}

void Server::show_info() const
{
	std::cout << "************   Server run   ************" << std::endl;
	std::cout << "*"
			  << std::setw(20) << std::right << "fd: "
			  << std::setw(18) << std::left << _server_fd
			  << "*" << std::endl;
	std::cout << "*"
			  << std::setw(20) << std::right << "port: "
			  << std::setw(18) << std::left << _server_port
			  << "#" << std::endl;
	std::cout << "*"
			  << std::setw(20) << std::right << "psw hash: "
			  << std::setw(18) << std::left << _server_password_hash
			  << "*" << std::endl;
	std::cout << "****************************************" << std::endl;
}

void Server::send_msg_to_client(int client_fd, const std::string& msg)
{
	std::cout << "-> [" << client_fd << "]: " << msg << std::endl;
	if (send(client_fd, msg.c_str(), msg.length(), 0) == -1)
		Utils::error_print(client_fd, ERROR_SEND_MSG);
}

bool Server::check_password(unsigned long user_password_hash) const
{
	return _server_password_hash == user_password_hash;
}

void Server::close_client_connection(int client_fd)
{
	std::cout << "[" << client_fd << "]: close connection " << std::endl;
	close(client_fd);
	//close(client_fd);
	delete _users[client_fd];
	_users.erase(client_fd);


	for (std::vector<pollfd>::iterator it = _poll_fds.begin(); it != _poll_fds.end(); ++it)
	{
		if ((*it).fd == client_fd)
		{
			_poll_fds.erase(it);
			it = _poll_fds.begin();
		}
	}
}

void Server::registered_new_client(const std::string& nick, int client_fd)
{
	_nick_to_fd[nick] = client_fd;
}

bool Server::is_nick_exist(const std::string& nick)
{
	return _nick_to_fd.find(nick) != _nick_to_fd.end();
}

void Server::new_messege_for(const std::string& nick, const std::string& message)
{
	int dst_fd = _nick_to_fd[nick];
	_users[dst_fd]->get_new_message(message);
}
