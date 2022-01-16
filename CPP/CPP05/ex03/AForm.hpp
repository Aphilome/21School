#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);

	std::string		GetName() const;
	bool			GetIsSigned() const;
	int				GetSignGrade() const;
	int				GetExecuteGrade() const;
	void			BeSigned(const Bureaucrat &bureaucrat);
	virtual void	Execute(Bureaucrat const &executor) const = 0;

	virtual ~AForm();

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

protected:
	void canExecuteWithException(const Bureaucrat &bureaucrat) const;

private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

	AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif
