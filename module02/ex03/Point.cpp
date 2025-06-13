#pragma once

#include "Point.hpp"

Point::Point(void)
{
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const float x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point	&Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._y;
	}
	return (*this);
}

Point::~Point(void)
{
	;
}