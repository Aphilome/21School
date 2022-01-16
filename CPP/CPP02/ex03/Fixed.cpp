#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointVal = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	_fixedPointVal = value << _fractionalBitsNum;
}

Fixed::Fixed(const float value)
{
	float pow = 1 << _fractionalBitsNum;
	_fixedPointVal = roundf(value * pow);
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	_fixedPointVal = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return (_fixedPointVal);
}

void Fixed::setRawBits(const int raw)
{
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

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_fixedPointVal > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_fixedPointVal < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (_fixedPointVal >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (_fixedPointVal <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (_fixedPointVal == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (_fixedPointVal != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed res(toFloat() + fixed.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed res(toFloat() - fixed.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed res(toFloat() * fixed.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed res(toFloat() / fixed.toFloat());
	return (res);
}

Fixed &Fixed::operator++()
{
	_fixedPointVal++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_fixedPointVal--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(toFloat());
	_fixedPointVal++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(toFloat());
	_fixedPointVal--;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
