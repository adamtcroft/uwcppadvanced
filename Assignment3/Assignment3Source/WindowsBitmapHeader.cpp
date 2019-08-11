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


void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::ifstream& bitmapStream)
{

}

void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
{

}

size_t BitmapGraphics::WindowsBitmapHeader::getFileSize() const
{
	return 0;
}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
{
	return 0;
}

size_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
{

	return 0;
}
