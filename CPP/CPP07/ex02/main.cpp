#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;//

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" << std::endl;

	Array<int> arr1(8);

	for (int i = 0; i < 8; ++i)
		arr1[i] = i * i;

	std::cout	<< "size = "
				<< arr1.size()
				<< std::endl;

	std::cout	<< "arr[3] = "
				<< arr1[3]
				<< std::endl;

	Array<int> arr2(8);
	arr2 = arr1;

	std::cout	<< "size1 = "
				<< arr1.size()
				<< std::endl;

	std::cout	<< "size2 = "
				<< arr2.size()
				<< std::endl;

	arr1[3] = 111;
	std::cout	<< "arr1[2] = "
				<< arr1[3]
				<< std::endl;

	std::cout	<< "arr2[3] = "
				<< arr2[3]
				<< std::endl;

	return (0);
}
