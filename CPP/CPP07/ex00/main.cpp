#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ " << std::endl;
	char	c1 = 'A';
	char	c2 = 'T';
	int		i1 = 21;
	int 	i2 = 1;

	// int
	std::cout	<< "a = "
				 << i1
				 << ", b = "
				 << i2 << std::endl;

	std::cout	<< "min(" << i1 << ", " << i2 << ") = "
				 << min(i1, i2)
				 << std::endl;

	std::cout	<< "max(" << i1 << ", " << i2 << ") = "
				 << max(i1, i2)
				 << std::endl;

	std::cout	<< "swap(" << i1 << ", " << i2 << ")"
				 << std::endl;

	swap(i1, i2);
	std::cout	<< "a = "
				 << i1
				 << ", b = "
				 << i2
				 << std::endl;

	std::cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ " << std::endl;

	// char
	std::cout	<< "a = "
				 << c1
				 << ", b = "
				 << c2
				 << std::endl;

	std::cout	<< "min(" << c1 << ", " << c2 << ") = "
				 << min(c1, c2)
				 << std::endl;

	std::cout	<< "max(" << c1 << ", " << c2 << ") = "
				 << max(c1, c2)
				 << std::endl;

	std::cout	<< "swap(" << c1 << ", " << c2 << ")"
				 << std::endl;

	swap(c1, c2);
	std::cout	<< "a = "
				 << c1 << ", b = "
				 << c2 << std::endl;

	return (0);
}
