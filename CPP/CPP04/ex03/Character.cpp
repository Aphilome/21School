#include "Character.hpp"

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; ++i)
		_inventar[i] = nullptr;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < 4; ++i)
		_inventar[i] = nullptr;
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return *this;
	_name = src._name;
	for (int i = 0; i < 4; ++i)
	{
		if (_inventar[i] != nullptr)
			delete _inventar[i];
		_inventar[i] = src._inventar[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *materia)
{
	if (materia != nullptr)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_inventar[i] == nullptr)
			{
				_inventar[i] = materia;
				return;
			}
		}
		std::cout << "Everything is busy in inventory" << std::endl;
		delete materia;
	}
}

void Character::unequip(int idx)
{
	_inventar[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (_inventar[idx] == nullptr)
	{
		std::cout	<< "Nothing use"
					<< std::endl;
		return;
	}
	_inventar[idx]->use(target);
	delete (_inventar[idx]);
	unequip(idx);
}

Character::Character()
{
	for (int i = 0; i < 4; ++i)
	{
		_inventar[i] = nullptr;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (_inventar[i] != nullptr)
			delete _inventar[i];
}