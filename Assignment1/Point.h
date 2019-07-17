#pragma once
#include <iostream>

namespace VG
{
	class Point
	{
	public:
		Point();
		Point(int x, int y);
		~Point();

		int getX() const;
		int const getY() const;

		void setX(int value);
		void setY(int value);

		friend bool operator==(const VG::Point& lhs, const VG::Point& rhs);
		friend bool operator!=(const VG::Point& lhs, const VG::Point& rhs);
		friend std::ostream& operator<<(std::ostream& output, VG::Point& p);

	private:
		int _x;
		int _y;
	};
}
