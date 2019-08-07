#include "Point.h"

VG::Point::Point()
{
}

VG::Point::Point(VG::Point&& other)
{
	if (&other != this)
	{
		x = other.x;
		y = other.y;
		other.x = 0;
		other.y = 0;
	}
}

void VG::Point::setX(int value)
{
	x = validateCoordinate(value);
}

void VG::Point::setY(int value)
{
	y = validateCoordinate(value);
}

int VG::Point::validateCoordinate(int& n) 
{
	return (n < 0) ? 0 : n;
}

bool VG::operator==(const VG::Point& lhs, const VG::Point& rhs)
{
	return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool VG::operator!=(const VG::Point& lhs, const VG::Point& rhs)
{
	return !(lhs == rhs);
}

std::ostream& VG::operator<<(std::ostream& output, VG::Point& p)
{
	output << "(" << p.getX() << ", " << p.getY() << ")";
	output.flush();

	return output;
}

std::ostream& VG::operator<<(std::ostream& output, const VG::Point& p)
{
	output << "(" << p.getX() << ", " << p.getY() << ")";
	output.flush();

	return output;
}
