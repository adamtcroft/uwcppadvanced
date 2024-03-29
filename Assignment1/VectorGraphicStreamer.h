#pragma once
#include <sstream>
#include <regex>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Parse.h"
#include "VectorGraphic.h"

namespace VG
{
	class VectorGraphicStreamer
	{
	public:
		VectorGraphicStreamer();
		VectorGraphicStreamer(const VectorGraphicStreamer& other) = delete;
		VectorGraphicStreamer(VectorGraphicStreamer&& other) = delete;
		VectorGraphicStreamer& operator=(const VectorGraphicStreamer& other) = delete;
		VectorGraphicStreamer& operator=(VectorGraphicStreamer&& other) = delete;
		~VectorGraphicStreamer();

		static VectorGraphic fromXml(std::stringstream& ss);
		static void toXml(VG::VectorGraphic& vg, std::ostream& ss);

	private:
		static void addPoint(std::string& point, VG::VectorGraphic& vg);
		static void addPoints(std::string& stream, VG::VectorGraphic& vg);
		static void setOpenOrClosed(std::string& stream, VG::VectorGraphic& vg);
		static bool isValidVG(std::string& stream);
		static std::vector<std::string> matchRegex(std::string& stream, std::regex& regex);
	};
}
