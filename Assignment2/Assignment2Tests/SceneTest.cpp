#include "Scene.h"
#include "TestHarness.h"
#include <algorithm>

struct LayerMatcher
{
    LayerMatcher() :
    myMountainsFound(false),
    mySeaFound(false),
    mySkyFound(false)
    {
    }
    
    void operator()(const Framework::Layer& layer)
    {
        if (layer.getAlias() == "Mountains")
        {
            myMountainsFound = true;
        }
        else if (layer.getAlias() == "Sea")
        {
            mySeaFound = true;
        }
        else if (layer.getAlias() == "Sky")
        {
            mySkyFound = true;
        }
    }
    
    bool allLayersFound()
    {
        return myMountainsFound && mySeaFound && mySkyFound;
    }
    
    bool onlyMountainsSkyFound()
    {
        return myMountainsFound && !mySeaFound && mySkyFound;
    }
    
private:
    bool myMountainsFound;
    bool mySeaFound;
    bool mySkyFound;
};

TEST(pushBack, Scene)
{
    Framework::Scene scene(800, 600);
	scene.pushBack(Framework::Layer("Mountains"));
	scene.pushBack(Framework::Layer("Sea"));
	scene.pushBack(Framework::Layer("Sky"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.allLayersFound());
}

TEST(remove, Scene)
{
    Framework::Scene scene(800, 600);
	scene.pushBack(Framework::Layer("Mountains"));
	scene.pushBack(Framework::Layer("Sea"));
	scene.pushBack(Framework::Layer("Sky"));
    
    scene.remove(Framework::Layer("Sea"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.onlyMountainsSkyFound());
}

TEST(setWidth, Scene)
{
	Framework::Scene scene(800, 600);

	CHECK_EQUAL(800, scene.getWidth());

	scene.setWidth(200);

	CHECK_EQUAL(200, scene.getWidth());
}

TEST(getWidth, Scene)
{
	Framework::Scene scene(800, 600);

	CHECK_EQUAL(800, scene.getWidth());
}

TEST(setHeigh, Scene)
{
	Framework::Scene scene(800, 600);

	CHECK_EQUAL(600, scene.getHeight());

	scene.setHeight(200);

	CHECK_EQUAL(200, scene.getHeight());
}

TEST(getHeigh, Scene)
{
	Framework::Scene scene(800, 600);

	CHECK_EQUAL(600, scene.getHeight());
}

TEST(ctor, Scene)
{
	Framework::Scene scene(800, 600);

	CHECK_EQUAL(800, scene.getWidth());
	CHECK_EQUAL(600, scene.getHeight());
}

TEST(copyCtor, Scene)
{
	Framework::Scene scene(800, 600);

	Framework::Scene secondScene(scene);

	CHECK_EQUAL(scene, secondScene);
}

TEST(copyAssignment, Scene)
{
	Framework::Scene scene(800, 600);

	Framework::Scene secondScene = scene;

	CHECK_EQUAL(scene, secondScene);
}

TEST(moveAssignment, Scene)
{
	Framework::Scene scene(800, 600);

	Framework::Scene secondScene(400, 300);
	secondScene = std::move(scene);

	CHECK_EQUAL(800, secondScene.getWidth());
	CHECK_EQUAL(600, secondScene.getHeight());
	CHECK_EQUAL(0, scene.getHeight());
	CHECK_EQUAL(0, scene.getWidth());
}
