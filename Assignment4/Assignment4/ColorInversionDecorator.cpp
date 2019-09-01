#include "ColorInversionDecorator.h"


namespace BitmapGraphics
{
	ColorInversionDecorator::ColorInversionDecorator(HBitmapIterator const& iterator) :
		originalIterator(iterator)
	{
	}

	void ColorInversionDecorator::nextScanLine()
	{
		originalIterator->nextScanLine();
	}

	bool ColorInversionDecorator::isEndOfImage()
	{
		return originalIterator->isEndOfImage();
	}

	void ColorInversionDecorator::nextPixel()
	{
		originalIterator->nextPixel();
	}

	bool ColorInversionDecorator::isEndOfScanLine()
	{
		return originalIterator->isEndOfScanLine();
	}

	Color ColorInversionDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		const int MAX_COLOR_VALUE{ 255 };

		return MAX_COLOR_VALUE - oldColor;
	}

	int ColorInversionDecorator::getBitmapWidth() const
	{
		return originalIterator->getBitmapWidth();
	}

	int ColorInversionDecorator::getBitmapHeight() const
	{
		return originalIterator->getBitmapHeight();
	}

	int ColorInversionDecorator::getBitmapFileSize() const
	{
		return originalIterator->getBitmapFileSize();
	}
}
