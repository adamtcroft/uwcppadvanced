#include "WindowsBitmapHeader.h"

BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader()
{
}

BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader(std::ifstream& bitmapStream)
{
	readFileHeader(bitmapStream);
}

BitmapGraphics::WindowsBitmapHeader::~WindowsBitmapHeader()
{
}


const auto readByte = Binary::Byte::read;
const auto readWord = Binary::Word::readLittleEndian;
const auto readDoubleWord = Binary::DoubleWord::readLittleEndian;
void BitmapGraphics::WindowsBitmapHeader::readFileHeader(const std::ifstream& bitmapStream)
{
}

void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
{

}

Binary::DoubleWord const& BitmapGraphics::WindowsBitmapHeader::getFileSize() const
{
	return fileSize;
}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
{
	return 0;
}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
{

	return 0;
}
