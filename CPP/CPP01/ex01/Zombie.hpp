#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	void announce( void );
	void setName( std::string name );
	Zombie();
	~Zombie();
private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
