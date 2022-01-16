#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);

	Ice &operator=(const Ice &src);

	void		use(ICharacter &target);
	AMateria*	clone() const;

	~Ice();
};

#endif
