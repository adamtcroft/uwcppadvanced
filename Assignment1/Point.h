#pragma once
#include <iostream>

namespace VG
{
	struct Point
	{
	public:
		Point();
		Point(int x, int y) :myX(x), myY(y) {};
		~Point();

		constexpr int getX() const noexcept { return myX; };
		constexpr int getY() const noexcept { return myY; };

		void setX(int value);
		void setY(int value);

		friend bool operator==(const VG::Point& lhs, const VG::Point& rhs);
		friend bool operator!=(const VG::Point& lhs, const VG::Point& rhs);
		friend std::ostream& operator<<(std::ostream& output, VG::Point& p);

	private:
		int myX, myY;
	};
}
