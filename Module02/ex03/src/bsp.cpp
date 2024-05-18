#include "Point.hpp"

Fixed module(Fixed num)
{
	if (num < 0)
		return(num * -1);
	return(num);
}

Fixed area(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{	
	Fixed ABC = module(area(a, b, c));
	Fixed PAB = module(area(point, a, b));
	Fixed PBC = module(area(point, b, c));
	Fixed PCA = module(area(point, c, a));
	
	return(ABC == (PAB + PBC + PCA));
}