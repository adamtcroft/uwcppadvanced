//#include "SceneWriter.h"
//
//Xml::HElement Framework::SceneWriter::writeScene(Scene& scene)
//{
//	Xml::HElement result = std::make_unique<Xml::Element>();
//	result->setName("Scene");
//	result->setAttribute("width", std::to_string(scene.getWidth()));
//	result->setAttribute("height", std::to_string(scene.getHeight()));
//
//	for (auto layerIterator = scene.begin(); layerIterator != scene.end(); layerIterator++)
//	{
//		writeLayers(layerIterator, result);
//	}
//
//	return result;
//}
//
//void Framework::SceneWriter::writeLayers(LayerIterator iterator, Xml::HElement scene)
//{
//	Xml::HElement layer = std::make_shared<Xml::Element>();
//	layer->setName("Layer");
//	layer->setAttribute("alias", iterator->getAlias());
//	scene->addChild(layer);
//
//	for (auto pgIterator = iterator->begin(); pgIterator != iterator->end(); pgIterator++)
//	{
//		writePlacedGraphics(pgIterator, layer);
//	}
//}
//
//void Framework::SceneWriter::writePlacedGraphics(PlacedGraphicIterator iterator, Xml::HElement layer)
//{
//		Xml::HElement pgChild = std::make_shared<Xml::Element>();
//		pgChild->setName("PlacedGraphic");
//		VG::Point p = iterator->getPlacementPoint();
//		pgChild->setAttribute("x", std::to_string(p.getX()));
//		pgChild->setAttribute("y", std::to_string(p.getY()));
//		layer->addChild(pgChild);
//
//		Xml::HElement vgChild = std::make_shared<Xml::Element>();
//		vgChild->setName("VectorGraphic");
//		VG::HVectorGraphic vg = iterator->getGraphic();
//		vgChild->setAttribute("closed", (vg->isClosed() == true ? "true" : "false"));
//		pgChild->addChild(vgChild);
//
//		int count = 0;
//		while (count < vg->getPointCount())
//		{
//			VG::Point childPoint = vg->getPoint(count);
//			Xml::HElement point = std::make_unique<Xml::Element>();
//			point->setName("Point");
//			point->setAttribute("x", std::to_string(childPoint.getX()));
//			point->setAttribute("y", std::to_string(childPoint.getY()));
//			vgChild->addChild(point);
//			count++;
//		}
//
//}
