//#include "WindowsBitmapHeader.h"
//
//namespace BitmapGraphics
//{
//	const Binary::Byte WindowsBitmapHeader::firstIdentifier = Binary::Byte{ 'B' };
//	const Binary::Byte WindowsBitmapHeader::secondIdentifier = Binary::Byte{ 'M' };
//	const Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
//	const Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 54;
//
//	const Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;
//	const Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
//	const Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
//	const Binary::DoubleWord WindowsBitmapHeader::compressionType = 0;
//	const Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0;
//	const Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0;
//}
//
//const auto readByte = Binary::Byte::read;
//const auto readWord = Binary::Word::readLittleEndian;
//const auto readDoubleWord = Binary::DoubleWord::readLittleEndian;
//BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader(std::ifstream& bitmapStream)
//{
//	readFileHeader(bitmapStream);
//	readInfoHeader(bitmapStream);
//}
//
//void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::istream& bitmapStream)
//{
//	VerifyEquality::verifyEquality(firstIdentifier, readByte(bitmapStream), "firstIdentifier does not match 'B'");
//	VerifyEquality::verifyEquality(secondIdentifier, readByte(bitmapStream), "secondIdentifier does not match 'B'");
//
//	fileSize = readDoubleWord(bitmapStream);
//
//	VerifyEquality::verifyEquality(reserved, readDoubleWord(bitmapStream), "reserved does not match '0'");
//	VerifyEquality::verifyEquality(rawImageByteOffset, readDoubleWord(bitmapStream), "rawImageByteOffset does not match '54'");
//}
//
//void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
//{
//	VerifyEquality::verifyEquality(infoHeaderBytes, readDoubleWord(bitmapStream), "infoHeaderBytes does not match '40'");
//
//	bitmapWidth = readDoubleWord(bitmapStream);
//	bitmapHeight = readDoubleWord(bitmapStream);
//
//	VerifyEquality::verifyEquality(numberOfPlanes, readWord(bitmapStream), "numberOfPlanes does not match '1'");
//	VerifyEquality::verifyEquality(bitsPerPixel, readWord(bitmapStream), "bitsPerPixel does not match '24'");
//	VerifyEquality::verifyEquality(compressionType, readDoubleWord(bitmapStream), "compressionType does not match '0'");
//
//	compressedImageSize = readDoubleWord(bitmapStream);
//	horizontalPixelsPerMeter = readDoubleWord(bitmapStream);
//	verticalPixelsPerMeter = readDoubleWord(bitmapStream);
//
//	VerifyEquality::verifyEquality(numberOfColors, readDoubleWord(bitmapStream), "numberOfColors does not match '0'");
//	VerifyEquality::verifyEquality(numberOfImportantColors, readDoubleWord(bitmapStream), "numberOfImportantColors does not match '0'");
//}
//
//void BitmapGraphics::WindowsBitmapHeader::write(std::ofstream& bitmapStream)
//{
//	firstIdentifier.write(bitmapStream);
//	secondIdentifier.write(bitmapStream);
//	fileSize.write(bitmapStream);
//	reserved.write(bitmapStream);
//	rawImageByteOffset.write(bitmapStream);
//	infoHeaderBytes.write(bitmapStream);
//	bitmapWidth.write(bitmapStream);
//	bitmapHeight.write(bitmapStream);
//	numberOfPlanes.write(bitmapStream);
//	bitsPerPixel.write(bitmapStream);
//	compressionType.write(bitmapStream);
//	compressedImageSize.write(bitmapStream);
//	horizontalPixelsPerMeter.write(bitmapStream);
//	verticalPixelsPerMeter.write(bitmapStream);
//	numberOfColors.write(bitmapStream);
//	numberOfImportantColors.write(bitmapStream);
//}
//
//Binary::DoubleWord const& BitmapGraphics::WindowsBitmapHeader::getFileSize() const
//{
//	return fileSize;
//}
//
//uint32_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
//{
//	return bitmapWidth.getValue();
//}
//
//uint32_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
//{
//	return bitmapHeight.getValue();
//}
