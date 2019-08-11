#include "Byte.h"

Binary::Byte::Byte()
{
}

Binary::Byte::Byte(uint8_t c) :
	character(c)
{

}

Binary::Byte::~Byte()
{
}

uint8_t Binary::Byte::read(std::stringstream& ss)
{
	char c;
	ss.get(c);
	return c;
}

void Binary::Byte::write(std::stringstream& ss)
{
	ss << character;
}
