#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
public:
	Contact();
	bool IsEmpty;
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;

};

#endif

