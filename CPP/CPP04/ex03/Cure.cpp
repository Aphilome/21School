#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout	<< "Cure default constructor"
				<< std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout	<< "* heals "
				<< target.getName()
				<< "'s wounds"
				<< " *"
			  	<< std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout	<< "Cure copy constructor"
				<< std::endl;

	*this = src;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout	<< "Cure destructor"
				<< std::endl;
}

