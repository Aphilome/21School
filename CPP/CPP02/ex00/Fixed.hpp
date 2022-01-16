#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
public:
	Fixed();
	~Fixed( );
	Fixed(const Fixed &fixed);

	Fixed &operator=(const Fixed &fixed);

	int getRawBits( ) const;
	void setRawBits( const int raw );


private:
	int _fixedPointVal;
	static const int _fractionalBitsNum = 8;
};

#endif
