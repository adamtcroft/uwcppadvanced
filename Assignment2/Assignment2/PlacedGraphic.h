#pragma once
#include "Point.h"
#include "VectorGraphic.h"

using HVectorGraphic = std::shared_ptr<VG::VectorGraphic>;

class PlacedGraphic
{
public:
	PlacedGraphic();
	~PlacedGraphic();

	void setPlacementPoint(VG::Point const& placement);
	VG::Point const& getPlacementPoint() const;

	void setGraphic(HVectorGraphic const& graphic);
	HVectorGraphic const& getGraphic() const;

private:
	VG::Point placementPoint;
	HVectorGraphic graphic;
};

