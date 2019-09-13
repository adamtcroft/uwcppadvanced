#include "SquarePen.h"

namespace BitmapGraphics
{
	void SquarePen::drawPoint(const HCanvas& canvas, const VG::Point& point)
	{
		//canvas->setPixelColor(point, myStroke->getColor());
		canvas->setPixelColor(point, Color(Binary::Byte(0), Binary::Byte(255), Binary::Byte(0)));
	}

	void SquarePen::drawPoint(VG::Point const& point)
	{

	}
}
