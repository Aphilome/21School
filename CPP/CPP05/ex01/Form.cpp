#include "Form.hpp"

Form::Form() : _signGrade(1), _executeGrade(1)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name),
_signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_executeGrade < Bureaucrat::highestPossibleGrade
			|| _signGrade < Bureaucrat::highestPossibleGrade)
		throw Form::GradeTooHighException();
	if (_executeGrade > Bureaucrat::lowestPossibleGrade
			|| _signGrade > Bureaucrat::lowestPossibleGrade)
		throw Form::GradeTooLowException();
	_isSigned = false;
}

Form::Form(const Form &src) : _name(src.GetName()), _signGrade(src.GetSignGrade()),
_executeGrade(src.GetExecuteGrade())
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_isSigned = src.GetIsSigned();
		*(const_cast<std::string *>(&_name)) = src.GetName();
		*(const_cast<int *>(&_signGrade)) = src.GetSignGrade();
		*(const_cast<int *>(&_executeGrade)) = src.GetExecuteGrade();
	}
	return *this;
}

std::string Form::GetName() const
{
	return (_name);
}

bool Form::GetIsSigned() const
{
	return (_isSigned);
}

int Form::GetSignGrade() const
{
	return (_signGrade);
}

int Form::GetExecuteGrade() const
{
	return (_executeGrade);
}

void Form::BeSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() >= _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << "Form name: " << src.GetName() << ". Form sign grade : " << src
	.GetSignGrade() << ". Form execute grade: " << src.GetExecuteGrade() <<
	". Is signed form status:" << src.GetIsSigned() << std::endl;
	return (out);
}
