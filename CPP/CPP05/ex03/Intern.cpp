#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string target)
const
{
	t_form	array[] =
			{
					{ "presidential pardon", &Intern::makePresidentialPardon },
					{ "robotomy request", &Intern::makeRobotomyRequest },
					{ "shrubbery creation", &Intern::makeShrubberyCreation },
					{ "", nullptr }
			};

	for(int i = 0; array[i].func != nullptr; i++)
		if (array[i].name == formName)
		{
			AForm *(Intern::*f)(std::string) const = array[i].func;
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*f)(target);
		}
	std::cout << "Not find the form " << formName << std::endl;

	return nullptr;
}

AForm *Intern::makePresidentialPardon(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreation(std::string target) const
{
	return new ShrubberyCreationForm(target);
}
