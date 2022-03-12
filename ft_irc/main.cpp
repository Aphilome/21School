#include <iostream>
#include <string>
#include <sstream>
#include "Server/Server.h"

bool str2int(int &i, char const *s)
{
	std::stringstream ss(s);
	ss >> i;
	if (ss.fail()) {
		return false;
	}
	return true;
}

// http://www.cse.yorku.ca/~oz/hash.html djb2
unsigned long get_hash(char *str)
{
	unsigned long hash = 5381;
	int c;
	while (*str)
	{
		c = *str;
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		str++;
	}
	return hash;
}


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Run: ./ircserv <port> <password>" << std::endl;
		return -1;
	}
	int server_port;
	if (!str2int(server_port, argv[1]))
	{
		std::cerr << "Not integer" << std::endl;
		return -1;
	}
	if (server_port < 0 || server_port > 65535)
	{
		std::cerr << "Not range of port" << std::endl;
		return -1;
	}

	unsigned long password_hash = get_hash(argv[2]);

	Server server(server_port, password_hash);
	server.Run();





	return 0;
}