#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &src);

	Brain *getBrain();
	Dog &operator=(const Dog &src);
	virtual void makeSound() const;

	virtual ~Dog();

private:
	Brain *_brain;
};

#endif
