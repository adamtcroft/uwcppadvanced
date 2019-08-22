#include "Color.h"

BitmapGraphics::Color::Color(
	const Binary::Byte & redInput,
	const Binary::Byte & greenInput,
	const Binary::Byte & blueInput) noexcept :
	red(redInput), green(greenInput), blue(blueInput)
{
}

BitmapGraphics::Color BitmapGraphics::Color::read(std::istream& sourceStream)
{
	Color myColor;

	myColor.blue = Binary::Byte::read(sourceStream);
	myColor.green = Binary::Byte::read(sourceStream);
	myColor.red = Binary::Byte::read(sourceStream);
	return myColor;
}

void BitmapGraphics::Color::write(std::ostream& destinationStream) const
{
	blue.write(destinationStream);
	green.write(destinationStream);
	red.write(destinationStream);
}

bool BitmapGraphics::Color::operator==(const Color& rhs) const
{
	return (getRed() == rhs.getRed()) && (getGreen() == rhs.getGreen()) && getBlue() == rhs.getBlue();
}

bool BitmapGraphics::Color::operator!=(const Color& rhs) const
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const BitmapGraphics::Color& color)
{
	color.write(os);
	return os;
}
