#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point &src);
	Point(const float &_x, const float &_y);
	~Point();

	Point &operator=(Point const &src);

	Fixed getX() const;
	Fixed getY() const;
private:
	const Fixed x;
	const Fixed y;
};

std::ostream &operator<<(std::ostream &out, Point const &point);

#endif
