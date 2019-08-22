#include "Bitmap.h"

auto const readByte = Binary::Byte::read;
BitmapGraphics::Bitmap::Bitmap(const uint32_t& width, const uint32_t& height, std::ifstream& bitmapStream) :
	bitmapWidth(Binary::DoubleWord{ width }), bitmapHeight(Binary::DoubleWord{ height })
{
	while (!(bitmapStream.eof()))
	{
		auto lineSize = width;
		ScanLine sLine;
		while (lineSize > 0)
		{
			auto blue = readByte(bitmapStream).getValue();
			auto green = readByte(bitmapStream).getValue();
			auto red = readByte(bitmapStream).getValue();
			Color pixel{ red, green, blue };
			sLine.push_back(pixel);
			lineSize--;
		}
		slCollection.push_back(sLine);
	}
	slCollection.erase(slCollection.end() - 1);

	//	while (!(bitmapStream.eof()))
	//	{
	//		auto blue = readByte(bitmapStream).getValue();
	//		auto green = readByte(bitmapStream).getValue();
	//		auto red = readByte(bitmapStream).getValue();
	//		Color pixel{ red, green, blue };
	//	}
}

BitmapGraphics::Bitmap::ScanLineIterator BitmapGraphics::Bitmap::begin()
{
	return slCollection.begin();
}

BitmapGraphics::Bitmap::ScanLineIterator BitmapGraphics::Bitmap::end()
{
	return slCollection.end();
}

void BitmapGraphics::Bitmap::write(std::ofstream& bitmapStream)
{
	for (auto& scanline : slCollection)
	{
		for (auto& color : scanline)
		{
			bitmapStream << color.getBlue();
			bitmapStream << color.getGreen();
			bitmapStream << color.getRed();
		}
	}
}

const uint32_t& BitmapGraphics::Bitmap::getWidth() const
{
	return bitmapWidth.getValue();
}

const uint32_t& BitmapGraphics::Bitmap::getHeight() const
{
	return bitmapHeight.getValue();
}
