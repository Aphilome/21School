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
