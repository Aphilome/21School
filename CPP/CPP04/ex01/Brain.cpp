#include "Brain.hpp"

Brain::Brain()
{
	std::cout	<< "＿ Brain default constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout	<< "＿ Brain copy constructor ✧╮(￣_￣)╭✧ say \"Hiii\"."
				 << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout	<< "＿ Brain destructor ‿︵‿✧╮(￣_￣)╭✧︵‿︵ say \"Ciao\"."
				 << std::endl;
}
