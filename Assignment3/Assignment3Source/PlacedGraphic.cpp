#include "PlacedGraphic.h"

Framework::PlacedGraphic::PlacedGraphic()
	:placementPoint(VG::Point(0,0)), graphic(VG::HVectorGraphic(new VG::VectorGraphic))
{
}

Framework::PlacedGraphic::PlacedGraphic(VG::Point& p, VG::HVectorGraphic& vg)
	:placementPoint(p), graphic(vg)
{
}

//Framework::PlacedGraphic::PlacedGraphic(VG::Point&& p, VG::HVectorGraphic& vg)
//	:placementPoint(std::move(p)), graphic(vg)
//{
//}
//
//Framework::PlacedGraphic::PlacedGraphic(VG::Point&& p, VG::HVectorGraphic&& vg)
//	:placementPoint(p), graphic(vg)
//{
//}

//Framework::PlacedGraphic::PlacedGraphic(PlacedGraphic&& other)
//	:placementPoint(std::move(other.placementPoint)), graphic(std::move(other.graphic))
//{
//	other.placementPoint = VG::Point();
//	other.graphic = nullptr;
//}

//Framework::PlacedGraphic& Framework::PlacedGraphic::operator=(PlacedGraphic&& other)
//{
//	if (&other != this)
//	{
//		placementPoint = other.placementPoint;
//		other.placementPoint = VG::Point();
//
//		graphic = other.graphic;
//		other.graphic = nullptr;
//	}
//	return *this;
//}

//void Framework::PlacedGraphic::setPlacementPoint(VG::Point const& placement)
//{
//	placementPoint = placement;
//}

template<class P> void Framework::PlacedGraphic::setPlacementPoint(P&& p)
{
	placementPoint = std::forward<P>(p);
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

bool Framework::operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
{
	return lhs.placementPoint == rhs.placementPoint && lhs.graphic == rhs.graphic;
}

bool Framework::operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Framework::operator<<(std::ostream& output, Framework::PlacedGraphic& pg)
{
	auto g = *pg.graphic;
	output << "Placement Point: " << pg.placementPoint << std::endl;
	output << *pg.graphic;
	output.flush();

	return output;
}
