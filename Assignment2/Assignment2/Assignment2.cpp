// Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XmlReader.h"
#include "Scene.h"
#include "XmlWriter.h"
#include "SceneReader.h"
#include "SceneWriter.h";
#include <fstream>

int main()
{
	std::ifstream inputFile("scene.xml");
	std::stringstream xmlStream;

	xmlStream << inputFile.rdbuf();

	Xml::HElement root = Xml::Reader::loadXml(xmlStream);
    Framework::Scene scene = Framework::SceneReader::readScene(*root);
    Xml::HElement sceneRoot = Framework::SceneWriter::writeScene(scene);
	Xml::Writer::writeXml(sceneRoot, std::cout);

	inputFile.close();
    return 0;
}

