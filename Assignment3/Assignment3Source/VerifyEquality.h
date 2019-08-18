#pragma once
#include "Word.h"
#include <string>

class VerifyEquality
{
public:
	VerifyEquality() = delete;
	~VerifyEquality() = delete;

	static void verifyEquality(const Binary::Word& expected, const Binary::Word& actual, const std::string& error);
};

