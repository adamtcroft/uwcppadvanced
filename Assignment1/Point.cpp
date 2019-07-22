#include "stdafx.h"
#include "Point.h"

VG::Point::Point()
{
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
	return lhs.getX() != rhs.getX() || lhs.getY() != rhs.getY();
}

std::ostream& VG::operator<<(std::ostream& output, VG::Point& p)
{
	output << p.getX() << ", " << p.getY();
	output.flush();

	return output;
}