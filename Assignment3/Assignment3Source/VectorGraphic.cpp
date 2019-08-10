#include "VectorGraphic.h"

void VG::VectorGraphic::removePoint(const Point& p)
{
	auto result = std::find(myPath.begin(), myPath.end(), p);

	if (result == myPath.end())
		throw std::out_of_range("The point provided does not exist.");
	else
		myPath.erase(result);
}

void VG::VectorGraphic::erasePoint(int index)
{
	if (index > myPath.size() || index < 0 || myPath.empty())
		throw std::out_of_range("Cannot erase element out of range!");
	else
		myPath.erase(myPath.begin() + index);
}

void VG::VectorGraphic::openShape()
{
	shapeOpenness = Openness::Open;
}

void VG::VectorGraphic::closeShape()
{
	shapeOpenness = Openness::Closed;
}

bool VG::VectorGraphic::isOpen() const
{
	return shapeOpenness == Openness::Open;
}

bool VG::VectorGraphic::isClosed() const
{
	return shapeOpenness == Openness::Closed;
}

int VG::VectorGraphic::getWidth() const
{
	std::vector<int> coords;
	for (auto point : myPath)
	{
		coords.push_back(point.getX());
	}

	if (coords.size() == 0)
		return 0;
	else
	{
		auto result = std::minmax_element(coords.begin(), coords.end());

		return *result.second - *result.first;
	}
}

int VG::VectorGraphic::getHeight() const
{
	std::vector<int> coords;
	for (auto point : myPath)
	{
		coords.push_back(point.getY());
	}

	if (coords.size() == 0)
		return 0;
	else
	{
		auto result = std::minmax_element(coords.begin(), coords.end());

		return *result.second - *result.first;
	}
}

size_t VG::VectorGraphic::getPointCount() const
{
	return myPath.size();
}

const VG::Point& VG::VectorGraphic::getPoint(int index) const
{
	return myPath.at(index);
}

bool VG::VectorGraphic::operator==(const VG::VectorGraphic& rhs) const
{
	return (shapeOpenness == rhs.shapeOpenness) && (myPath == rhs.myPath);
}

bool VG::VectorGraphic::operator!=(const VG::VectorGraphic& rhs) const
{
	return !(*this == rhs);
}

std::ostream& VG::operator<<(std::ostream& output, VG::VectorGraphic& vg)
{
	//output << "VectorGraphic Openness: " << (vg.isOpen() ? "open" : "closed") << std::endl;
	//output << "VectorGraphic Point Count: " << vg.getPointCount() << std::endl;
	//output << "VectorGraphic Width: " << vg.getWidth() << std::endl;
	//output << "VectorGraphic Height: " << vg.getHeight() << std::endl;

	//for (auto point : vg.myPath)
	//{
	//	output << "Point: " << point.getX() << ", " << point.getY() << std::endl;
	//}
	output << "VECTORGRAPHIC";
	output.flush();

	return output;
}
