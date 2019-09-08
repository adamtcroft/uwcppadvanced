#include "SquarePen.h"

namespace BitmapGraphics
{
	void SquarePen::drawPoint(const HCanvas&, const VG::Point&)
	{

	}

	void SquarePen::drawPoint(VG::Point const& point)
	{

	}

	HPen SquarePen::clone()
	{
		return std::make_shared<SquarePen>();
	}
}
