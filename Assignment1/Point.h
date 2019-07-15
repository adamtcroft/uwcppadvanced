#pragma once
class Point
{
public:
	Point();
	~Point();

	int getX() const;
	int getY() const;

	void setX(int value);
	void setY(int value);

private:
	int x, y;
};

