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
void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::ifstream& bitmapStream)
{
	firstIdentifier = readByte(bitmapStream);
	secondIdentifier = readByte(bitmapStream);
	fileSize = readDoubleWord(bitmapStream);
	auto temp_reserved = readDoubleWord(bitmapStream);
	rawImageByteOffset = readDoubleWord(bitmapStream);
	auto temp_infoHeaderBytes = readDoubleWord(bitmapStream);
	bitmapWidth = readDoubleWord(bitmapStream);
	bitmapHeight = readDoubleWord(bitmapStream);
	auto temp_numberOfPlanes = readWord(bitmapStream);
	bitsPerPixel = readWord(bitmapStream);
	compressionType = readDoubleWord(bitmapStream);
	compressedImageSize = readDoubleWord(bitmapStream);
	horizontalPixelsPerMeter = readDoubleWord(bitmapStream);
	numberOfColors = readDoubleWord(bitmapStream);
	numberOfImportantColors = readDoubleWord(bitmapStream);
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
