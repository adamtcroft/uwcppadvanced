#include "VectorGraphicStreamer.h"

VG::VectorGraphicStreamer::VectorGraphicStreamer()
{
}


VG::VectorGraphicStreamer::~VectorGraphicStreamer()
{
}

const std::string VectorGraphicXml = R"(
<VectorGraphic closed="true">
<Point x="0" y="0"/>
<Point x="10" y="0">
</Point>
<Point x="10" y="10"/>
<Point x="0" y="10"/>
</VectorGraphic>
)";

//NEEDS TO RETURN VG::VECTORGRAPHIC
VG::VectorGraphic VG::VectorGraphicStreamer::fromXml(std::stringstream& ss)
{
	VectorGraphic vg;
	std::string stream = ss.str();

	if (isValidVG(stream))
	{
		stream = ss.str();
		setOpenOrClosed(stream, vg);
		stream = ss.str();
		addPoints(stream, vg);
	}

	return vg;
}

void VG::VectorGraphicStreamer::addPoint(std::string& point, VG::VectorGraphic& vg)
{
	int x, y;
	std::regex regex("[x-y]=\"\\d*\"");
	std::smatch matches;
	std::vector<std::string> results;

	while (std::regex_search(point, matches, regex))
	{
		for (auto match : matches)
		{
			results.push_back(match);
		}
		point = matches.suffix().str();
	}

	for (auto result : results)
	{
		if (result[0] == 'x')
		{
			Parse::trim(result, "x=\"");
			x = std::stoi(result);
		}

		if (result[0] == 'y')
		{
			Parse::trim(result, "y=\"");
			y = std::stoi(result);
		}
	}

	vg.addPoint(VG::Point{ x, y });
}

void VG::VectorGraphicStreamer::addPoints(std::string& stream, VG::VectorGraphic& vg)
{
	// This does not check if a point is well-formed!!
	std::regex regex("<Point [x-y]=\"\\d*\" [x-y]=\"\\d*\"\/*>");
	std::smatch matches;
	std::vector<std::string> results;

	while (std::regex_search(stream, matches, regex))
	{
		for (auto match : matches)
		{
			results.push_back(match);
		}
		stream = matches.suffix().str();
	}

	for (std::string point : results)
	{
		addPoint(point, vg);
	}
}

void VG::VectorGraphicStreamer::setOpenOrClosed(std::string& stream, VG::VectorGraphic& vg)
{
	std::regex regex("closed=\"(true | false)\"");
	std::smatch matches;
	std::vector<std::string> results;

	while (std::regex_search(stream, matches, regex))
	{
		for (auto match : matches)
		{
			results.push_back(match);
		}
		stream = matches.suffix().str();
	}

	if (std::find(results.begin(), results.end(), "closed=\"true\"") != results.end())
	{
		vg.closeShape();
	}

	if (std::find(results.begin(), results.end(), "closed=\"false\"") != results.end())
	{
		vg.openShape();
	}
}

bool VG::VectorGraphicStreamer::isValidVG(std::string& stream)
{
	std::regex regex("\/*VectorGraphic");
	std::smatch matches;
	std::vector<std::string> results;

	while (std::regex_search(stream, matches, regex))
	{
		for (auto match : matches)
		{
			results.push_back(match);
		}
		stream = matches.suffix().str();
	}

	if (std::find(results.begin(), results.end(), "VectorGraphic") != results.end()
		&& std::find(results.begin(), results.end(), "/VectorGraphic") != results.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
