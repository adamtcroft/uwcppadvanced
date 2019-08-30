#include "BrightnessDecorator.h"


namespace BitmapGraphics
{
	BrightnessDecorator::BrightnessDecorator(HBitmapIterator const& iterator) :
		originalIterator(iterator)
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
		Color const originalColor = originalIterator->getColor();

		uint8_t red = originalColor.getRed() + brightnessAdjustment;
		if (red > 255) {
			red = 255;
		}
		else if (red < 0) {
			red = 0;
		}

		uint8_t green = originalColor.getGreen() + brightnessAdjustment;
		if (green > 255) {
			green = 255;
		}
		else if (green < 0) {
			red = 0;
		}

		uint8_t blue = originalColor.getBlue() + brightnessAdjustment;
		if (blue > 255) {
			blue = 255;
		}
		else if (blue < 0) {
			blue = 0;
		}

		Binary::Byte redByte(red);
		Binary::Byte greenByte(green);
		Binary::Byte blueByte(blue);

		return Color(redByte, greenByte, blueByte);
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
