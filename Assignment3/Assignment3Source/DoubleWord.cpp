#include "DoubleWord.h"

Binary::DoubleWord::DoubleWord(uint32_t input) :
	value(input)
{
}

Binary::DoubleWord Binary::DoubleWord::readLittleEndian(std::stringstream& ss)
{
	return _byteswap_ulong(readBigEndian(ss));
}

const auto readWordBigEndian = Binary::Word::readBigEndian;
Binary::DoubleWord Binary::DoubleWord::readBigEndian(std::stringstream& ss)
{
	return readWordBigEndian(ss) << 16 | readWordBigEndian(ss);
}

bool Binary::DoubleWord::operator==(const DoubleWord& rhs) const
{
	return value == rhs.value;
}

bool Binary::DoubleWord::operator!=(const DoubleWord& rhs) const
{
	return !(*this == rhs);
}
