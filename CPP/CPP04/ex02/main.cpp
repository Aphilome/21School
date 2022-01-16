#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡PI♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	std::cout	<< "♡Dog-Cat♡"
				 << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	std::cout	<< "♡Dog-Cat-Mas♡"
				 << std::endl;

	AAnimal *dogCat[100];
	for (int k = 0; k < 50; ++k)
	{
		dogCat[k] = new Dog();
	}
	for (int k = 50; k < 100; ++k)
	{
		dogCat[k] = new Cat();
	}
	for (int k = 0; k < 100; ++k)
	{
		delete dogCat[k];
	}

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	std::cout	<< "Brain copy"
				 << std::endl;

	Dog dog;
	{
		Dog tmpDog = dog;

		dog.getBrain()->ideas[0] = "idea1";
		dog.getBrain()->ideas[1] = "idea2";
		dog.getBrain()->ideas[2] = "idea3";

		for (int k = 0; k < 3; ++k)
		{
			if (!dog.getBrain()->ideas[k].empty())
			{
				std::cout	<< dog.getBrain()->ideas[k]
							 << std::endl;
			}
		}
		std::cout << "♡♡♡♡♡" <<std::endl;

		for (int k = 0; k < 3; ++k)
		{
			if (!tmpDog.getBrain()->ideas[k].empty())
			{
				std::cout	<< tmpDog.getBrain()->ideas[k]
							 << std::endl;
			}
		}
		std::cout << "no idea" << std::endl;
	}

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡END_PI♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

}
