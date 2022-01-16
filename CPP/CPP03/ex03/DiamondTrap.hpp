#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap( const std::string &name );
	DiamondTrap( const DiamondTrap &src );
	~DiamondTrap();

	DiamondTrap	&operator=( const DiamondTrap &src );

	void attack( const std::string &target ) const ;
	void whoAmI();
private:
	std::string _name;
	DiamondTrap();
};


#endif
