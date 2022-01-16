#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);

	Cure &operator=(const Cure &src);

	void		use(ICharacter &target);
	AMateria*	clone() const;

	~Cure();
};

#endif
