#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::endl;
	std::cout << std::setw(11) << "str: " << &str << std::endl;
	std::cout << std::setw(11) << "stringPTR: " << stringPTR << std::endl;
	std::cout << std::setw(11) << "stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(11) << "stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setw(11) << "stringREF: " << stringREF << std::endl;

	return (0);
}
