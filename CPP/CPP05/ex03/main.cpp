#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm *form = nullptr;

	try
	{
		Bureaucrat b("Tbirdper bug", 2);

		form =intern.makeForm("presidential pardon", "NotSignedPaper");
		if (form != nullptr)
			form->Execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		if (form != nullptr)
			delete form;
		form = nullptr;
	}
	if (form != nullptr)
		delete form;
	form = nullptr;

	try
	{
		Bureaucrat b("X", 2);

		form =intern.makeForm("presidential pardon", "SignedPaper");
		if (form != nullptr)
		{
			form->BeSigned(b);
			form->Execute(b);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		if (form != nullptr)
			delete form;
		form = nullptr;
	}
	if (form != nullptr)
		delete form;
	form = nullptr;

	try
	{
		Bureaucrat b("x", 70);
		Bureaucrat b1("y", 2);
		form =intern.makeForm("robotomy request", "SignedPaper");
		if (form != nullptr)
		{
			form->BeSigned(b);
			form->Execute(b1);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		if (form != nullptr)
			delete form;
		form = nullptr;
	}
	if (form != nullptr)
		delete form;
	form = nullptr;

	try
	{
		Bureaucrat b("x", 70);
		Bureaucrat b1("y", 2);

		form =intern.makeForm("shrubbery creation", "SignedPaper");
		if (form != nullptr)
		{
			form->BeSigned(b1);
			form->BeSigned(b);
			form->Execute(b1);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		if (form != nullptr)
			delete form;
		form = nullptr;
	}
	if (form != nullptr)
		delete form;

	form =intern.makeForm("test", "SignedPaper");
	if (form != nullptr)
		delete form;

	return 0;
}
