#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal &src);

	AAnimal &operator=(const AAnimal &src);

	std::string getType() const;
	virtual Brain *getBrain() = 0;
	virtual void makeSound() const = 0;

	virtual ~AAnimal();

protected:
	std::string _type;
};

#endif
