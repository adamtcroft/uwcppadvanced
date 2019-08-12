#include "Word.h"


Binary::Word::Word()
{
}

Binary::Word::Word(uint16_t input) :
	value(input)
{
}

Binary::Word::~Word()
{
}

Binary::Word Binary::Word::readLittleEndian(std::stringstream& ss)
{
	return _byteswap_ushort(readBigEndian(ss));
}

const auto readByte = Binary::Byte::read;
Binary::Word Binary::Word::readBigEndian(std::stringstream& ss)
{
	return readByte(ss) << 8 | readByte(ss);
}

bool Binary::Word::operator==(const Word& rhs) const
{
	return (value == rhs.value);
}

bool Binary::Word::operator!=(const Word& rhs) const
{
	return !(*this == rhs);
}
