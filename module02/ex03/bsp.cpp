#include "Point.hpp"
#include <cstdlib>

//  Checking if the area formed by the triangle is not zero.
bool    checkTriangle(Point const &a, Point const &b, Point const &c)
{
    Fixed area;

    area = Fixed(0.5f) * ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
						  (b.getY() - a.getY()) * (c.getX() - a.getX()));
    if (area == 0)
        return (false);
    else
        return (true);
}

//		Using Point class to define a vector variable
Point	getVector(Point const a, Point const b)
{
	Fixed	vec_x;
	Fixed	vec_y;

	vec_x = b.getX() - a.getX();
	vec_y = b.getY() - a.getY();

	return (Point(vec_x.toFloat(), vec_y.toFloat()));
}

//		Calculating cross-product between two 2D vectors (PA and PB) (pseudoscalar) to determine
//		the rotation direction from PA to PB
Fixed	cross(Point const point, Point const a, Point const b)
{
	Point	vec_PA;
	Point	vec_PB;
	Fixed	cross_prod;

	vec_PA = getVector(point, a);
	vec_PB = getVector(point, b);
	cross_prod = vec_PA.getX() * vec_PB.getY() - vec_PB.getX() * vec_PA.getY();
	return (cross_prod);

}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	float	point2AB;
	float	point2BC;
	float	point2CA;

	point2AB = cross(point, a, b).toFloat();
	point2BC = cross(point, b, c).toFloat();
	point2CA = cross(point, c, a).toFloat();
	if (point2AB <= 0 && point2BC <= 0 && point2CA <= 0)
		return (true);
	if (point2AB >= 0 && point2BC >= 0 && point2CA >= 0)
		return (true);
	return (false);
}
