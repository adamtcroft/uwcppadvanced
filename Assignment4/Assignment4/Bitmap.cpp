#include "Bitmap.h"

BitmapGraphics::Bitmap::Bitmap(const uint32_t& width, const uint32_t& height, std::istream& sourceStream) :
	bitmapWidth(Binary::DoubleWord{ width }), bitmapHeight(Binary::DoubleWord{ height })
{
	read(sourceStream);
}

uint32_t BitmapGraphics::Bitmap::getNumberOfPadBytes() const
{
	const auto remainder = (bitmapWidth * 3) % 4;
	return (remainder == 0) ? 0 : (4 - remainder);
}

void BitmapGraphics::Bitmap::read(std::istream& sourceStream)
{
	slCollection.clear();
	
	for (auto row = 0; row < bitmapHeight; ++row)
	{
		ScanLine scanline;

		for (auto column = 0; column < bitmapWidth; ++column)
		{
			scanline.push_back(Color::read(sourceStream));
		}

		for (auto pad = 0; pad < getNumberOfPadBytes(); ++pad)
		{
			Binary::Byte::read(sourceStream);
		}

		slCollection.push_back(std::move(scanline));
	}
}

void BitmapGraphics::Bitmap::write(std::ostream& destinationStream)
{
	for (auto& scanline : slCollection)
	{
		for (auto& color : scanline)
		{
			// Write row of pixels
			std::copy(scanline.begin(), scanline.end(), binary_ostream_iterator<Color>(destinationStream));

			// Write pad bytes
			for (auto pad = 0; pad < getNumberOfPadBytes(); ++pad)
			{
				Binary::Byte(0).write(destinationStream);
			}
		}
	}
}
