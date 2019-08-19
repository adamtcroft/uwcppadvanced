#include "VerifyEquality.h"

void VerifyEquality::verifyEquality(const Binary::Byte& expected, const Binary::Byte& actual, const std::string& error)
{
	if (expected != actual)
	{
		throw std::runtime_error(error);
	}
}

void VerifyEquality::verifyEquality(const Binary::Word& expected, const Binary::Word& actual, const std::string& error)
{
	if (expected != actual)
	{
		throw std::runtime_error(error);
	}
}

void VerifyEquality::verifyEquality(const Binary::DoubleWord& expected, const Binary::DoubleWord& actual, const std::string& error)
{
	if (expected != actual)
	{
		throw std::runtime_error(error);
	}
}
