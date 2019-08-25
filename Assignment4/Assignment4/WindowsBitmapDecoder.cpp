#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream)
	{
		//if (!isSupported(sourceStream))
		//	throw std::runtime_error("File Type Not Supported.");
		//else
		//{
		sourceStream.seekg(0, std::ios_base::end);
		if (sourceStream.tellg() == 0)
			return;
		else
		{
			sourceStream.seekg(0);
			WindowsBitmapHeader header;
			header.read(sourceStream);
			Bitmap localBitmap{ header.getBitmapWidth(), header.getBitmapHeight() };
			myBitmap = localBitmap;

			myBitmap.clearCollection();

			for (auto row = 0; row < myBitmap.getHeight(); ++row)
			{
				std::vector<Color> scanline;

				for (auto column = 0; column < myBitmap.getWidth(); ++column)
				{
					scanline.push_back(Color::read(sourceStream));
				}

				for (auto pad = 0; pad < calculatePadBytes(); ++pad)
				{
					Binary::Byte::read(sourceStream);
				}

				myBitmap.push_back(std::move(scanline));
			}
		}

		//}
	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return std::make_unique<WindowsBitmapDecoder>(sourceStream);
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		if (myBitmap.getHeight() == 0 || myBitmap.getWidth() == 0 || myMimeType == "")
			throw std::runtime_error("Error: Cannot return iterator if no bitmap has been decoded.");
		else
			return myBitmap.createIterator();
	}

	bool WindowsBitmapDecoder::isSupported(std::istream& sourceStream)
	{
		std::string first100(100, ' ');
		sourceStream.read(&first100[0], 100);
		sourceStream.seekg(0);

		if (first100.substr(0, 2) == "BM")
			return true;
		else
			return false;
	}

	uint32_t WindowsBitmapDecoder::calculatePadBytes()
	{
		const auto remainder = (myBitmap.getWidth() * 3) % 4;
		return (remainder == 0) ? 0 : (4 - remainder);
	}
}
