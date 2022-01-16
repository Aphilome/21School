#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	virtual void Execute(Bureaucrat const &executor) const;

	~PresidentialPardonForm();

private:
	std::string _target;

	PresidentialPardonForm();
};

#endif
