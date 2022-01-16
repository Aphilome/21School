#include <iostream>
#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout	<< "Error: arg"
					<< std::endl;
		return 1;
	}
	levels currentLevel = Karen::enumLevelConverter(argv[1]);
	if (currentLevel == lNone)
	{
		std::cout	<< "[ Probably complaining about"
					 "insignificant problems ]"
					<< std::endl;
		return 1;
	}
	Karen karen(currentLevel);

	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");

	return (0);
}
