#include "stdafx.h"
#include "Point.h"

Point::Point()
{
}

Point::Point(int x, int y)
	:_x(x), _y(y)
{

}

Point::~Point()
{
}

int Point::getX() const
{
	return _x;
}

int Point::getY() const
{
	return _y;
}

void Point::setX(int value)
{
	_x = value;
}

void Point::setY(int value)
{
	_y = value;
}

bool operator==(const Point& lhs, const Point& rhs)
{
	return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool operator!=(const Point& lhs, const Point& rhs)
{
	return lhs.getX() != rhs.getX() && lhs.getY() != rhs.getY();
}

std::ostream& operator<<(std::ostream& output, Point& p)
{
	output << p.getX() << ", " << p.getY();
	output.flush();

	return output;
}