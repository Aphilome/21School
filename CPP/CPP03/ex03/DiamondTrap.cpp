#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout	<< "＿ DiamondTrap default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	std::cout	<< "＿ DiamondTrap ♡"
				 << _name
				 << "♡ constructor with name parameter ✧╮( ˘ ､ ˘ )╭✧ say \"Hiii\"."
				 << std::endl;

	ClapTrap::_name = name + "＿ ClapTrap";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout	<< "＿ DiamondTrap ♡"
				 << _name
				 << "♡ copy constructor"
				 << std::endl;

	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout	<< "＿ DiamondTrap ♡"
				 << _name
				 << "♡ overload operator"
				 << std::endl;

	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_attackDamage = src._attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target) const
{
	std::cout	<< "＿ DiamondTrap ♡"
				 << _name
				 << "♡ attacked "
				 << target
				 << ", inflicted damage: -"
				 << _attackDamage
				 << "."
				 << std::endl;
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout	<< "＿ Diamond name: ♡"
				<< _name
				<< "♡"
				<< std::endl;

	std::cout	<< "＿ ClapTrap name: ♡"
				<< ClapTrap::_name
				<< "♡"
				<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "＿ DiamondTrap ♡"
				 << _name
				 << "♡ destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."	<<
				 std::endl;
}
