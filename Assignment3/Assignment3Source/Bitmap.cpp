#include "Bitmap.h"

BitmapGraphics::Bitmap::Bitmap(const uint32_t& width, const uint32_t& height, std::ifstream& bitmapStream) :
	bitmapWidth(Binary::DoubleWord{ width }), bitmapHeight(Binary::DoubleWord{ height })
{

}

const uint32_t& BitmapGraphics::Bitmap::getWidth() const
{
	return bitmapWidth.getValue();
}

const uint32_t& BitmapGraphics::Bitmap::getHeight() const
{
	return bitmapHeight.getValue();
}
