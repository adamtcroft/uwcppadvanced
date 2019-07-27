#include "PlacedGraphic.h"
/*
Framework::PlacedGraphic::PlacedGraphic()
{
}
*/

Framework::PlacedGraphic::PlacedGraphic(VG::Point& p, const VG::VectorGraphic vg)
	:placementPoint(p), graphic(vg)
{
}


Framework::PlacedGraphic::~PlacedGraphic()
{
}

void Framework::PlacedGraphic::setPlacementPoint(VG::Point const& placement)
{

}

VG::Point const& Framework::PlacedGraphic::getPlacementPoint() const
{
	VG::Point temp;
	return temp;
}

void Framework::PlacedGraphic::setGraphic(VG::HVectorGraphic const& graphic)
{

}

VG::HVectorGraphic const& Framework::PlacedGraphic::getGraphic() const
{
	VG::VectorGraphic temp;
	return temp;
}
