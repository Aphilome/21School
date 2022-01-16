#include <iostream>
#include <iomanip>
#include "iter.hpp"

void arrPrint(int &i)
{
	std::cout << "♡" << std::setw(2) << i << "♡ " << std::endl;
}

void increment(int &i)
{
	i++;
}

int main()
{
	int array[5] = { 1, 2, 3, 4, 5 };

	iter((int *)array, 5, &arrPrint);

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" << std::endl;

	iter((int *)array, 5, &increment);
	iter((int *)array, 5, &arrPrint);

	std::cout << std::endl;

	return (0);
}
