#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"

namespace VG
{
	using HVectorGraphic = std::shared_ptr<VectorGraphic>;
}

namespace Framework
{
	class PlacedGraphic
	{
	public:
		//PlacedGraphic();
		PlacedGraphic(VG::Point& p, VG::HVectorGraphic& vg);

		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic& operator=(const PlacedGraphic& other) = default;
		PlacedGraphic& operator=(PlacedGraphic&& other) = default;
		~PlacedGraphic();

		void setPlacementPoint(VG::Point const& placement);
		VG::Point const& getPlacementPoint() const;

		void setGraphic(VG::HVectorGraphic const& graphic);
		VG::HVectorGraphic const& getGraphic() const;

	private:
		VG::Point placementPoint;
		VG::HVectorGraphic graphic;
	};
}