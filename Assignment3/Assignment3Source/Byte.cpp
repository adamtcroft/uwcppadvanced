#include "Byte.h"

Binary::Byte::Byte(uint8_t input) :
	value(input)
{

}

unsigned char Binary::Byte::read(std::stringstream& ss)
{
	char c;
	ss.get(c);
	return c;
}

void Binary::Byte::write(std::stringstream& ss)
{
	ss << value;
}
