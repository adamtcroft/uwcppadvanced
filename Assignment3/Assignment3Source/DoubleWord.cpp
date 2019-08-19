#include "DoubleWord.h"

Binary::DoubleWord::DoubleWord(datatype input) :
	value(input)
{
}

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
