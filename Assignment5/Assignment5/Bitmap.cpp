#include "Bitmap.h"
#include "BitmapIterator.h"

namespace BitmapGraphics
{
	Bitmap::Bitmap(const uint32_t& width, const uint32_t& height) :
		bitmapWidth(width), bitmapHeight(height)
	{
	}

	HBitmapIterator Bitmap::createIterator()
	{
		auto pBitmapIterator = std::make_shared<BitmapIterator>(BitmapIterator(*this));
		return pBitmapIterator;
	}

	void Bitmap::setPixelColor(VG::Point const& location, Color const& color)
	{
		slCollection[location.getX()][location.getY()] = color;
	}
}
