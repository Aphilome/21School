#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	setName(name);
}

void Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " destructor come" << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
