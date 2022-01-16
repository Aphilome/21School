#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits>

typedef unsigned int t_uint;
typedef unsigned long t_ulong;

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	t_uint _hitPoints;
	t_uint _attackDamage;
	t_uint _energyPoints;

	ClapTrap();
};

#endif
