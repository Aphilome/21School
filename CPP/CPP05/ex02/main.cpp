#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("Tbirdper bug", 2);

		PresidentialPardonForm pf("NotSignedPaper");

		AForm *f = &pf;
		f->Execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("X", 2);

		PresidentialPardonForm pf("SignedPaper");

		AForm *f = &pf;
		f->BeSigned(b);
		f->Execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("x", 70);
		Bureaucrat b1("y", 2);

		RobotomyRequestForm rf("SignedPaper");

		AForm *f = &rf;
		f->BeSigned(b);
		f->Execute(b1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("x1", 140);
		Bureaucrat b1("y1", 70);

		ShrubberyCreationForm sf("SignedPaper");

		AForm *f = &sf;
		f->BeSigned(b1);
		f->BeSigned(b);
		f->Execute(b1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
