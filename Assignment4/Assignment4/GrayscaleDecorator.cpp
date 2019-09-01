#include "GrayscaleDecorator.h"

namespace BitmapGraphics
{
	GrayscaleDecorator::GrayscaleDecorator(HBitmapIterator const& iterator) :
		originalIterator(iterator)
	{
	}

	void GrayscaleDecorator::nextScanLine()
	{
		originalIterator->nextScanLine();
	}

	bool GrayscaleDecorator::isEndOfImage()
	{
		return originalIterator->isEndOfImage();
	}

	void GrayscaleDecorator::nextPixel()
	{
		originalIterator->nextPixel();
	}

	bool GrayscaleDecorator::isEndOfScanLine()
	{
		return originalIterator->isEndOfScanLine();
	}

	Color GrayscaleDecorator::getColor() const
	{
		Color const oldColor = originalIterator->getColor();

		int redValue = oldColor.getRed().getValue();
		int greenValue = oldColor.getGreen().getValue();
		int blueValue = oldColor.getBlue().getValue();

		auto grayValue = (redValue + greenValue + blueValue) / 3;

		Binary::Byte gray{ static_cast<uint8_t>(grayValue) };

		return Color(gray, gray, gray);
	}

	int GrayscaleDecorator::getBitmapWidth() const
	{
		return originalIterator->getBitmapWidth();
	}

	int GrayscaleDecorator::getBitmapHeight() const
	{
		return originalIterator->getBitmapHeight();
	}

	int GrayscaleDecorator::getBitmapFileSize() const
	{
		return originalIterator->getBitmapFileSize();
	}
}



