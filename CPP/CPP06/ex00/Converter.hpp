#pragma once
#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

class Converter
{
public:
	Converter(char *src);
	Converter(const Converter &src);

	Converter &operator=(const Converter &src);

	void 	PrintChar();
	void 	PrintInt();
	void 	PrintFloat();
	void 	PrintDouble();

	~Converter();
	
private:
	Converter();
	bool isFractionalPart();

	std::string	_srcString;
	double		_myDouble;
};

#endif
