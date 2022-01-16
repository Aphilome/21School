#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &src);

	Brain *getBrain();
	Cat &operator=(const Cat &src);
	virtual void makeSound() const;

	virtual ~Cat();

private:
	Brain *_brain;
};

#endif
