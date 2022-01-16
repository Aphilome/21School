#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout	<< "＿ FragTrap default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;

	_hitPoints = 100;
	_energyPoints = 300;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout	<< "＿ FragTrap ♡"
				 << _name
				 << "♡ constructor with name parameter ✧╮( ˘ ､ ˘ )╭✧ say \"Hiii\"."
				 << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout	<< "＿ FragTrap ♡"
				 << _name
				 << "♡ copy constructor"
				 << std::endl;

	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout	<< "＿ FragTrap ♡"
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

void FragTrap::highFivesGuys()
{
	std::cout	<< "＿ FragTrap ♡"
				 << _name
				 << "♡ ¯\\_(ツ)_/¯ high fives"
				 << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout	<< "＿ FragTrap ♡"
				 << _name
				 << "♡ destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."	<<
				 std::endl;
}
