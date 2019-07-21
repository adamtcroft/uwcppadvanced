#include "VectorGraphicStreamer.h"


VG::VectorGraphicStreamer::VectorGraphicStreamer()
{
}


VG::VectorGraphicStreamer::~VectorGraphicStreamer()
{
}


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

void VG::VectorGraphicStreamer::toXml(VG::VectorGraphic& vg, std::stringstream& ss)
{
	if (vg.isClosed())
	{
		std::string s = R"(<VectorGraphic closed="true">)";
		ss << s;
	}

	if (vg.isOpen())
	{
		std::string s = R"(<VectorGraphic closed="false">)";
		ss << s;
	}

	for (auto point : vg.getPath())
	{
		std::string p = R"(<Point x=")" + std::to_string(point.getX())
			+ R"(" y=")" + std::to_string(point.getY()) + R"(" />)";
		ss << p;
	}

	std::string s = "</VectorGraphic>";
	ss << s;

	std::ofstream outFile("myVG.xml");
	outFile << ss.rdbuf();
}

void VG::VectorGraphicStreamer::toXml(VG::VectorGraphic& vg)
{
	std::stringstream ss;
	toXml(vg, ss);
}

void VG::VectorGraphicStreamer::addPoint(std::string& point, VG::VectorGraphic& vg)
{
	int x, y;
	std::regex regex("[x-y]=\"\\d*\"");
	std::vector<std::string> results = matchRegex(point, regex);

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
	// Ran out of time - should check for closing tags too
	std::regex regex("<Point [x-y]=\\W*\\d*\\W* [x-y]=\\W*\\d*\\W*>");
	std::vector<std::string> results = matchRegex(stream, regex);

	for (std::string point : results)
	{
		addPoint(point, vg);
	}
}

void VG::VectorGraphicStreamer::setOpenOrClosed(std::string& stream, VG::VectorGraphic& vg)
{
	std::regex regex("<VectorGraphic closed=.*(true|false).*?>");
	std::vector<std::string> results = matchRegex(stream, regex);

	if (std::find(results.begin(), results.end(), "true") != results.end()
)
	{
		vg.closeShape();
	}

	if (std::find(results.begin(), results.end(), "false") != results.end())
	{
		vg.openShape();
	}
}

bool VG::VectorGraphicStreamer::isValidVG(std::string& stream)
{
	std::regex regex("\/*VectorGraphic");
	std::vector<std::string> results = matchRegex(stream, regex);

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

std::vector<std::string> VG::VectorGraphicStreamer::matchRegex(std::string& stream, std::regex& regex)
{
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

	return results;
}
