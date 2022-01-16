#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
public:
	Animal();
	Animal(const Animal &src);

	Animal &operator=(const Animal &src);

	std::string getType() const;
	virtual Brain *getBrain();
	virtual void makeSound() const;

	virtual ~Animal();

protected:
	std::string _type;
};

#endif
