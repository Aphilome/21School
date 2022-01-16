#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	virtual void Execute(Bureaucrat const &executor) const;

private:
	std::string _target;

	ShrubberyCreationForm();
};

#endif
