#include "Byte.h"

Binary::Byte::Byte(uint8_t input) :
	value(input)
{

}

unsigned char Binary::Byte::read(std::istream& ss)
{
	char c;
	ss.get(c);
	return c;
}

void Binary::Byte::write(std::stringstream& ss)
{
	ss << value;
}

bool Binary::Byte::operator==(const char& rhs)
{
	return value == rhs;
}

bool Binary::Byte::operator!=(const char& rhs)
{
	return !(value == rhs);
}
