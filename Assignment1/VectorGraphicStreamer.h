#pragma once
#include <sstream>
#include <regex>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Parse.h"
#include "VectorGraphic.h"

namespace VG
{
	class VectorGraphicStreamer
	{
	public:
		VectorGraphicStreamer();
		~VectorGraphicStreamer();

		static VectorGraphic fromXml(std::stringstream& ss);
		static void toXml(VG::VectorGraphic& vg, std::stringstream& ss);

	private:
		static void addPoint(std::string& point, VG::VectorGraphic& vg);
		static void addPoints(std::string& stream, VG::VectorGraphic& vg);
		static void setOpenOrClosed(std::string& stream, VG::VectorGraphic& vg);
		static bool isValidVG(std::string& stream);
	};
}
