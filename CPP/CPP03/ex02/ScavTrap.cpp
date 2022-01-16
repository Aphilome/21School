#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
	std::cout	<< "＿ ScavTrap default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout	<< "＿ ScavTrap ♡"
				 << _name
				 << "♡ constructor with name parameter ✧╮( ˘ ､ ˘ )╭✧ say \"Hiii\"."
				 << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout	<< "＿ ScavTrap ♡"
				 << _name
				 << "♡ copy constructor"
				 << std::endl;

	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout	<< "＿ ScavTrap ♡"
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

void ScavTrap::guardGate()
{
	std::cout	<< "＿ ScavTrap ♡"
				 << _name
				 << "♡ entered seven gates perfect keeper mode"
				 << std::endl;
}

void ScavTrap::attack(const std::string &target) const
{
	std::cout	<< "＿ ScavTrap ♡"
				 << _name
				 << "♡ attacked "
				 << target
				 << ", inflicted damage: -"
				 << _attackDamage
				 << "."
				 << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "＿ ScavTrap ♡"
				 << _name
				 << "♡ destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."	<<
				 std::endl;
}
