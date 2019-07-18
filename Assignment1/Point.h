#pragma once
#include <iostream>

namespace VG
{
	struct Point
	{
	public:
		Point();
		constexpr Point(int x, int y)
			:_x(x), _y(y) {};
		~Point() = default;

		constexpr int getX() const { return _x; };
		constexpr int getY() const { return _y; };

		void setX(int value);
		void setY(int value);

		friend bool operator==(const VG::Point& lhs, const VG::Point& rhs);
		friend bool operator!=(const VG::Point& lhs, const VG::Point& rhs);
		friend std::ostream& operator<<(std::ostream& output, VG::Point& p);

	private:
		int _x, _y;
	};
}
