#include "TestHarness.h"
#include "Layer.h"
#include "VectorGraphic.h"
#include <ostream>

TEST(ctor, Layer)
{
	Framework::Layer myLayer("Test Alias");

	CHECK_EQUAL("Test Alias", myLayer.getAlias());
}

TEST(copyCtor, Layer)
{
	Framework::Layer myLayer("Test Alias");
	Framework::Layer mySecondLayer(myLayer);

	CHECK_EQUAL("Test Alias", mySecondLayer.getAlias());
}

TEST(moveConstructor, Layer)
{
	Framework::Layer mySecondLayer(std::move(Framework::Layer("Test Alias")));

	CHECK_EQUAL("Test Alias", mySecondLayer.getAlias());
}

TEST(copyAssignment, Layer)
{
	Framework::Layer myLayer("Test Alias");
	Framework::Layer mySecondLayer = myLayer;

	CHECK_EQUAL(myLayer, mySecondLayer);
}

TEST(moveAssignment, Layer)
{
	Framework::Layer myLayer("Placeholder");
	Framework::Layer secondLayer("Test Alias");
	myLayer = std::move(secondLayer);

	CHECK_EQUAL("Test Alias", myLayer.getAlias());
	CHECK_EQUAL("", secondLayer.getAlias())
}

TEST(getAndpushBack, Layer)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::Layer myLayer("Test Alias");
	Framework::PlacedGraphic pg;
	myLayer.pushBack(pg);

	CHECK_EQUAL(pg, myLayer.getGraphic(0));
}

TEST(remove, Layer)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::Layer myLayer("Test Alias");
	Framework::PlacedGraphic pg(VG::Point{ 1,1 }, VG::HVectorGraphic(new VG::VectorGraphic));
	Framework::PlacedGraphic pg2(VG::Point{ 0,0 }, VG::HVectorGraphic(new VG::VectorGraphic));
	Framework::PlacedGraphic pg3(VG::Point{ 3,8 }, VG::HVectorGraphic(new VG::VectorGraphic));
	myLayer.pushBack(pg);
	myLayer.pushBack(pg2);

	CHECK_EQUAL(pg, myLayer.getGraphic(0));

	myLayer.remove(pg);
	std::cout << std::endl;

	CHECK(pg != myLayer.getGraphic(0));

	try
	{
		myLayer.remove(pg3);
	}
	catch (std::out_of_range& e)
	{
		CHECK_EQUAL(e.what(), "The graphic provided does not exist.")
	}
}

TEST(setAlias, Layer)
{
	Framework::Layer myLayer("Test Alias");

	CHECK_EQUAL("Test Alias", myLayer.getAlias());

	myLayer.setAlias("Change Alias");

	CHECK_EQUAL("Change Alias", myLayer.getAlias());
}

TEST(getAlias, Layer)
{
	Framework::Layer myLayer("Test Alias");

	CHECK_EQUAL("Test Alias", myLayer.getAlias());
}

TEST(equality, Layer)
{
	Framework::Layer myLayer("Test Alias");
	Framework::Layer mySecondLayer("Test Alias");

	CHECK_EQUAL(mySecondLayer, myLayer);
}

TEST(inequality, Layer)
{
	Framework::Layer myLayer("Test Alias");
	Framework::Layer mySecondLayer("This is different");

	CHECK(myLayer != mySecondLayer);
}

TEST(outputStream, Layer)
{
	Framework::Layer myLayer("Test Alias");
	std::ostringstream oss;
	oss << myLayer;
	std::string myString = oss.str();

	CHECK_EQUAL("Test Alias", myString);
}

TEST(getOutOfRange, Layer)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::Layer myLayer("Test Alias");
	Framework::PlacedGraphic pg(VG::Point{ 0,0 }, vg);
	myLayer.pushBack(pg);

	try
	{
		auto graphic = myLayer.getGraphic(12);
	}
	catch (std::out_of_range& e)
	{
		CHECK_EQUAL(e.what(), "The graphic requested does not exist.")
	}
}
