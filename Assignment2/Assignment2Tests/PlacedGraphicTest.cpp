#include "PlacedGraphic.h"
#include "VectorGraphic.h"
#include "TestHarness.h"

TEST(ctor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);

    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK_EQUAL(vg, pg.getGraphic());
}

TEST(setPlacementPoint, PlacedGraphic)
{
    Framework::PlacedGraphic graphic;
    graphic.setPlacementPoint(VG::Point(44, 55));

    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);

	CHECK_EQUAL(vg, pg.getGraphic());
}

TEST(copyCtor, PlacedGraphic)
{
	Framework::PlacedGraphic pg;
	VG::HVectorGraphic vg(new VG::VectorGraphic);

	Framework::PlacedGraphic pg2(pg);

	CHECK_EQUAL(pg, pg2);
}

TEST(equality, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);

    Framework::PlacedGraphic pg2;
    pg2.setGraphic(vg);

	CHECK_EQUAL(pg, pg2);
}

TEST(inequality, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);

    Framework::PlacedGraphic pg2;
    VG::HVectorGraphic vg2(new VG::VectorGraphic);
    pg2.setGraphic(vg2);

	CHECK(pg != pg2);
}

TEST(sharedPtr, HVectorGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);

    Framework::PlacedGraphic pg2;
    pg2.setGraphic(vg);

	CHECK_EQUAL(pg.getGraphic(), pg2.getGraphic());
}

// TEST RVALUE CTOR!
/*
TEST(rValueCopyCtor, PlacedGraphic)
{
	Framework::PlacedGraphic pg(Framework::PlacedGraphic());
	Framework::PlacedGraphic pg2;
	CHECK_EQUAL(pg2, pg);
}
*/
