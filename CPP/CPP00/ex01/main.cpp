#include <iostream>
#include "PhoneBook.h"

void read_contact(Contact *contact)
{
	std::cout << "FirstName> ";
	getline(std::cin, contact->FirstName, '\n');
	if (std::cin.eof())
		exit(1);
	std::cout << "LastName> ";
	getline(std::cin, contact->LastName, '\n');
	if (std::cin.eof())
		exit(1);
	std::cout << "Nickname> ";
	getline(std::cin, contact->NickName, '\n');
	if (std::cin.eof())
		exit(1);
	std::cout << "PhoneNumber> ";
	getline(std::cin, contact->PhoneNumber, '\n');
	if (std::cin.eof())
		exit(1);
	std::cout << "DarkestSecret> ";
	getline(std::cin, contact->DarkestSecret, '\n');
	if (std::cin.eof())
		exit(1);
}

int read_index()
{
	std::string	str;
	std::cout << "index> ";
	getline(std::cin, str, '\n');
	if (std::cin.eof())
		exit(1);
	const char *start = str.c_str();
	char *end;
	long num = strtol(start, &end, 10);
	if (end == start || *end != '\0' || errno == ERANGE)
		return -1;
	if (num > INT32_MAX || num < INT32_MIN)
		return -1;
	return (int)num;
}

int main()
{
	Contact		contact;
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true)
	{
		std::cout << "> ";
		getline(std::cin, cmd, '\n');
		if (std::cin.eof())
			exit(1);
		if (cmd == "EXIT")
			return 0;
		else if (cmd == "ADD")
		{
			read_contact(&contact);
			phoneBook.Add(&contact);
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.PrintAll();
			phoneBook.PrintOne(read_index());
		}
	}
}
