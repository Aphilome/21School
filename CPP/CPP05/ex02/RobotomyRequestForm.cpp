#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("PresidentialPardon", 72, 45)
{
	std::srand(std::time(nullptr));
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	std::srand(std::time(nullptr));
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;
	_target = src._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("", 1, 1)
{
}

void RobotomyRequestForm::Execute(const Bureaucrat &executor) const
{
	canExecuteWithException(executor);

	if (std::rand() % 2)
		std::cout 	<< _target << " has been successfull y robotomized"
					<< std::endl;
	else
		std::cout 	<< _target << " has been failure" << std::endl;
}
