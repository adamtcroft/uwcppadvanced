#include "stdafx.h"
#include "VectorGraphic.h"


VectorGraphic::VectorGraphic()
{
}

VectorGraphic::~VectorGraphic()
{
}

void VectorGraphic::addPoint(const Point& p)
{
	myPath.push_back(p);
}

void VectorGraphic::removePoint(const Point& p)
{
	for (Points::iterator i = myPath.begin(); i < myPath.end(); i++)
	{
		if (*i == p)
		{
			myPath.erase(i);
		}
	}
}

void VectorGraphic::erasePoint(int index)
{
	myPath.erase(myPath.begin() + index);
}