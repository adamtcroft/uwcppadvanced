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
		}
	}
}

void VG::VectorGraphic::erasePoint(int index)
{
	myPath.erase(myPath.begin() + index);
}