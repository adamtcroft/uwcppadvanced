// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include "VectorGraphicStreamer.h"
#include "VectorGraphic.h"


int main()
{
	std::ifstream in("VectorGraphic.xml");
	std::stringstream stream;
	stream << in.rdbuf();

	auto vg = VG::VectorGraphicStreamer::fromXml(stream);
	VG::VectorGraphicStreamer::toXml(vg);

	return 0;
}

