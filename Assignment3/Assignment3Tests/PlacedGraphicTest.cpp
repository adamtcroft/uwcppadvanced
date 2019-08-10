#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

TEST(ctor, PlacedGraphic)
{
    VG::VectorGraphic vg;
	Framework::PlacedGraphic pg({ 44,55 }, vg);


    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK_EQUAL(vg, pg.getGraphic());
}

TEST(copyCtor, PlacedGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 3,4 });
	Framework::PlacedGraphic pg({ 1,1 }, vg);

	Framework::PlacedGraphic pg2(pg);

	CHECK(pg == pg2);
	CHECK(pg.getGraphic().getPointCount() == 1);
}

TEST(moveCtor, PlacedGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 8,9 });
	Framework::PlacedGraphic pg(VG::Point{ 1,1 }, vg);
	Framework::PlacedGraphic pg2(std::move(pg));

	CHECK_EQUAL(VG::Point(1,1), pg2.getPlacementPoint());
	CHECK_EQUAL(VG::Point(), pg.getPlacementPoint());
	CHECK_EQUAL(1, pg2.getGraphic().getPointCount());
	CHECK_EQUAL(0, pg.getGraphic().getPointCount());
}

TEST(copyAssignment, PlacedGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{1, 1});
    Framework::PlacedGraphic pg(VG::Point{44,55}, vg);
	auto pg2 = pg;

	CHECK(pg2 == pg);
	CHECK_EQUAL(1, pg.getGraphic().getPointCount());
	CHECK_EQUAL(1, pg2.getGraphic().getPointCount());
}

TEST(moveAssignment, PlacedGraphic)
{
	VG::VectorGraphic vg;
	vg.addPoint(VG::Point{ 4,5 });
	Framework::PlacedGraphic pg;
	pg = Framework::PlacedGraphic({ 1,1 }, vg);

	CHECK_EQUAL(VG::Point(1,1), pg.getPlacementPoint());
	CHECK_EQUAL(1, pg.getGraphic().getPointCount());
}

//TEST(setPlacementPoint, PlacedGraphic)
//{
//    Framework::PlacedGraphic graphic;
//    graphic.setPlacementPoint(VG::Point(44, 55));
//
//    constexpr VG::Point expected(44, 55);
//    CHECK_EQUAL(expected, graphic.getPlacementPoint());
//}
//
//TEST(setGraphic, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg;
//    VG::HVectorGraphic vg(new VG::VectorGraphic);
//    pg.setGraphic(vg);
//
//	CHECK_EQUAL(vg, pg.getGraphic());
//}
//
//TEST(getPlacementPoint, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg(VG::Point(44,55), VG::HVectorGraphic(new VG::VectorGraphic));
//
//    CHECK_EQUAL(VG::Point(44,55), pg.getPlacementPoint());
//}
//
//TEST(getGraphic, PlacedGraphic)
//{
//	VG::HVectorGraphic vg(new VG::VectorGraphic);
//    Framework::PlacedGraphic pg(VG::Point(44,55), vg);
//
//    CHECK_EQUAL(vg, pg.getGraphic());
//}
//
//TEST(equality, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg;
//    VG::HVectorGraphic vg(new VG::VectorGraphic);
//    pg.setGraphic(vg);
//
//    Framework::PlacedGraphic pg2;
//    pg2.setGraphic(vg);
//
//	CHECK_EQUAL(pg, pg2);
//}
//
//TEST(inequality, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg;
//    VG::HVectorGraphic vg(new VG::VectorGraphic);
//    pg.setGraphic(vg);
//
//    Framework::PlacedGraphic pg2;
//    VG::HVectorGraphic vg2(new VG::VectorGraphic);
//    pg2.setGraphic(vg2);
//
//	CHECK(pg != pg2);
//}
//
//TEST(oStream, PlacedGraphic)
//{
//	Framework::PlacedGraphic pg;
//	std::ostringstream oss;
//	oss << pg;
//
//	std::ostringstream expected;
//	expected << "Placement Point: " << pg.getPlacementPoint() << std::endl;
//	expected << *pg.getGraphic();
//
//	CHECK_EQUAL(expected.str(), oss.str());
//}
//
//TEST(sharedPtr, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg;
//    VG::HVectorGraphic vg(new VG::VectorGraphic);
//    pg.setGraphic(vg);
//
//    Framework::PlacedGraphic pg2;
//    pg2.setGraphic(vg);
//
//	CHECK_EQUAL(pg.getGraphic(), pg2.getGraphic());
//}
//
//TEST(validateCoord, PlacedGraphic)
//{
//    Framework::PlacedGraphic pg;
//    VG::HVectorGraphic vg(new VG::VectorGraphic);
//    pg.setGraphic(vg);
//
//    Framework::PlacedGraphic pg2;
//    pg2.setGraphic(vg);
//
//	CHECK_EQUAL(pg.getGraphic(), pg2.getGraphic());
//}
