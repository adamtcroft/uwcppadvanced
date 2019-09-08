#include "StrokeFactory.h"

namespace BitmapGraphics
{
	StrokeFactory::StrokeFactory()
	{
		addStroke("square", std::make_shared<SquareStroke>());
		addStroke("slash", std::make_shared<SlashStroke>());
	}

	void StrokeFactory::addStroke(std::string const& tip, HStroke const& stroke)
	{
		myStrokes[tip] = stroke;
	}

	HStroke StrokeFactory::createStroke(std::string const& tip)
	{
		if (myStrokes[tip])
			return myStrokes[tip];
		else
			throw std::runtime_error("Pen type does not exist.");
	}
}
