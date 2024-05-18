#pragma once

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float num, const float num2);
		Point(const Point& other);
		~Point();
	public:
		Point& operator =(const Point& other);
		float getX() const;
		float getY() const;
	private:
		const Fixed x;
		const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
