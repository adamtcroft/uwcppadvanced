#pragma once
#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "Point.h"

namespace Framework
{
	class PlacedGraphic
	{
	public:
		PlacedGraphic();
//		PlacedGraphic(VG::Point& p, VG::HVectorGraphic& vg);
//		//PlacedGraphic(VG::Point&& p, VG::HVectorGraphic& vg);
//		//PlacedGraphic(VG::Point&& p, VG::HVectorGraphic&& vg);
//
//		PlacedGraphic(const PlacedGraphic& other) = default;
//		PlacedGraphic(PlacedGraphic&& other) = default;
//
//		PlacedGraphic& operator=(const PlacedGraphic& other) = default;
//		PlacedGraphic& operator=(PlacedGraphic&& other) = default;
//
		~PlacedGraphic() = default;
//
//		template<class P> void setPlacementPoint(P&& p);
//		//void setPlacementPoint(VG::Point const& placement);
//		void setGraphic(VG::HVectorGraphic const& referenceGraphic);
//
		VG::Point const& getPlacementPoint() const;
		VG::HVectorGraphic const& getGraphic() const;
//
//		//friend bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
//		//friend bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
//		friend std::ostream& operator<<(std::ostream& output, Framework::PlacedGraphic& pg);
//
	private:
		VG::Point placementPoint;
		VG::HVectorGraphic graphic;
	};

	bool operator==(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
	bool operator!=(const PlacedGraphic& lhs, const PlacedGraphic& rhs);
}