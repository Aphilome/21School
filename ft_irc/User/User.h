#ifndef USER_H
#define USER_H

/*
RFC 1459
Oikarinen & Reed                                               [Page 14]
   The recommended order for a client to register is as follows:
           1. Pass message
           2. Nick message
           3. User message
*/

#include <string>
#include <vector>

enum user_state
{
	usr_new,
	usr_psw_accept,
	usr_registered,
};

enum user_commands
{
	cmd_none,
	cmd_pass,
	cmd_user,
	cmd_nick
};

class User
{
private:
	std::string _nickname;
	std::string _username;
	user_state _state;
	std::vector<std::string> _new_messages;
public:
	void	apply(user_commands cmd, std::string *args);
	User();
	~User();
};

#endif
