#include "PlacedGraphic.h"

PlacedGraphic::PlacedGraphic()
{
}


PlacedGraphic::~PlacedGraphic()
{
}

void PlacedGraphic::setPlacementPoint(VG::Point const& placement)
{

}

VG::Point const& PlacedGraphic::getPlacementPoint() const
{
	VG::Point temp;
	return temp;
}

void PlacedGraphic::setGraphic(HVectorGraphic const& graphic)
{

}

HVectorGraphic const& PlacedGraphic::getGraphic() const
{
	HVectorGraphic temp = std::make_shared<VG::VectorGraphic>();
	return temp;
}
