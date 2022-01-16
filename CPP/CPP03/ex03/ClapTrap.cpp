#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout	<< "＿ ClapTrap default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{

	std::cout	<< "＿ ClapTrap ♡"
				 << name
				 << "♡ constructor with name parameter ✧╮( ˘ ､ ˘ )╭✧ say \"Hiii\"."
				 << std::endl;

	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout	<< "＿ ClapTrap ♡"
				 << _name
				 << "♡ copy constructor"
				 << std::endl;

	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout	<< "＿ ClapTrap ♡"
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

void ClapTrap::attack(const std::string &target)
{
	std::cout	<< "＿ ClapTrap ♡"
				 << _name
				 << "♡ attacked "
				 << target
				 << ", inflicted damage: -"
				 << _attackDamage
				 << "."
				 << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout	<< "＿ ClapTrap ♡"
					 << _name
					 << "♡ already out (!) Are you ok, teddy bear?"
					 << std::endl;
		return;
	}
	std::cout	<< "＿ ClapTrap ♡"
				 << _name
				 << "♡ take damage: -"
				 << amount;

	if (amount > _hitPoints)
	{
		_hitPoints = 0;
		std::cout	<< ". He is out (!)"
					 << std::endl;
		return;
	}
	_hitPoints -= amount;
	std::cout	<< ". Hit points left: "
				 << _hitPoints
				 << "."
				 << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
	{
		std::cout	<< "＿ ClapTrap ♡"
					 << _name
					 << "♡ could not cause damage (!) Are you ok, teddy bear?"
					 << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		_hitPoints += amount;

		std::cout	<< "＿ ClapTrap ♡"
					 << _name
					 << "♡ restored +"
					 << amount
					 << " HP ☺."
					 << std::endl;
		return;
	}
	t_ulong hP = _hitPoints;
	hP += amount;
	std::cout	<< "＿ ClapTrap ♡"
				 << _name
				 << "♡ restored +"
				 << amount
				 << " HP ☺.";

	if (hP > UINT32_MAX)
	{
		_hitPoints = UINT32_MAX;
		std::cout << "What? HP is already full.";
	}
	else
		_hitPoints = hP;

	std::cout	<< " total now: "
				 << _hitPoints
				 << " HP ☺☺."
				 << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "＿ ClapTrap ♡"
				 << _name
				 << "♡ destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."	<<
				 std::endl;
}
