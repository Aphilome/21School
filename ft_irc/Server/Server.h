#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <poll.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>

#define MSG_BUFFER_SIZE	4096

class Server
{
private:

	bool _ready_to_start;
	int _server_port;
	int _server_fd;
	unsigned long _password_hash;
	std::vector<pollfd> poll_fds;

	void new_client_handler();
	void old_client_handler(int client_fd, short client_revents);

public:
	Server(int port, unsigned long password_hash);
	~Server();

	void Run();
};


#endif
