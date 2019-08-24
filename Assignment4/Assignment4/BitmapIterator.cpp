#include "BitmapIterator.h"

namespace BitmapGraphics
{

	BitmapIterator::BitmapIterator(uint32_t width, uint32_t height) :
		myWidth(width), myHeight(height)
	{

	}
	void BitmapIterator::nextScanLine()
	{

	}


	bool BitmapIterator::isEndOfImage() const
	{
		return true;
	}

	void BitmapIterator::nextPixel()
	{

	}

	bool BitmapIterator::isEndOfScanLine()
	{
		return true;
	}

	BitmapGraphics::Color BitmapIterator::getColor() const
	{
		BitmapGraphics::Color newColor;
		return newColor;
	}
}
