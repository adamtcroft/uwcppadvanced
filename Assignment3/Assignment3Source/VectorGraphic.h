#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include "Point.h"

namespace VG
{
	class VectorGraphic;
	using HVectorGraphic = std::shared_ptr<VectorGraphic>;
	using Points = std::vector<VG::Point>;

	class VectorGraphic
	{
	public:
		VectorGraphic() = default;

		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;

		VectorGraphic& operator=(const VectorGraphic& other) = default;
		VectorGraphic& operator=(VectorGraphic&& other) = default;

		~VectorGraphic() = default;

		template<class C> void addPoint(C&& p)
		{
			myPath.emplace_back(std::forward<C>(p));
		}

		//		void removePoint(const VG::Point& p);
		//		void erasePoint(int index);
		//
		//		void openShape();
		//		void closeShape();
		//
		bool isOpen() const;
		//		bool isClosed() const;
		//
		//		int getWidth() const;
		//		int getHeight() const;
		//
		size_t getPointCount() const;
		//		const Point& getPoint(int index) const;
		//
		friend std::ostream& operator<<(std::ostream& output, VG::VectorGraphic& vg);
		//
		//	private:
		Points myPath;
		enum class Openness { Open, Closed } shapeOpenness = Openness::Closed;
	};
	bool operator==(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);
	bool operator!=(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);
}
