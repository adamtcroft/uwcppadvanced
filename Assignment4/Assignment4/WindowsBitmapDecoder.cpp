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
			Bitmap localBitmap{ myBitmapHeader.getBitmapWidth(), myBitmapHeader.getBitmapHeight() };
			myBitmap = localBitmap;

			myBitmap.clearCollection();

			for (auto row = 0; row < myBitmap.getHeight(); ++row)
			{
				std::vector<Color> scanline;

				for (auto column = 0; column < myBitmap.getWidth(); ++column)
				{
					scanline.push_back(Color::read(sourceStream));
				}

				for (auto pad = 0; pad < myBitmap.getNumberOfPadBytes(); ++pad)
				{
					Binary::Byte::read(sourceStream);
				}

				myBitmap.push_back(std::move(scanline));
			}
		}
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_unique<WindowsBitmapDecoder>(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		return myBitmap.createIterator();
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
