#include "Byte.h"

Binary::Byte::Byte(uint8_t input) :
	value(input)
{
}

const Binary::Byte Binary::Byte::read(std::istream& ss)
{
	char c;
	ss.get(c);
	Binary::Byte b;
	b = c;
	return b;
}

void Binary::Byte::write(std::ostream& ss) const
{
	ss << value;
}

bool Binary::operator==(const Byte& lhs, const Byte& rhs)
{
	return lhs.getValue() == rhs.getValue();
}

bool Binary::operator!=(const Byte& lhs, const Byte& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Binary::operator<<(std::ostream& output, const Byte& rhs)
{
	output << rhs.getValue();
	return output;
}

//bool Binary::Byte::operator==(const char& rhs)
//{
//	return value == rhs;
//}
//
//bool Binary::Byte::operator!=(const char& rhs)
//{
//	return !(value == rhs);
//}
