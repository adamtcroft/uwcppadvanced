#include "WindowsBitmapHeader.h"

namespace BitmapGraphics
{
	const Binary::Byte WindowsBitmapHeader::firstIdentifier = Binary::Byte{ 'B' };
	const Binary::Byte WindowsBitmapHeader::secondIdentifier = Binary::Byte{ 'M' };
	const Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
	const Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 54;

	const Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;
	const Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
	const Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
	const Binary::DoubleWord WindowsBitmapHeader::compressionType = 0;
	const Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0;
	const Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0;
}

const auto readByte = Binary::Byte::read;
const auto readWord = Binary::Word::readLittleEndian;
const auto readDoubleWord = Binary::DoubleWord::readLittleEndian;
BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader(std::ifstream& bitmapStream)
{
	readFileHeader(bitmapStream);
	readInfoHeader(bitmapStream);
}

void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::istream& bitmapStream)
{
	auto firstID = readByte(bitmapStream);
	std::cout << firstID << " : " << firstIdentifier << std::endl;

	auto secondID = readByte(bitmapStream);
	std::cout << secondID << " : " << secondIdentifier << std::endl;

	fileSize = readDoubleWord(bitmapStream);
	std::cout << fileSize.getValue() << std::endl;

	auto temp_reserved = readDoubleWord(bitmapStream);
	std::cout << temp_reserved << " : " << reserved << std::endl;

	auto temp_rawImageByteOffset = readDoubleWord(bitmapStream);
	std::cout << temp_rawImageByteOffset << " : " << rawImageByteOffset << std::endl;
}

void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
{
	auto temp_infoHeaderBytes = readDoubleWord(bitmapStream);
	std::cout << temp_infoHeaderBytes << " : " << infoHeaderBytes << std::endl;

	bitmapWidth = readDoubleWord(bitmapStream);
	std::cout << "Width: " << bitmapWidth << std::endl;

	bitmapHeight = readDoubleWord(bitmapStream);
	std::cout << "Height: " << bitmapHeight << std::endl;

	auto temp_numPlanes = readWord(bitmapStream);
	std::cout << temp_numPlanes << " : " << numberOfPlanes << std::endl;

	auto temp_bitsPerPixel = readWord(bitmapStream);
	std::cout << temp_bitsPerPixel << " : " << bitsPerPixel << std::endl;

	auto temp_compressionType = readDoubleWord(bitmapStream);
	std::cout << "Compression Type: " << temp_compressionType << " : " << compressionType << std::endl;

	compressedImageSize = readDoubleWord(bitmapStream);
	std::cout << "Compressed Image Size: " << compressedImageSize << std::endl;

	horizontalPixelsPerMeter = readDoubleWord(bitmapStream);
	std::cout << "Horizontal PPM: " << horizontalPixelsPerMeter << std::endl;

	verticalPixelsPerMeter = readDoubleWord(bitmapStream);
	std::cout << "Vertical PPM: " << verticalPixelsPerMeter << std::endl;

	auto temp_numColors = readDoubleWord(bitmapStream);
	std::cout << "Number of Colors: " << temp_numColors << " : " << numberOfColors << std::endl;

	auto temp_numImpColors = readDoubleWord(bitmapStream);
	std::cout << "Number of Important Colors: " << temp_numImpColors << " : " << numberOfImportantColors << std::endl;

	std::cout << std::endl;
}

void BitmapGraphics::WindowsBitmapHeader::write(std::ofstream& bitmapStream)
{
	firstIdentifier.write(bitmapStream);
	secondIdentifier.write(bitmapStream);
	fileSize.write(bitmapStream);
	reserved.write(bitmapStream);
	rawImageByteOffset.write(bitmapStream);
	infoHeaderBytes.write(bitmapStream);
	bitmapWidth.write(bitmapStream);
	bitmapHeight.write(bitmapStream);
	numberOfPlanes.write(bitmapStream);
	bitsPerPixel.write(bitmapStream);
	compressionType.write(bitmapStream);
	compressedImageSize.write(bitmapStream);
	horizontalPixelsPerMeter.write(bitmapStream);
	verticalPixelsPerMeter.write(bitmapStream);
	numberOfColors.write(bitmapStream);
	numberOfImportantColors.write(bitmapStream);
}

Binary::DoubleWord const& BitmapGraphics::WindowsBitmapHeader::getFileSize() const
{
	return fileSize;
}

uint32_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
{
	return bitmapWidth.getValue();
}

uint32_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
{
	return bitmapHeight.getValue();
}
