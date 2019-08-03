#include "SceneReader.h"

Framework::SceneReader::SceneReader()
{
}


Framework::SceneReader::~SceneReader()
{
}

Framework::Scene Framework::SceneReader::readScene(Xml::Element& root)
{
	Scene scene;
	auto elementName = root.getName();
	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);

	if (elementName == "scene")
	{
		scene.setWidth(std::stoi(root.getAttribute("width")));
		scene.setHeight(std::stoi(root.getAttribute("height")));

		for (auto element : root.getChildElements())
		{
			buildLayer(scene, element);
		}
	}
	else
		return scene;


	return scene;
}

void Framework::SceneReader::buildLayer(Scene& parent, Xml::HElement& element)
{
	std::string elementName = element->getName();
	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);

	if (elementName == "layer")
	{
		Layer layer(element->getAttribute("alias"));

		for (auto child : element->getChildElements())
		{
			buildPlacedGraphic(layer, child);
		}

		parent.pushBack(layer);
	}
}

void Framework::SceneReader::buildPlacedGraphic(Layer& parent, Xml::HElement& element)
{
	std::string elementName = element->getName();
	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);

	if (elementName == "placedgraphic")
	{
		auto childElements = element->getChildElements();

		auto vectorGraphicElement = childElements[0];
		auto closed = vectorGraphicElement->getAttribute("closed");
		VG::VectorGraphic vg;
		if (closed == "true")
			vg.closeShape();
		else
			vg.openShape();

		auto vgPoints = vectorGraphicElement->getChildElements();
		for (auto point : vgPoints)
		{
			VG::Point p(std::stoi(point->getAttribute("x")), std::stoi(point->getAttribute("y")));
			vg.addPoint(p);
		}

		VG::HVectorGraphic hvg = std::make_shared<VG::VectorGraphic>(vg);
		VG::Point point(std::stoi(element->getAttribute("x")), std::stoi(element->getAttribute("y")));
		PlacedGraphic pg(point, hvg);
		parent.pushBack(pg);
	}
}
