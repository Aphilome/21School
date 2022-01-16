#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout	<< "Default constructor called"
				 << std::endl;
	_fixedPointVal = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout	<< "Assignation operator called"
				<< std::endl;
	if (this == &fixed)
		return *this;
	_fixedPointVal = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return _fixedPointVal;
}

void Fixed::setRawBits(const int raw)
{
	std::cout	<< "setRawBits member function called"
				<< std::endl;
	_fixedPointVal = raw;
}
