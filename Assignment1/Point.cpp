#include "stdafx.h"
#include "Point.h"

VG::Point::Point()
{
}

VG::Point::Point(int x, int y) 
	:_x(x), _y(y)
{

}

VG::Point::~Point()
{
}

int VG::Point::getX() const 
{
	return _x;
}

int const VG::Point::getY() const
{
	return _y;
}

void VG::Point::setX(int value)
{
	_x = value;
}

void VG::Point::setY(int value)
{
	_y = value;
}

bool VG::operator==(const VG::Point& lhs, const VG::Point& rhs)
{
	return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool VG::operator!=(const VG::Point& lhs, const VG::Point& rhs)
{
	return lhs.getX() != rhs.getX() && lhs.getY() != rhs.getY();
}

std::ostream& VG::operator<<(std::ostream& output, VG::Point& p)
{
	output << p.getX() << ", " << p.getY();
	output.flush();

	return output;
}