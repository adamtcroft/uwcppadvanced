#pragma once
#include <iostream>

namespace VG
{
	struct Point
	{
	public:
		float _x, _y;
		Point();
		constexpr Point(int x = 0, int y = 0) noexcept
			:_x(x), _y(y) {};
		~Point();

		constexpr float getX() const noexcept { return _x; };
		constexpr float getY() const noexcept { return _y; };

		void setX(int value);
		void setY(int value);

		friend bool operator==(const VG::Point& lhs, const VG::Point& rhs);
		friend bool operator!=(const VG::Point& lhs, const VG::Point& rhs);
		friend std::ostream& operator<<(std::ostream& output, VG::Point& p);

	private:
	};
}
