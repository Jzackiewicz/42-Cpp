#include "Point.hpp"
#include <cstdlib>

//  Checking if the area formed by the triangle is not zero.
bool    checkTriangle(Point const &a, Point const &b, Point const &c)
{
    Fixed area;

    area = Fixed(0.5f) * ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX()));
    if (area == 0)
        return (false);
    else
        return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point abNormalVector(a)
}