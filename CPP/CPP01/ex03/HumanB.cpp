#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_weapon = nullptr;
	_name = name;
}

void HumanB::attack()
{
	if (_weapon == nullptr)
		std::cout	<< _name << " attacks with bare hands "
					<< std::endl;
	else
		std::cout	<< _name << " attacks with his " << _weapon->getType()
					<< std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
