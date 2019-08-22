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
