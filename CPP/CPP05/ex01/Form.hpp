#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &src);
	Form &operator=(const Form &src);

	std::string	GetName() const;
	bool		GetIsSigned() const;
	int			GetSignGrade() const;
	int			GetExecuteGrade() const;
	void		BeSigned(const Bureaucrat &bureaucrat);

	~Form();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("F: grade too high exception");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("F: grade too low exception");
		}
	};

private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

	Form();
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif
