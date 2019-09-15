#include "BasicCanvasBitmapIterator.h"

namespace BitmapGraphics
{

	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(BasicCanvas& canvas) :
		myCanvas(&canvas)
	{
	}

	void BasicCanvasBitmapIterator::nextScanLine()
	{
		++myY;
		myX = 0;
	}

	bool BasicCanvasBitmapIterator::isEndOfImage()
	{
		if (myY >= myCanvas->getHeight())
			return true;
		else
			return false;
	}

	void BasicCanvasBitmapIterator::nextPixel()
	{
		if (myX < myCanvas->getWidth())
			++myX;
		else
		{
			nextScanLine();
		}
	}

	bool BasicCanvasBitmapIterator::isEndOfScanLine()
	{
		if (myX >= myCanvas->getWidth())
			return true;
		else
			return false;
	}

	BitmapGraphics::Color BasicCanvasBitmapIterator::getColor() const
	{
		return myCanvas->getPixelColor(VG::Point{ myX, myY });
	}

	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return myCanvas->getWidth();
	}

	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return myCanvas->getHeight();
	}
}
