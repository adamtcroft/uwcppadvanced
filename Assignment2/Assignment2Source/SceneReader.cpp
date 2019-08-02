#include "SceneReader.h"

Framework::SceneReader::SceneReader()
{
}


Framework::SceneReader::~SceneReader()
{
}

Framework::Scene Framework::SceneReader::readScene(Xml::Element& root)
{
	Scene scene(std::stoi(root.getAttribute("width")), std::stoi((root.getAttribute("height"))));

	return scene;
}