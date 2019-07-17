#include "stdafx.h"
#include "VectorGraphic.h"

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

int VG::VectorGraphic::getPointCount() const
{
	return myPath.size();
}

VG::Point VG::VectorGraphic::getPoint(int index) const
{
	return myPath[index];
}
