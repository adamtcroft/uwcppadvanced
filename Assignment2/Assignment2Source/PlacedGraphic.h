#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"

namespace Framework
{
	class PlacedGraphic
	{
	public:
		PlacedGraphic() = default;
		PlacedGraphic(VG::Point&& p, VG::HVectorGraphic& vg);

		//Test These
		PlacedGraphic(const PlacedGraphic& other) = default;
		PlacedGraphic(PlacedGraphic&& other) = default;

		PlacedGraphic& operator=(const PlacedGraphic& other) = default;
		PlacedGraphic& operator=(PlacedGraphic&& other) = default;

		~PlacedGraphic() = default;

		void setPlacementPoint(VG::Point const& placement);
		void setGraphic(VG::HVectorGraphic const& referenceGraphic);

		VG::Point const& getPlacementPoint() const;
		VG::HVectorGraphic const& getGraphic() const;

		friend bool operator==(const Framework::PlacedGraphic& lhs, const Framework::PlacedGraphic& rhs);
		friend bool operator!=(const Framework::PlacedGraphic& lhs, const Framework::PlacedGraphic& rhs);
		friend std::ostream& operator<<(std::ostream& output, Framework::PlacedGraphic& pg);

	private:
		VG::Point placementPoint;
		VG::HVectorGraphic graphic;
	};

}