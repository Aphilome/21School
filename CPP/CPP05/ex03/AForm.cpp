#include "AForm.hpp"

AForm::AForm() : _signGrade(1), _executeGrade(1)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name),
																  _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_executeGrade < Bureaucrat::highestPossibleGrade
		|| _signGrade < Bureaucrat::highestPossibleGrade)
		throw AForm::GradeTooHighException();
	if (_executeGrade > Bureaucrat::lowestPossibleGrade
		|| _signGrade > Bureaucrat::lowestPossibleGrade)
		throw AForm::GradeTooLowException();
	_isSigned = false;
}

AForm::AForm(const AForm &src) : _name(src.GetName()), _signGrade(src.GetSignGrade()),
								 _executeGrade(src.GetExecuteGrade())
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
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

std::string AForm::GetName() const
{
	return (_name);
}

bool AForm::GetIsSigned() const
{
	return (_isSigned);
}

int AForm::GetSignGrade() const
{
	return (_signGrade);
}

int AForm::GetExecuteGrade() const
{
	return (_executeGrade);
}

void AForm::BeSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() >= _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::canExecuteWithException(const Bureaucrat &bureaucrat) const
{
	if (!_isSigned || bureaucrat.GetGrade() >= _executeGrade)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << "AForm name: " << src.GetName() << ". AForm sign grade : " << src
			.GetSignGrade() << ". AForm execute grade: " << src.GetExecuteGrade() <<
		". Is signed form status:" << src.GetIsSigned() << std::endl;
	return (out);
}
