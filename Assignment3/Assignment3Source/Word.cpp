#include "Word.h"

const auto readByte = Binary::Byte::read;
Binary::Word::Word(datatype input) :
	value(input)
{
}

void Binary::Word::write(std::ostream& ss) const
{
	auto nonConst = const_cast<datatype*>(&value);
	auto valuePtr = reinterpret_cast<char*>(nonConst);
	ss.write((char*)(&value), sizeof(datatype));
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
