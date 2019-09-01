#include "BrightnessDecorator.h"
#include <algorithm>

namespace BitmapGraphics
{
	BrightnessDecorator::BrightnessDecorator(HBitmapIterator const& iterator, int adjustment) :
		originalIterator(iterator), brightnessAdjustment(adjustment)
	{
	}

	void BrightnessDecorator::setBrightnessAdjustment(int adjustment)
	{
		brightnessAdjustment = adjustment;
	}

	int BrightnessDecorator::getBrightnessAdjustment()
	{
		return brightnessAdjustment;
	}

	void BrightnessDecorator::nextScanLine()
	{
		originalIterator->nextScanLine();
	}

	bool BrightnessDecorator::isEndOfImage()
	{
		return originalIterator->isEndOfImage();
	}

	void BrightnessDecorator::nextPixel()
	{
		originalIterator->nextPixel();
	}

	bool BrightnessDecorator::isEndOfScanLine()
	{
		return originalIterator->isEndOfScanLine();
	}

	Color BrightnessDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		return oldColor + brightnessAdjustment;
	}

	int BrightnessDecorator::getBitmapWidth() const
	{
		return originalIterator->getBitmapWidth();
	}

	int BrightnessDecorator::getBitmapHeight() const
	{
		return originalIterator->getBitmapHeight();
	}

	int BrightnessDecorator::getBitmapFileSize() const
	{
		return originalIterator->getBitmapFileSize();
	}
}
