#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a1(4.58, -1.11);
	Point b1(6.55, 4.86);
	Point c1(12.02, 2.66);
	Point p1(7.98, 2.24);
	Point p2(10.77, 1.89);
	Point p3(4.64, 0.55);

	std::cout << "A1: " << a1	<< std::endl;
	std::cout << "B1: " << b1	<< std::endl;
	std::cout << "C1: " << c1	<< std::endl
								<< std::endl;

	std::cout << "P1: " << p1 << ": ";
	if (bsp(a1, b1, c1, p1))
		std::cout	<< "in triangle"
					<< std::endl;
	else
		std::cout	<< "out triangle"
					<< std::endl;

	std::cout << "P2: " << p2 << ": ";
	if (bsp(a1, b1, c1, p2))
		std::cout	<< "in triangle"
					<< std::endl;
	else
		std::cout	<< "out triangle"
					<< std::endl;

	std::cout << "P3: " << p3 << ": ";
	if (bsp(a1, b1, c1, p3))
		std::cout	<< "in triangle"
					<< std::endl;
	else
		std::cout	<< "out triangle"
					<< std::endl;

	return (0);
}
