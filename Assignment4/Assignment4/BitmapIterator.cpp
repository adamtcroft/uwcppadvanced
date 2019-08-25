#include "BitmapIterator.h"

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(Bitmap& bitmap) :
		myBitmap(&bitmap)
	{
		myWidth = myBitmap->getWidth();
		myHeight = myBitmap->getHeight();
		slIterator = myBitmap->begin();
	}

	void BitmapIterator::nextScanLine()
	{
	}


	bool BitmapIterator::isEndOfImage() const
	{
		return false;
	}

	void BitmapIterator::nextPixel()
	{
		slIterator++;
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
