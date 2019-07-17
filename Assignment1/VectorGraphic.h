#pragma once

#include <vector>
#include "Point.h"

namespace VG
{
	using Points = std::vector<VG::Point>;

	class VectorGraphic
	{
	public:
		VectorGraphic();
		~VectorGraphic();

		void addPoint(const VG::Point& p);
		void removePoint(const VG::Point& p);
		void erasePoint(int index);

		void openShape();
		void closeShape();

		bool isOpen() const;
		bool isClosed() const;
		int getWidth() const;
		int getHeight() const;
		Points getPath() const;

		int getPointCount() const;
		Point getPoint(int index) const;

		friend bool operator==(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);
		friend bool operator!=(const VG::VectorGraphic& lhs, const VG::VectorGraphic& rhs);

	private:
		Points myPath;
		bool openness;
	};
}
