#include "Converter.hpp"

Converter::Converter()
{
}

Converter::Converter(char *src)
{
	_srcString = src;
	_myDouble = strtold(src, NULL);
}

Converter::Converter(const Converter &src)
{
	*this = src;
}

Converter &Converter::operator=(const Converter &src)
{
	if (this != &src)
	{
		_srcString = src._srcString;
		_myDouble = src._myDouble;
	}
	return (*this);
}

void Converter::PrintChar()
{
	std::cout << "char: ";
	if (isprint(_myDouble))
	{
		char ch = static_cast<char>(_myDouble);

		std::cout	<< "'"
					<< ch
					<<"'";
	}
	else if (_myDouble > 127 || _myDouble < 0 || isnan(_myDouble))
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
}

void Converter::PrintInt()
{
	std::cout << "int: ";

	if (_myDouble <= INT32_MAX && _myDouble >= INT32_MIN && !(isnan(_myDouble)))
	{
		int val = static_cast<int>(_myDouble);

		std::cout	<< val
					<< std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

bool Converter::isFractionalPart()
{
	if (_srcString.find('.') == std::string::npos)
	{
		return (false);
	}
	for(size_t i = _srcString.find('.') + 1; i < _srcString.size(); ++i)
	{
		if (_srcString[i] > '0' && _srcString[i] <= '9')
		{
			return (true);
		}
	}
	return (false);
}

void Converter::PrintFloat()
{
	std::cout << "float: ";

	float myFloat = static_cast<float>(_myDouble);
	std::cout << myFloat;
	if (isFractionalPart() || _myDouble == std::numeric_limits<double>::infinity()
		|| isnan(_myDouble) || _myDouble == -std::numeric_limits<double>::infinity())
	{
		std::cout	<< "f" <<std::endl;
	}
	else
	{
		std::cout	<< ".0f"
					<< std::endl;
	}
}

void Converter::PrintDouble()
{
	std::cout << "double: " << _myDouble;

	if (isFractionalPart() || _myDouble == std::numeric_limits<double>::infinity()
	|| isnan(_myDouble) || _myDouble == -std::numeric_limits<double>::infinity())
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << ".0" << std::endl;
	}
}

Converter::~Converter()
{
}
