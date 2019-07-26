#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include "Point.h"

namespace VG
{
	using Points = std::vector<VG::Point>;

	class VectorGraphic
	{
	public:
		VectorGraphic();

		VectorGraphic(const VectorGraphic& other) = default;
		VectorGraphic(VectorGraphic&& other) = default;

		VectorGraphic& operator=(const VectorGraphic& other) = default;
		VectorGraphic& operator=(VectorGraphic&& other) = default;

		~VectorGraphic();

		void addPoint(const VG::Point& p);
		void addPoint(VG::Point&& p);
		void removePoint(const VG::Point& p);
		void erasePoint(int index);

		void openShape();
		void closeShape();

		bool isOpen() const;
		bool isClosed() const;

		int getWidth() const;
		int getHeight() const;

		int getPointCount() const;
		const Point& getPoint(int index) const;

		friend bool operator==(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);
		friend bool operator!=(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);
		friend std::ostream& operator<<(std::ostream& output, VG::VectorGraphic& vg);

	private:
		Points myPath;
		enum class Openness { Open, Closed } shapeOpenness = Openness::Closed;
	};
}
