#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream)
	{
		if (!isSupported(sourceStream))
			throw std::runtime_error("File Type Not Supported.");
		else
		{
			myBitmapHeader.read(sourceStream);
		}
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_unique<WindowsBitmapDecoder>(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		return std::make_unique<BitmapIterator>(myBitmapHeader.getBitmapWidth(), myBitmapHeader.getBitmapHeight());
	}

	bool WindowsBitmapDecoder::isSupported(std::istream& sourceStream)
	{
		std::string first100(100, ' ');
		sourceStream.read(&first100[0], 100);
		sourceStream.seekg(0);

		if (first100.substr(0, 2) == "BM")
		{
			myMimeType = "image/x-ms-bmp";
			return true;
		}
		else
		{
			return false;
		}

	}
}
