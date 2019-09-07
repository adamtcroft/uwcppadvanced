#include "BasicCanvas.h"

namespace BitmapGraphics
{
	BasicCanvas::BasicCanvas(int width, int height, Color const& background) :
		myWidth(width), myHeight(height), myBackground(background)
	{
		myCollection.reserve(myHeight);
		initializeCanvas();
	}

	void BasicCanvas::initializeCanvas()
	{
		for (auto row = 0; row < myHeight; ++row)
		{
			ScanLine scanline;

			for (auto column = 0; column < myWidth; ++column)
			{
				scanline.push_back(myBackground);
			}

			myCollection.push_back(scanline);
		}
	}

	void BasicCanvas::setPixelColor(VG::Point const& location, Color const& color)
	{
		auto row = myCollection.at(location.getX());
		row.at(location.getY()) = color;
	}

	BitmapGraphics::Color BasicCanvas::getPixelColor(VG::Point const& location) const
	{
		return myCollection.at(location.getX()).at(location.getY());
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
