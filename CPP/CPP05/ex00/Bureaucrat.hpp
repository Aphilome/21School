#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);

	Bureaucrat	&operator=(const Bureaucrat &src);

	std::string	GetName() const;
	int			GetGrade() const;

	void IncrementGrade();
	void DecrementGrade();

	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade too high exception";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade too low exception";
		}
	};

private:

	const std::string	_name;
	int 				_grade;

	static const int	highestPossibleGrade = 1;
	static const int	lowestPossibleGrade = 150;

	Bureaucrat();
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src);

#endif
