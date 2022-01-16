#include "Dog.hpp"

Dog::Dog()
{
	std::cout	<< "＿ Dog default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &src)
{
	std::cout	<< "＿ Dog copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_brain = new Brain();
	*this = src;
}

Brain *Dog::getBrain()
{
	return (_brain);
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
	delete (_brain);
}
