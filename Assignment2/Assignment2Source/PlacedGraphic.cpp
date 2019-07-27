#include "PlacedGraphic.h"

Framework::PlacedGraphic::PlacedGraphic(VG::Point&& p, VG::HVectorGraphic& vg)
	:placementPoint(p), graphic(vg)
{
}


void Framework::PlacedGraphic::setPlacementPoint(VG::Point const& placement)
{
	placementPoint = placement;
}

VG::Point const& Framework::PlacedGraphic::getPlacementPoint() const
{
	return placementPoint;
}

void Framework::PlacedGraphic::setGraphic(VG::HVectorGraphic const& referenceGraphic)
{
	graphic = referenceGraphic;
}

VG::HVectorGraphic const& Framework::PlacedGraphic::getGraphic() const
{
	return graphic;
}

bool Framework::operator==(const Framework::PlacedGraphic& lhs, const Framework::PlacedGraphic& rhs)
{
	return lhs.getPlacementPoint() == rhs.getPlacementPoint() && lhs.getGraphic() == rhs.getGraphic();
}

bool Framework::operator!=(const Framework::PlacedGraphic& lhs, const Framework::PlacedGraphic& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Framework::operator<<(std::ostream& output, Framework::PlacedGraphic& pg)
{
	VG::Point point = pg.getPlacementPoint();
	output << point;
	output << pg.getGraphic();
	output.flush();

	return output;
}
