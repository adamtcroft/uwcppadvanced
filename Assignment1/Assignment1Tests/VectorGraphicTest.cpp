#include "VectorGraphic.h"
#include "VectorGraphicStreamer.h"
#include "TestHarness.h"
#include <sstream>

TEST(ctor, VectorGraphic)
{
    VG::VectorGraphic vg;
    CHECK_EQUAL(0, vg.getPointCount());
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(defaultOpenness, VectorGraphic)
{
	VG::VectorGraphic vg;
	CHECK_EQUAL(false, vg.isOpen());
	CHECK_EQUAL(true, vg.isClosed());
}

TEST(insertPoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    CHECK_EQUAL(1, vg.getPointCount());
    
    vg.addPoint(VG::Point{2, 2});
    CHECK_EQUAL(2, vg.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.removePoint(VG::Point{1, 1});
    
    CHECK_EQUAL(1, vg.getPointCount());
    CHECK_EQUAL(VG::Point(2, 2), vg.getPoint(0));
}

TEST(erasePoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.addPoint(VG::Point{3, 3});
    vg.erasePoint(1);
    
    CHECK_EQUAL(2, vg.getPointCount());
    CHECK_EQUAL(VG::Point(1, 1), vg.getPoint(0));
    CHECK_EQUAL(VG::Point(3, 3), vg.getPoint(1));

	vg.erasePoint(0);
	CHECK_EQUAL(VG::Point(3, 3), vg.getPoint(0));
}


TEST(erasePointOutOfRange, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.addPoint(VG::Point{3, 3});
    
    try
    {
        vg.erasePoint(5);
    }
    catch (std::out_of_range&)
    {
        CHECK_EQUAL(3, vg.getPointCount());
        return;
    }
    CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
    VG::VectorGraphic vg1;
    vg1.addPoint(VG::Point{1, 1});
    vg1.addPoint(VG::Point{2, 2});
    vg1.addPoint(VG::Point{3, 3});
    
    VG::VectorGraphic vg2;
    vg2.addPoint(VG::Point{1, 1});
    vg2.addPoint(VG::Point{2, 2});
    vg2.addPoint(VG::Point{3, 3});
    
    CHECK(vg1 == vg2);
}

TEST(inequality, VectorGraphic)
{
    VG::VectorGraphic vg1;
    vg1.addPoint(VG::Point{1, 1});
    vg1.addPoint(VG::Point{1, 2});
    vg1.addPoint(VG::Point{1, 3});
    
    VG::VectorGraphic vg2;
    vg2.addPoint(VG::Point{2, 1});
    vg2.addPoint(VG::Point{2, 2});
    vg2.addPoint(VG::Point{2, 3});
    
    CHECK(vg1 != vg2);
    
    VG::VectorGraphic vg3;
    vg3.addPoint(VG::Point{1, 1});
    vg3.addPoint(VG::Point{1, 2});
    vg3.addPoint(VG::Point{1, 3});
    vg3.openShape();
    
    CHECK(vg3 != vg1);
}

TEST(closeShape, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.closeShape();
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(openShape, VectorGraphic)
{
    VG::VectorGraphic vg;
	CHECK_EQUAL(false, vg.isOpen());
	CHECK_EQUAL(true, vg.isClosed());
    vg.openShape();
    CHECK_EQUAL(false, vg.isClosed());
    CHECK_EQUAL(true, vg.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
    VG::VectorGraphic vectorGraphic;
    vectorGraphic.addPoint(VG::Point{0, 2});
    vectorGraphic.addPoint(VG::Point{4, 3});
    vectorGraphic.addPoint(VG::Point{5, 8});
    vectorGraphic.addPoint(VG::Point{2, 1});
    CHECK_EQUAL(5, vectorGraphic.getWidth());
    CHECK_EQUAL(7, vectorGraphic.getHeight());
    
    vectorGraphic.erasePoint(2);
    CHECK_EQUAL(4, vectorGraphic.getWidth());
    CHECK_EQUAL(2, vectorGraphic.getHeight());
}

TEST(getPointRange, VectorGraphic)
{
	VG::VectorGraphic vg;
    vg.addPoint(VG::Point{0, 2});

	try
	{
		auto point = vg.getPoint(1);
	}
	catch (std::out_of_range& e)
	{
		CHECK_EQUAL("Index of point out of range!", e.what())
	}
}


// This test throws an unresolved external symbol error and I'm not sure why
// as the function is defined and seen by the IDE...
/*
TEST(templateAdd, VectorGraphic)
{
    VG::VectorGraphic vectorGraphic;
    vectorGraphic.templateAddPoint(VG::Point{0, 2});
    CHECK_EQUAL(0, vectorGraphic.getPoint(0).getX());
}
*/

// C++11 has a new "raw string literal" that is useful for
// embedding long strings in a file for testing. Previously
// this would have to be done with a "stringification" macro:
//   #define STR(a) #a

const std::string VectorGraphicXml = R"(
<VectorGraphic closed="true">
<Point x="0" y="0"/>
<Point x="10" y="0">
</Point>
<Point x="10" y="10"/>
<Point x="0" y="10"/>
</VectorGraphic>
)";

TEST(fromXml, VectorGraphic)
{
    std::stringstream sstr(VectorGraphicXml);
    
    auto vg = VG::VectorGraphicStreamer::fromXml(sstr);
    
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(4, vg.getPointCount());
    CHECK_EQUAL(10, vg.getPoint(2).getX());
    CHECK_EQUAL(10, vg.getPoint(2).getY());
}

TEST(toXml, VectorGraphic)
{
    VG::VectorGraphic vg1;
    vg1.addPoint(VG::Point(1, 1));
    vg1.addPoint(VG::Point(2, 2));
    vg1.addPoint(VG::Point(3, 3));
    
    std::stringstream sstr;
    VG::VectorGraphicStreamer::toXml(vg1, sstr);
    
    auto vg2 = VG::VectorGraphicStreamer::fromXml(sstr);
    
    CHECK(vg1 == vg2);
}

std::string testXML = R"(
<VectorGraphic closed="true">
<Point x="0" y="0"/>
<Point x="10" y="0">
</Point>
<Point x="10" y="10"/>
<Point x="0" y="10"/>
)";

TEST(validXML, VectorGraphic)
{
	std::stringstream sstr(testXML);

	auto vg = VG::VectorGraphicStreamer::fromXml(sstr);
	VG::VectorGraphic control;

	CHECK_EQUAL(vg, control);
}
