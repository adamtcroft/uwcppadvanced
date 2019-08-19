#include "DoubleWord.h"

//const auto readWordBigEndian = Binary::Word::readBigEndian;
Binary::DoubleWord::DoubleWord(uint32_t input) :
	value(input)
{
}

//Binary::DoubleWord Binary::DoubleWord::readLittleEndian(std::istream& ss)
//{
//	return _byteswap_ulong(static_cast<uint32_t>(readBigEndian(ss)));
//}

//Binary::DoubleWord Binary::DoubleWord::readBigEndian(std::istream& ss)
//{
//	return static_cast<uint16_t>(readWordBigEndian(ss)) << 16 | static_cast<uint16_t>(readWordBigEndian(ss));
//}

void Binary::DoubleWord::write(std::ostream& ss) const
{
	auto nonConst = const_cast<uint32_t*>(&value);
	auto valuePtr = reinterpret_cast<char*>(nonConst);
	ss.write(valuePtr, sizeof(uint32_t));
}

bool Binary::DoubleWord::operator==(const DoubleWord& rhs) const
{
	return value == rhs.value;
}

bool Binary::DoubleWord::operator!=(const DoubleWord& rhs) const
{
	return !(*this == rhs);
}

std::ostream& Binary::operator<<(std::ostream& output, const DoubleWord& rhs)
{
	output << rhs.getValue();
	return output;
}
