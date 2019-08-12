#include "Color.h"


BitmapGraphics::Color::Color(uint8_t redInput, uint8_t greenInput, uint8_t blueInput) :
	red(redInput), green(greenInput), blue(blueInput)
{
}

const auto readByte = Binary::Byte::read;
BitmapGraphics::Color BitmapGraphics::Color::read(const std::istringstream& iss)
{
	std::stringstream ss(iss.str());
	Color myColor;
	myColor.blue = readByte(ss);
	myColor.green = readByte(ss);
	myColor.red = readByte(ss);
	return myColor;
}

uint8_t const& BitmapGraphics::Color::getRed() const
{
	return red;
}

uint8_t const& BitmapGraphics::Color::getGreen() const
{
	return green;
}

uint8_t const& BitmapGraphics::Color::getBlue() const
{
	return blue;
}
