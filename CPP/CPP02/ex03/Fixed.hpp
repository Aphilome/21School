#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &fixed);

	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;

	Fixed	operator+(const Fixed &fixed) const;
	Fixed	operator-(const Fixed &fixed) const;
	Fixed	operator*(const Fixed &fixed) const;
	Fixed	operator/(const Fixed &fixed) const;
	// pre increment
	Fixed	&operator++();
	// pre decrement
	Fixed	&operator--();
	// post increment
	Fixed	operator++(int);
	// post decrement
	Fixed	operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits() const;
	void setRawBits( const int raw );
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedPointVal;
	static const int _fractionalBitsNum = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
