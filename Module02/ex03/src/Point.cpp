#include "Point.hpp"

Point::Point():x(0),y(0)
{}
Point::Point(const float num1, const float num2) : x(num1),y(num2)
{}
Point::Point(const Point& other):x(other.x),y(other.y)
{}

Point& Point::operator= (const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point()
{}

float Point::getX(void) const
{
    return x.toFloat();
}

float Point::getY(void) const
{
    return y.toFloat();
}