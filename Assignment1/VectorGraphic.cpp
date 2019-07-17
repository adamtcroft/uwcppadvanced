#include "stdafx.h"
#include "VectorGraphic.h"

using Points = std::vector<VG::Point>;

VG::VectorGraphic::VectorGraphic()
{
}

VG::VectorGraphic::~VectorGraphic()
{
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
	return -1;
}

int VG::VectorGraphic::getHeight() const
{
	return -1;
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
