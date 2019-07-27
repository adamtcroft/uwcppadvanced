#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"


namespace Framework
{
	class PlacedGraphic
	{
	public:
		//PlacedGraphic();
		PlacedGraphic(VG::Point& p, const VG::VectorGraphic vg);

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
namespace VG
{
	using HVectorGraphic = const VG::VectorGraphic&;
}