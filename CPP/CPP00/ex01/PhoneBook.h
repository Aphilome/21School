#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	void Add(Contact *c);
	void PrintAll();
	void PrintOne(int index);
private:
	static const int _maxCount = 8;
	int 			_index;
	Contact			_book[_maxCount];
	static void 	PrintBorderedString(const std::string& str);
};

#endif
