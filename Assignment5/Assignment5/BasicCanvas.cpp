#include "BasicCanvas.h"

namespace BitmapGraphics
{
	BasicCanvas::BasicCanvas(int width, int height, Color const& background) :
		myWidth(width), myHeight(height), myBackground(background)
	{
		myBitmap.clearCollection();
		initializeCanvas();
	}

	void BasicCanvas::initializeCanvas()
	{
		for (auto row = 0; row < myHeight; ++row)
		{
			ScanLine scanline;
			scanline.reserve(myWidth);

			for (auto column = 0; column < myWidth; ++column)
			{
				scanline.push_back(myBackground);
			}

			myBitmap.push_back(scanline);
		}
	}

	bool BasicCanvas::inBounds(VG::Point const& location) const
	{
		if ((location.getX() > 0 && location.getX() <= myWidth) &&
			(location.getY() > 0 && location.getY() <= myHeight))
			return true;
		else
			return false;
	}

	void BasicCanvas::setPixelColor(VG::Point const& location, Color const& color)
	{
		if (inBounds(location))
			myBitmap.setPixelColor(location, color);
		else
			throw std::runtime_error("Can't set pixel out of bounds.");
	}

	Color BasicCanvas::getPixelColor(VG::Point const& location) const
	{
		if (inBounds(location))
			return myBitmap.getPixelColor(location);
		else
			throw std::runtime_error("Can't get pixel out of bounds.");
	}

	int BasicCanvas::getWidth() const
	{
		return myWidth;
	}

	int BasicCanvas::getHeight() const
	{
		return myHeight;
	}

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{
		if (myBitmap.getHeight() == 0 || myBitmap.getWidth() == 0)
			throw std::runtime_error("Error: Cannot return iterator if canvas has no size.");
		else
			return myBitmap.createIterator();
	}
}
