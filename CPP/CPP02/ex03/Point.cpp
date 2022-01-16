#include "Point.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const Point &src): x(src.x), y(src.y)
{
}

Point::Point(const float &_x, const float &_y): x(_x), y(_y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return (*this);
	*(const_cast<Fixed*>(&x)) = src.x;
	*(const_cast<Fixed*>(&y)) = src.y;
	return (*this);
}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}

std::ostream &operator<<(std::ostream &out, Point const &point)
{
	out << '[' << point.getX() << "; " << point.getY() << ']';
	return (out);
}