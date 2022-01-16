#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &src);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	AMateria *_learning[4];
};

#endif
