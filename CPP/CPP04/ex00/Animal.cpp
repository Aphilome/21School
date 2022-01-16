#include "Animal.hpp"

Animal::Animal()
{
	std::cout	<< "＿ Animal default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				<< std::endl;
	_type = "Animal";
}

Animal::Animal(const Animal &src)
{
	std::cout	<< "＿ Animal copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				<< std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout	<< "✧ unknown sound ✧"
				<< std::endl;
}

Animal::~Animal()
{
	std::cout	<< "＿ Animal destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
}
