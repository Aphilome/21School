#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " destructor come" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
