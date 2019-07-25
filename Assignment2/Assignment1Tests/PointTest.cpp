//
//  PointTest.cpp
//  Assignment1
//
//  Created by Chris Elderkin on 4/26/15.
//  Copyright (c) 2015 Chris Elderkin. All rights reserved.
//

#include "Point.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

TEST(equality, Point)
{
	CHECK_EQUAL(VG::Point(1, 2), VG::Point(1, 2));
}

TEST(inequality, Point)
{
	CHECK(VG::Point(1, 2) != VG::Point(3, 4));
}

TEST(inequality2, Point)
{
	CHECK(VG::Point(1, 2) != VG::Point(1, 4));
}

TEST(inequality3, Point)
{
	CHECK(VG::Point(2, 4) != VG::Point(1, 4));
}

TEST(constexprPoint, Point)
{
	constexpr int i = VG::Point{ 4,5 }.getX();

	CHECK_EQUAL(i, 4);
}

TEST(constexprPointY, Point)
{
	constexpr int i = VG::Point{ 4,5 }.getY();

	CHECK_EQUAL(i, 5);
}

TEST(setters, Point)
{
	VG::Point p;

	p.setX(0);
	p.setY(1);

	CHECK_EQUAL(0, p.getX());
	CHECK_EQUAL(1, p.getY());
}

TEST(ostream, Point)
{
	VG::Point p{ 8,10 };

	std::ostringstream oss;
	oss << p;
	std::string myString = oss.str();

	CHECK_EQUAL("8, 10", myString);
}
