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
	Binary::Word word;

	for (auto byte = 0; byte != sizeof(Binary::Word); ++byte) {
		char c = 0;
		if (!ss.get(c)) {
			throw(std::runtime_error("Attempt to read failed."));
		}

		typename Binary::Word tmp = static_cast<unsigned char>(c); // Otherwise sign extension occurs.
		word |= tmp << (8 * byte);
		// word |= static_cast<uint8_t>(c) << (8 * byte);
	}

	//return readByte(ss) << 8 | readByte(ss);
}

bool Binary::Word::operator==(const Word& rhs) const
{
	return (value == rhs.value);
}

bool Binary::Word::operator!=(const Word& rhs) const
{
	return !(*this == rhs);
}
