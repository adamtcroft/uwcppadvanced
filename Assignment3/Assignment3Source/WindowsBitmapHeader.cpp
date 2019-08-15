#include "WindowsBitmapHeader.h"

const auto readByte = Binary::Byte::read;
const auto readWord = Binary::Word::readLittleEndian;
const auto readDoubleWord = Binary::DoubleWord::readLittleEndian;
BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader(std::ifstream& bitmapStream)
{
	BitmapGraphics::WindowsBitmapHeader::firstIdentifier = readByte(bitmapStream);
	BitmapGraphics::WindowsBitmapHeader::secondIdentifier = readByte(bitmapStream);
	readFileHeader(bitmapStream);
}

void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::istream& bitmapStream)
{
}

void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
{
}

//Binary::DoubleWord const& BitmapGraphics::WindowsBitmapHeader::getFileSize() const
//{
//	return fileSize;
//}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
{
	return 0;
}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
{

	return 0;
}
