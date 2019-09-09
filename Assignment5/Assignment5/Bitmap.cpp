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
		return std::make_shared<BitmapIterator>(BitmapIterator(*this));
	}

	void Bitmap::setPixelColor(VG::Point const& location, Color const& color)
	{
		std::cout << "slCollection size: " << slCollection.size() << std::endl;
		std::cout << "getY: " << location.getY() << std::endl;
		slCollection[location.getX()][location.getY()] = color;
	}

	void Bitmap::flip()
	{
		std::reverse(slCollection.begin(), slCollection.end());
	}
}
