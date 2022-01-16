#include "Dog.hpp"

Dog::Dog()
{
	std::cout	<< "＿ Dog default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout	<< "＿ Dog copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

void Dog::makeSound() const
{
	std::cout	<< "✧ gav ✧"
				 << std::endl;
}

Dog::~Dog()
{
	std::cout	<< "＿ Dog destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
}
