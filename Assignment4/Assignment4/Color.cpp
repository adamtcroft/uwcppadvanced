#include "Color.h"

BitmapGraphics::Color::Color(uint8_t redInput, uint8_t greenInput, uint8_t blueInput) :
	red(redInput), green(greenInput), blue(blueInput)
{
}

const auto readByte = Binary::Byte::read;
BitmapGraphics::Color BitmapGraphics::Color::read(std::istream& iss)
{
	Color myColor;

	myColor.blue = readByte(iss);
	myColor.green = readByte(iss);
	myColor.red = readByte(iss);
	return myColor;
}

const uint8_t& BitmapGraphics::Color::getRed() const
{
	return red.getValue();
}

const uint8_t& BitmapGraphics::Color::getGreen() const
{
	return green.getValue();
}

const uint8_t& BitmapGraphics::Color::getBlue() const
{
	return blue.getValue();
}

bool BitmapGraphics::Color::operator==(const Color& rhs) const
{
	return (red == rhs.red) && (green == rhs.green) && (blue == rhs.blue);
}

bool BitmapGraphics::Color::operator!=(const Color& rhs) const
{
	return !(*this == rhs);
}
