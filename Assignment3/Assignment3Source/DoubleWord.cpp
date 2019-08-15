#include "DoubleWord.h"

//Binary::DoubleWord::DoubleWord(uint32_t input) :
//	value(input)
//{
//}
//
//Binary::DoubleWord Binary::DoubleWord::readLittleEndian(std::istream& ss)
//{
//	return _byteswap_ulong(static_cast<uint32_t>(readBigEndian(ss)));
//}
//
//const auto readWordBigEndian = Binary::Word::readBigEndian;
//Binary::DoubleWord Binary::DoubleWord::readBigEndian(std::istream& ss)
//{
//	return static_cast<uint16_t>(readWordBigEndian(ss)) << 16 | static_cast<uint16_t>(readWordBigEndian(ss));
//}
//
//bool Binary::DoubleWord::operator==(const DoubleWord& rhs) const
//{
//	return value == rhs.value;
//}
//
//bool Binary::DoubleWord::operator!=(const DoubleWord& rhs) const
//{
//	return !(*this == rhs);
//}
