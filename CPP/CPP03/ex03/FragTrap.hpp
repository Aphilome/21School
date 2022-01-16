#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	~FragTrap();

	FragTrap &operator=(const FragTrap &src);

	void highFivesGuys();

protected:
	FragTrap();
};

#endif
