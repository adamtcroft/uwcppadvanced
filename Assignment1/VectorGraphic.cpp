#include "stdafx.h"
#include "VectorGraphic.h"

using Points = std::vector<VG::Point>;

VG::VectorGraphic::VectorGraphic()
{
}

VG::VectorGraphic::~VectorGraphic()
{
}

template<typename T>
void VG::VectorGraphic::templateAddPoint(T&& p)
{
	myPath.push_back(std::forward<T>(p));
}

void VG::VectorGraphic::addPoint(const Point& p)
{
	myPath.push_back(p);
}

void VG::VectorGraphic::removePoint(const Point& p)
{
	for (Points::iterator i = myPath.begin(); i < myPath.end(); i++)
	{
		if (*i == p)
		{
			myPath.erase(i);
			return;
		}
	}
}

void VG::VectorGraphic::erasePoint(int index)
{
	if (index > myPath.size() || index < 1 || myPath.empty())
		throw std::out_of_range("Cannot erase element out of range!");
	else
		myPath.erase(myPath.begin() + index);
}

void VG::VectorGraphic::openShape()
{
	openness = true;
}

void VG::VectorGraphic::closeShape()
{
	openness = false;
}

bool VG::VectorGraphic::isOpen() const
{
	if (openness)
		return true;
	else
		return false;
}

bool VG::VectorGraphic::isClosed() const
{
	if (!openness)
		return true;
	else
		return false;
}

int VG::VectorGraphic::getWidth() const
{
	int smallest, largest;
	for (int i = 0; i < myPath.size(); i++)
	{
		if (i == 0)
		{
			smallest = myPath[i].getX();
			largest = myPath[i].getX();
		}
		else
		{
			if (myPath[i].getX() < smallest)
			{
				smallest = myPath[i].getX();
			}

			if (myPath[i].getX() > largest)
			{
				largest = myPath[i].getX();
			}
		}
	}

	return largest - smallest;
}

int VG::VectorGraphic::getHeight() const
{
	int smallest, largest;
	for (int i = 0; i < myPath.size(); i++)
	{
		if (i == 0)
		{
			smallest = myPath[i].getY();
			largest = myPath[i].getY();
		}
		else
		{
			if (myPath[i].getY() < smallest)
			{
				smallest = myPath[i].getY();
			}

			if (myPath[i].getY() > largest)
			{
				largest = myPath[i].getY();
			}
		}
	}

	return largest - smallest;
}

Points VG::VectorGraphic::getPath() const
{
	return myPath;
}

int VG::VectorGraphic::getPointCount() const
{
	return myPath.size();
}

VG::Point VG::VectorGraphic::getPoint(int index) const
{
	return myPath[index];
}

bool VG::operator==(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs)
{
	return lhs.getPath() == rhs.getPath() && lhs.isOpen() == rhs.isOpen();
}

bool VG::operator!=(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs)
{
	return lhs.getPath() != rhs.getPath() || lhs.isOpen() != rhs.isOpen();
}

std::ostream& VG::operator<<(std::ostream& output, VG::VectorGraphic& vg)
{
	output << "VectorGraphic Openness: " << vg.isOpen() << std::endl;
	output << "VectorGraphic Point Count: " << vg.getPointCount() << std::endl;
	output << "VectorGraphic Width: " << vg.getWidth() << std::endl;
	output << "VectorGraphic Height: " << vg.getHeight() << std::endl;

	for (auto point : vg.getPath())
	{
		output << "Point: " << point.getX() << ", " << point.getY() << std::endl;
	}
	output.flush();

	return output;
}
