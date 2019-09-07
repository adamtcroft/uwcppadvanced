#include "BasicCanvas.h"

namespace VG
{
	void BasicCanvas::setPixelColor(Point const& location, BitmapGraphics::Color const& color)
	{

	}

	BitmapGraphics::Color BasicCanvas::getPixelColor(Point const& location) const
	{
		BitmapGraphics::Color temp;
		return temp;
	}
	
	int BasicCanvas::getWidth() const
	{
		return 1;
	}

	int BasicCanvas::getHeight() const
	{
		return 1;
	}
	
	BitmapGraphics::HBitmapIterator BasicCanvas::createBitmapIterator() const
	{
		BitmapGraphics::HBitmapIterator temp;
		return temp;
	}
}
