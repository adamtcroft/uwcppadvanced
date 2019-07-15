#include "stdafx.h"
#include "Point.h"


Point::Point()
{
}

Point::~Point()
{
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int value)
{
	x = value;
}

void Point::setY(int value)
{
	y = value;
}