#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: arguments" << std::endl;
		return (1);
	}

	Converter converter(argv[1]);

	converter.PrintChar();

	converter.PrintInt();

	converter.PrintFloat();

	converter.PrintDouble();

	return (0);
}
