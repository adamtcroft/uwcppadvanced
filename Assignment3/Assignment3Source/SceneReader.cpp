#include "SceneReader.h"
#include "Scene.h"
#include "XmlInterfaces.h"
#include "VectorGraphic.h"
#include <sstream>

Framework::Scene Framework::SceneReader::readScene(Xml::IElement& root)
{
	if (root.getName() != "Scene")
	{
		throw std::runtime_error("Expected Scene");
	}
	int width = std::stoi(root.getAttribute("width"));
	int height = std::stoi(root.getAttribute("height"));
	Scene myScene(width, height);

	Xml::ElementCollection layers = root.getChildElements();
	Xml::ElementCollection::const_iterator layer;
	for (layer = layers.begin(); layer != layers.end(); ++layer)
	{
		readLayer(myScene, *layer);
	}

	return myScene;
}

void Framework::SceneReader::readLayer(Framework::Scene& scene,	const Xml::HElement layerElement)
{
	if (layerElement->getName() != "Layer")
	{
		throw std::runtime_error("Expected Layer");
	}

	Framework::Layer layer(layerElement->getAttribute("alias"));

	Xml::ElementCollection graphics = layerElement->getChildElements();
	Xml::ElementCollection::const_iterator graphic;
	for (graphic = graphics.begin(); graphic != graphics.end(); ++graphic)
	{
		readGraphic(scene, layer, *graphic);
	}

	scene.pushBack(layer);
}

void Framework::SceneReader::readGraphic(Framework::Scene& scene, Framework::Layer& layer, Xml::HElement graphicElement)
{
	if (graphicElement->getName() != "PlacedGraphic")
	{
		throw std::runtime_error("Expected PlacedGraphic");
	}

	Framework::PlacedGraphic pg;
	int x = std::stoi(graphicElement->getAttribute("x"));
	int y = std::stoi(graphicElement->getAttribute("y"));

	if (x < 0 || y < 0 ||
		x > scene.getWidth() || y > scene.getHeight())
	{
		throw std::runtime_error("PlacedGraphic out of bounds");
	}

	pg.setPlacementPoint(VG::Point(x, y));

	Xml::ElementCollection vectorGraphics = graphicElement->getChildElements();
	Xml::ElementCollection::const_iterator vgElement;
	for (vgElement = vectorGraphics.begin(); vgElement != vectorGraphics.end(); ++vgElement)
	{
		// TODO - assert - there should only be one of these
		pg.setGraphic(readVectorGraphic(*vgElement));
	}

	layer.pushBack(pg);
}

VG::VectorGraphic Framework::SceneReader::readVectorGraphic(Xml::HElement vgElement)
{
	VG::VectorGraphic vg;

	std::string closed = vgElement->getAttribute("closed");
	if (closed == "true")
	{
		vg.closeShape();
	}
	else if (closed == "false")
	{
		vg.openShape();
	}
	else
	{
		throw std::runtime_error("Invalid VectorGraphic attribute");
	}

	Xml::ElementCollection points = vgElement->getChildElements();
	Xml::ElementCollection::const_iterator p;
	for (p = points.begin(); p != points.end(); ++p)
	{
		int x = std::stoi((*p)->getAttribute("x"));
		int y = std::stoi((*p)->getAttribute("y"));
		vg.addPoint(VG::Point(x, y));
	}

	return vg;
}


//Framework::Scene Framework::SceneReader::readScene(Xml::Element& root)
//{
//	Scene scene;
//	auto elementName = root.getName();
//	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);
//
//	if (elementName == "scene")
//	{
//		scene.setWidth(std::stoi(root.getAttribute("width")));
//		scene.setHeight(std::stoi(root.getAttribute("height")));
//
//		for (auto element : root.getChildElements())
//		{
//			buildLayer(scene, element);
//		}
//	}
//	else
//		return scene;
//
//
//	return scene;
//}
//
//void Framework::SceneReader::buildLayer(Scene& parent, Xml::HElement& element)
//{
//	std::string elementName = element->getName();
//	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);
//
//	if (elementName == "layer")
//	{
//		Layer layer(element->getAttribute("alias"));
//
//		for (auto child : element->getChildElements())
//		{
//			buildPlacedGraphic(layer, child);
//		}
//
//		parent.pushBack(layer);
//	}
//}
//
//void Framework::SceneReader::buildPlacedGraphic(Layer& parent, Xml::HElement& element)
//{
//	std::string elementName = element->getName();
//	std::transform(elementName.begin(), elementName.end(), elementName.begin(), ::tolower);
//
//	if (elementName == "placedgraphic")
//	{
//		auto childElements = element->getChildElements();
//
//		auto vectorGraphicElement = childElements[0];
//		auto closed = vectorGraphicElement->getAttribute("closed");
//		VG::VectorGraphic vg;
//		if (closed == "true")
//			vg.closeShape();
//		else
//			vg.openShape();
//
//		auto vgPoints = vectorGraphicElement->getChildElements();
//		for (auto point : vgPoints)
//		{
//			VG::Point p(std::stoi(point->getAttribute("x")), std::stoi(point->getAttribute("y")));
//			vg.addPoint(p);
//		}
//
//		VG::HVectorGraphic hvg = std::make_shared<VG::VectorGraphic>(vg);
//		VG::Point point(std::stoi(element->getAttribute("x")), std::stoi(element->getAttribute("y")));
//		PlacedGraphic pg(point, hvg);
//		parent.pushBack(pg);
//	}
//}
