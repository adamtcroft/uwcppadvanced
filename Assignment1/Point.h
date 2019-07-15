#pragma once
#include <iostream>

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int getX() const;
	int getY() const;

	void setX(int value);
	void setY(int value);

	friend bool operator==(const Point& lhs, const Point& rhs);
	friend bool operator!=(const Point& lhs, const Point& rhs);
	friend std::ostream& operator<<(std::ostream& output, Point& p);

private:
	int _x, _y;
};
