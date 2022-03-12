#ifndef UTILS_H
#define UTILS_H

#define ERROR_ARGC				"Run: ./ircserv <port> <password>"
#define ERROR_PORT_PARSE			"Port must be number"
#define ERROR_PORT_RANGE			"Port must be in range from 0 to 65535"
#define ERROR_NEW_SOCKET			"Creating a socket"
#define ERROR_BIND_PORT			"Cant bind port"
#define ERROR_PORT_LISTENING		"Set socket for listening"
#define ERROR_SERVER_READY		"Server not inited"

#define ERROR_EXIT_CODE		1

#include <string>
#include <iostream>
#include <sstream>

class Utils
{
public:
	static void error_print(const std::string& msg);
	static void error_exit(const std::string& msg);

	static int int_parse(const std::string& s, const std::string& error_msg);
	static bool int_try_parse(const std::string& s, int &value,
							  const std::string& error_msg);

	static unsigned long	to_hash(const std::string& s);

};

#endif
