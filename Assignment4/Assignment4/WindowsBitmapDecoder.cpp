#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream) :
		myMimeType("image/x-ms-bmp")
	{
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_unique<WindowsBitmapDecoder>(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		HBitmapIterator temp;
		return temp;
	}

	bool WindowsBitmapDecoder::isSupported()
	{
		return true;
	}
}
