#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> container;
	container.reserve(10);
	for (int i = 0; i < 10; i++)
		container.push_back(i);

	std::vector<int>::iterator iterator;
	iterator = easyfind(container, 30);
	if (iterator == container.end())
		std::cout	<< "missing"
					<< std::endl;
	else
		std::cout	<< "is present: "
					<< *iterator
					<< std::endl;

	iterator = easyfind(container, 7);
	if (iterator == container.end())
		std::cout	<< "missing"
					<< std::endl;
	else
		std::cout	<< "is present: "
					<< *iterator
					<< std::endl;

	return (0);
}
