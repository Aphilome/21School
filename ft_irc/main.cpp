#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <poll.h>
#include <vector>
#include <sstream>

#define BUFFER_SIZE 4096


bool str2int (int &i, char const *s)
{
	std::stringstream ss(s);
	ss >> i;
	if (ss.fail()) {
		// not an integer
		return false;
	}
	return true;
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Need set port" << std::endl;
		return -1;
	}
	int server_port;
	if (str2int(server_port, argv[1]) == false)
	{
		std::cerr << "Not integer" << std::endl;
		return -1;
	}
	if (server_port < 0 || server_port > 65535)
	{
		std::cerr << "Not range of port" << std::endl;
		return -1;
	}

	// Create a socket
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		std::cerr << "Can't create a socket! Quitting" << std::endl;
		return -1;
	}
	std::cout << "Server fd: " << server_fd << std::endl;

	// Bind the ip address and port to a socket
	sockaddr_in hint = {};
	hint.sin_family = AF_INET;
	hint.sin_port = htons(server_port);
	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

	if (bind(server_fd, (sockaddr*)&hint, sizeof(hint)) == -1)
	{
		std::cerr << "Can't bind" << std::endl;
		return -1;
	}

	// Tell Winsock the socket is for listening
	if (listen(server_fd, SOMAXCONN) == -1)
	{
		std::cerr << "Can't listen" << std::endl;
		return -1;
	}

	std::vector<pollfd> poll_fds;

	pollfd pfd = {};
	pfd.fd = server_fd;
	pfd.events = POLLIN;
	poll_fds.push_back(pfd);


	while (true)
	{
		int state  = poll(&(poll_fds[0]), poll_fds.size(), 1000);
		if (state == -1)
		{
			std::cerr << "Error poll" << std::endl;
			continue;
		}

		if (poll_fds[0].revents == POLLIN)
		{
			sockaddr_in address = {};
			socklen_t csin_len = sizeof(address);
			int fd = accept(server_fd, (struct sockaddr *)&address, &csin_len);
			if (fd == -1)
			{
				std::cerr << "client fd creation error" << std::endl;
				continue;
			}
			std::cout << "New connection: " << fd << std::endl;
			pollfd client_pfd = {};
			client_pfd.fd = fd;
			client_pfd.events = POLLIN;
			poll_fds.push_back(client_pfd);

			std::string buffer = "Hello " + std::to_string(fd) + "!\r\n";
			if (send(fd, buffer.c_str(), buffer.length(), 0) == -1)
			{
				std::cerr  << "[" << fd << "]: " << "send error"
				<< std::endl;
				continue;
			}
		}
		else
		{
			for (std::vector<pollfd>::iterator it = poll_fds.begin(); it != poll_fds.end(); ++it)
			{
				if ((*it).fd == server_fd)
					continue;
				if ((*it).revents == (POLLIN | POLLHUP))
				{
					std::cout << "Client close connection " << (*it).fd <<
					std::endl;
					close((*it).fd);
					continue;
				}
				if ((*it).revents == POLLIN)
				{
					char buffer[BUFFER_SIZE + 1];
					memset(buffer, 0, BUFFER_SIZE);
					ssize_t size = recv((*it).fd, &buffer, BUFFER_SIZE, 0);
					if (size == -1)
						continue;
					if (size == 0)
					{
						std::cout << "Need delete connection " << (*it).fd <<
						std::endl;
						close((*it).fd);
						continue;
					}
					buffer[size] = 0;
					std::cout << "[" << (*it).fd << "]: " << buffer << std::endl;
				}
			}
		}
	}

	// Close the socket
	close(server_fd);

	return 0;
}