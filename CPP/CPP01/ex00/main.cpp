#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie *zombieFirst = newZombie("Tbirdper");
	randomChump("Aphilome");
	zombieFirst->announce();
	delete zombieFirst;
	return (0);
}
