#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout	<< "＿ WrongAnimal default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout	<< "＿ WrongAnimal copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout	<< "✧ wrong animal sound ✧"
				 << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "＿ WrongAnimal destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
}
