#include "BasicCanvas.h"

namespace BitmapGraphics
{
	BasicCanvas::BasicCanvas(int width, int height, Color const& background) :
		myBitmap(width, height), myBackground(background)
	{
		myBitmap.clearCollection();
		initializeCanvas();
	}

	void BasicCanvas::initializeCanvas()
	{
		for (auto row = 0; row < myBitmap.getHeight(); ++row)
		{
			ScanLine scanline;
			scanline.reserve(myBitmap.getHeight());

			for (auto column = 0; column < myBitmap.getWidth(); ++column)
			{
				scanline.push_back(myBackground);
			}

			myBitmap.push_back(scanline);
		}
	}

	bool BasicCanvas::inBounds(VG::Point const& location) const
	{
		if ((location.getX() >= 0 && location.getX() <= myBitmap.getWidth()) &&
			(location.getY() >= 0 && location.getY() <= myBitmap.getHeight()))
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
		return myBitmap.getWidth();
	}

	int BasicCanvas::getHeight() const
	{
		return myBitmap.getHeight();
	}

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{
		if (myBitmap.getWidth() == 0 || myBitmap.getHeight() == 0)
			throw std::runtime_error("Error: Cannot return iterator if canvas has no size.");
		else
			myBitmap.flip();
			return myBitmap.createIterator();
	}
}
