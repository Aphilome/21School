#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PresidentialPardon", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return *this;
	_target = src._target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("", 1, 1)
{
}

void PresidentialPardonForm::Execute(const Bureaucrat &executor) const
{
	canExecuteWithException(executor);

	std::cout << _target << " has been pardoned by Zafod Beeblebrox."
			  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}