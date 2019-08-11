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
	auto word = readBigEndian(ss);
	return _byteswap_ushort(word);
}

Binary::Word Binary::Word::readBigEndian(std::stringstream& ss)
{
	return ss.get() << 8 | ss.get();
}

bool Binary::Word::operator==(const Word& rhs) const
{
	return (value == rhs.value);
}

bool Binary::Word::operator!=(const Word& rhs) const
{
	return !(*this == rhs);
}
