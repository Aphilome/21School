#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("PresidentialPardon", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return *this;
	_target = src._target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("", 1, 1)
{
}

void ShrubberyCreationForm::Execute(const Bureaucrat &executor) const
{
	canExecuteWithException(executor);

	std::ofstream file(_target + "_shrubbery");
	//file.open(, std::ios::out);
	if (file.is_open())
	{
		file << "      ." << std::endl;
		file << "   __/ \\__" << std::endl;
		file << "   \\     /" << std::endl;
		file << "   /.'o'.\\" << std::endl;
		file << "    .o.'." << std::endl;
		file << "   .'.'o'." << std::endl;
		file << "  o'.o.'.o." << std::endl;
		file << " .'.o.'.'.o." << std::endl;
		file << ".o.'.o.'.o.'." << std::endl;
		file << "   [_____]" << std::endl;
		file << "    \\___/" << std::endl;
		file << std::endl;
		file << std::endl;
		file << "      ." << std::endl;
		file << "   __/ \\__" << std::endl;
		file << "   \\     /" << std::endl;
		file << "   /.'o'.\\" << std::endl;
		file << "    .o.'." << std::endl;
		file << "   .'.'o'." << std::endl;
		file << "  o'.o.'.o." << std::endl;
		file << " .'.o.'.'.o." << std::endl;
		file << ".o.'.o.'.o.'." << std::endl;
		file << "   [_____]" << std::endl;
		file << "    \\___/" << std::endl;

		file.close();
		std::cout << "Success creating file" << std::endl;
	}
	else
		std::cout << "Error creating file" << std::endl;
}
