#include "SceneWriter.h"

void Framework::SceneWriter::buildSceneChildren(LayerIterator iterator, Xml::HElement result)
{
	Xml::HElement child = std::make_shared<Xml::Element>();
	child->setName("Layer");
	child->setAttribute("alias", iterator->getAlias());
	result->addChild(child);

	for (auto pgIterator = iterator->begin(); pgIterator != iterator->end(); pgIterator++)
	{
		Xml::HElement pgChild = std::make_shared<Xml::Element>();
		pgChild->setName("PlacedGraphic");
		VG::Point p = pgIterator->getPlacementPoint();
		pgChild->setAttribute("x", std::to_string(p.getX()));
		pgChild->setAttribute("y", std::to_string(p.getY()));
		child->addChild(pgChild);

		Xml::HElement vgChild = std::make_shared<Xml::Element>();
		vgChild->setName("VectorGraphic");
		VG::HVectorGraphic vg = pgIterator->getGraphic();
		vgChild->setAttribute("closed", (vg->isClosed() == true ? "true" : "false"));
		pgChild->addChild(vgChild);
	}
}

Xml::HElement Framework::SceneWriter::writeScene(Scene& scene)
{
	Xml::HElement result = std::make_unique<Xml::Element>();
	result->setName("Scene");
	result->setAttribute("width", std::to_string(scene.getWidth()));
	result->setAttribute("height", std::to_string(scene.getHeight()));

	for (auto layerIterator = scene.begin(); layerIterator != scene.end(); layerIterator++)
	{
		buildSceneChildren(layerIterator, result);
	}


	return result;
}
