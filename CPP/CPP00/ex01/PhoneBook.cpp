#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	_index = 0;
}

void PhoneBook::Add(Contact *contactData)
{
	_book[_index].IsEmpty = false;
	_book[_index].FirstName = contactData->FirstName;
	_book[_index].LastName = contactData->LastName;
	_book[_index].NickName = contactData->NickName;
	_book[_index].PhoneNumber = contactData->PhoneNumber;
	_book[_index].DarkestSecret = contactData->DarkestSecret;
	_index++;
	if (_index == _maxCount)
		_index = 0;
}

void PhoneBook::PrintAll()
{
	std::cout << '|' << std::setw(10) << std::right << "index";
	std::cout << '|' << std::setw(10) << std::right << "FirstName";
	std::cout << '|' << std::setw(10) << std::right << "LastName";
	std::cout << '|' << std::setw(10) << std::right << "NickName";
	std::cout << '|' << std::endl;
	for (int i = 0; i < _maxCount; ++i)
	{
		if (_book[i].IsEmpty)
			continue;
		std::cout << '|' << std::setw(10) << std::right << i;
		PrintBorderedString(_book[i].FirstName);
		PrintBorderedString(_book[i].LastName);
		PrintBorderedString(_book[i].NickName);
		std::cout << '|' << std::endl;
	}
}

void PhoneBook::PrintBorderedString(const std::string& str)
{
	if (str.length() > 10)
		std::cout << '|' << std::setw(10) << std::right
		<< str.substr(0, 9) + ".";
	else
		std::cout << '|' << std::setw(10) << std::right << str;
}

void PhoneBook::PrintOne(int index)
{
	if (index < 0 || index >= _maxCount || _book[index].IsEmpty)
	{
		std::cout << "Error: index input" << std::endl;
		return;
	}
	std::cout << _book[index].FirstName << std::endl;
	std::cout << _book[index].LastName << std::endl;
	std::cout << _book[index].NickName << std::endl;
	std::cout << _book[index].PhoneNumber << std::endl;
	std::cout << _book[index].DarkestSecret << std::endl;
}

