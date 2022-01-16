#pragma once
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);

	WrongAnimal &operator=(const WrongAnimal &src);
	std::string getType() const;
	void makeSound() const;

	~WrongAnimal();

protected:
	std::string _type;
};

#endif
