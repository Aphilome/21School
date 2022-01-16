#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string &type)
{
	_type = type;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout	<< "Can't use"
				<< std::endl;
}

AMateria::~AMateria()
{
}
