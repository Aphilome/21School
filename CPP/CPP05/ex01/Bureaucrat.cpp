#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	_grade = grade;
	if (_grade < highestPossibleGrade)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > lowestPossibleGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		_grade = src._grade;
		*(const_cast<std::string *>(&_name)) = src.GetName();
	}
	return *this;
}

std::string Bureaucrat::GetName() const
{
	return (_name);
}

int Bureaucrat::GetGrade() const
{
	return (_grade);
}

void Bureaucrat::IncrementGrade()
{
	_grade--;
	if (_grade < highestPossibleGrade)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::DecrementGrade()
{
	_grade++;
	if (_grade > lowestPossibleGrade)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::SignForm(Form &form)
{
	try
	{
		form.BeSigned(*this);
		std::cout	<< _name
					 << " signs "
					 << form.GetName()
					 << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout	<< _name
					<< " cannot signs "
					<< form.GetName()
					<< " because with low grade."
					<< std::endl;
	}

}

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.GetName() << "'s bureaucrat grade: " << src.GetGrade();
	return (o);
}
