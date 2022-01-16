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

Fixed::Fixed(const int value)
{
	std::cout	<< "Int constructor called"
				<< std::endl;
	_fixedPointVal = value << _fractionalBitsNum;
}

Fixed::Fixed(const float value)
{
	std::cout	<< "Float constructor called"
				<< std::endl;
	float pow = 1 << _fractionalBitsNum;
	_fixedPointVal = roundf(value * pow);
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
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout	<< "getRawBits member function called"
				 << std::endl;
	return (_fixedPointVal);
}

void Fixed::setRawBits(const int raw)
{
	std::cout	<< "setRawBits member function called"
				 << std::endl;
	_fixedPointVal = raw;
}

float Fixed::toFloat(void) const
{
	float pow = 1 << _fractionalBitsNum;
	return (_fixedPointVal / pow);
}

int Fixed::toInt(void) const
{
	return _fixedPointVal >> _fractionalBitsNum;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
