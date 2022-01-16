#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	virtual void Execute(Bureaucrat const &executor) const;

private:
	std::string _target;

	RobotomyRequestForm();
};

#endif
