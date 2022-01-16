#include <iostream>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	int r = rand() % 3;

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void identify(Base *ptr){
	if (dynamic_cast<A *>(ptr))
	{
		std::cout	<< "class A"
					<< std::endl;
	}

	else if(dynamic_cast<B *>(ptr))
	{
		std::cout	<< "class B"
					<< std::endl;
	}

	else
	{
		std::cout	<< "class C"
					<< std::endl;
	}
}

void identify(Base& ptr)
{
	try
	{
		(void)dynamic_cast<A &>(ptr);

		std::cout	<< "class A"
					<< std::endl;
	}

	catch (std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(ptr);
		std::cout	<< "class B"
					<< std::endl;
	}

	catch (std::exception & e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(ptr);
		std::cout	<< "class C"
					<< std::endl;
	}

	catch (std::exception & e)
	{
	}
}

int main()
{
	srand(time(0));

	Base *b = generate();

	identify(b);

	identify(*b);

	delete b;

	return (0);
}
