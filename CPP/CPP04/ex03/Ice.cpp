#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *"
				<< std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout	<< "Ice copy constructor"
				<< std::endl;
	*this = src;
}

Ice::~Ice()
{
	std::cout	<< "Ice destructor"
				<< std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this == &src)
		return *this;
	_type = src._type;
	return *this;
}
