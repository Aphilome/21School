#include "Bureaucrat.hpp"

int main()
{
	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡PI♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	try
	{
		Bureaucrat a("Tion", 125);
		std::cout << a << std::endl;
//		a.IncrementGrade();
//		a.IncrementGrade();
//		a.IncrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Birdperson", 1);
		std::cout << a << std::endl;
//		a.IncrementGrade();
//		a.IncrementGrade();
//		a.IncrementGrade();
//		a.IncrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Tbirdper", 2);
		std::cout << a << std::endl;
//		a.IncrementGrade();
//		a.DecrementGrade();
//		a.DecrementGrade();
//		a.DecrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡END_PI♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	return 0;
}
