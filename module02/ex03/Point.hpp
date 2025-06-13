#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& obj);
		Point &operator=(const Point &other);
		~Point();
};