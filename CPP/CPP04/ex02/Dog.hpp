#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog: public AAnimal
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
