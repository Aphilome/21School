#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(std::string name);
	Character(const Character &src);

	Character &operator=(const Character &src);

	std::string const	&getName() const;
	void 				equip(AMateria* materia);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);

	~Character();

private:
	std::string _name;
	AMateria *_inventar[4];

	Character();
};

#endif
