#pragma once
#include <iostream>

namespace VG
{
	class Point
	{
	public:
		Point();
		constexpr Point(int x, int y);
		~Point();

		constexpr int getX() const;
		int const getY() const;

		void setX(int value);
		void setY(int value);

		friend bool operator==(const Point& lhs, const Point& rhs);
		friend bool operator!=(const Point& lhs, const Point& rhs);
		friend std::ostream& operator<<(std::ostream& output, Point& p);

	private:
		int _x;
		int _y;
	};
}
