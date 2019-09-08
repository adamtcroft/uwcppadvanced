#include "SquarePen.h"

namespace BitmapGraphics
{
	void SquarePen::drawPoint(const HCanvas& canvas, const VG::Point& point)
	{
		canvas->setPixelColor(point, Color(Binary::Byte(0), Binary::Byte(0), Binary::Byte(0)));
	}

	void SquarePen::drawPoint(VG::Point const& point)
	{

	}

	HPen SquarePen::clone()
	{
		return std::make_shared<SquarePen>();
	}
}
