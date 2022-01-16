#include "Cat.hpp"

Cat::Cat()
{
	std::cout	<< "＿ Cat default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &src)
{
	std::cout	<< "＿ Cat copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_brain = new Brain();
	*this = src;
}

Brain *Cat::getBrain()
{
	return (_brain);
}


Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

void Cat::makeSound() const
{
	std::cout	<< "✧ meow ✧"
				 << std::endl;
}

Cat::~Cat()
{
	std::cout	<< "＿ Cat destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
	delete (_brain);
}
