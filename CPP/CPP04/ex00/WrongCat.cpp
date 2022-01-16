#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout	<< "＿ WrongCat default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout	<< "＿ WrongCat copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout	<< "✧ wrong meow ✧"
				 << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout	<< "＿ WrongCat destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
}
