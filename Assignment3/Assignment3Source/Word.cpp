#include "Word.h"

const auto readByte = Binary::Byte::read;
Binary::Word::Word(uint16_t input) :
	value(input)
{
}

Binary::Word Binary::Word::readLittleEndian(std::istream& ss)
{
	return _byteswap_ushort(static_cast<uint16_t>(readBigEndian(ss)));
}

Binary::Word Binary::Word::readBigEndian(std::istream& ss)
{
//	Binary::Word word;
//
//	for (auto byte = 0; byte != sizeof(Binary::Word); ++byte) {
//		char c = 0;
//		if (!ss.get(c)) {
//			throw(std::runtime_error("Attempt to read failed."));
//		}
//
//		typename Binary::Word tmp = static_cast<unsigned char>(c); // Otherwise sign extension occurs.
//		word |= tmp << (8 * byte);
//		// word |= static_cast<uint8_t>(c) << (8 * byte);
//	}

	//Binary::Word word{ static_cast<uint16_t>(readByte(ss).getValue() << 8 | readByte(ss).getValue()) };
	//ss.read(ss.rdbuf(), sizeof(Word));
	return static_cast<uint8_t>(readByte(ss)) << 8 | static_cast<uint8_t>(readByte(ss));
}

void Binary::Word::write(std::ostream& ss) const
{
	auto nonConst = const_cast<uint16_t*>(&value);
	auto valuePtr = reinterpret_cast<char*>(nonConst);
	ss.write((char*)(&value), sizeof(uint16_t));
}

bool Binary::Word::operator==(const Word& rhs) const
{
	return (value == rhs.value);
}

bool Binary::Word::operator!=(const Word& rhs) const
{
	return !(*this == rhs);
}

std::ostream& Binary::operator<<(std::ostream& output, const Word& rhs)
{
	output << rhs.getValue();
	return output;
}
