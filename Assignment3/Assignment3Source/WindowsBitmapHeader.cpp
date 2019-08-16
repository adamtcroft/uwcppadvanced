//#include "WindowsBitmapHeader.h"
//
//namespace BitmapGraphics
//{
//	const Binary::Byte WindowsBitmapHeader::firstIdentifier = Binary::Byte{ 'B' };
//	const Binary::Byte WindowsBitmapHeader::secondIdentifier = Binary::Byte{ 'M' };
//	const Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
//
//	const Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;
//	const Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
//	const Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
//}
//
//const auto readByte = Binary::Byte::read;
//const auto readWord = Binary::Word::readLittleEndian;
//const auto readDoubleWord = Binary::DoubleWord::readLittleEndian;
//BitmapGraphics::WindowsBitmapHeader::WindowsBitmapHeader(std::ifstream& bitmapStream)
//{
//	readFileHeader(bitmapStream);
//}
//
//void BitmapGraphics::WindowsBitmapHeader::readFileHeader(std::istream& bitmapStream)
//{
////	std::stringstream ss;
////	firstIdentifier.write(ss);
////	std::cout << ss.str() << std::endl;
////	std::stringstream ss2;
////	auto b = readByte(bitmapStream);
////	b.write(ss2);
////	std::cout << ss2.str() << std::endl;
//}
//
//void BitmapGraphics::WindowsBitmapHeader::readInfoHeader(std::ifstream& bitmapStream)
//{
//}
//
////Binary::DoubleWord const& BitmapGraphics::WindowsBitmapHeader::getFileSize() const
////{
////	return fileSize;
////}
//
//size_t BitmapGraphics::WindowsBitmapHeader::getBitmapWidth() const
//{
//	return 0;
//}
//
//size_t BitmapGraphics::WindowsBitmapHeader::getBitmapHeight() const
//{
//
//	return 0;
//}
