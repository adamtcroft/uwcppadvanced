#include "PenFactory.h"

namespace BitmapGraphics
{
	PenFactory::PenFactory()
	{
		addPen("square", std::make_shared<SquarePen>());
	}

	void PenFactory::addPen(std::string const& tip, HPen const& pen)
	{
		myPens[tip] = pen;
	}

	HPen PenFactory::createPen(std::string const& tip)
	{
		if (myPens[tip])
			return myPens[tip];
		else
			throw std::runtime_error("Pen type does not exist.");
	}
}
