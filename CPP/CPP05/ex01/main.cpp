#include "Bureaucrat.hpp"

int main()
{
	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡PII♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	try
	{
		Form f("test", 0, 5);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form f("ipoteka", 4, 5);
		Bureaucrat b("Bill", 6);
		b.SignForm(f);
		std::cout << f << std::endl;
		b.IncrementGrade();
		b.IncrementGrade();
		b.IncrementGrade();
		b.SignForm(f);
		std::cout << f << std::endl;
		b.IncrementGrade();
		b.IncrementGrade();
		b.IncrementGrade();
		b.IncrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡END_PII♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;

	return (0);
}
