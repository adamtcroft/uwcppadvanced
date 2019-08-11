#pragma once
#include <cstdint>
#include <sstream>
#include "Byte.h"

namespace Binary
{
	class Word
	{
	public:
		Word();
		Word(uint16_t input);
		~Word();

		static Word readLittleEndian(std::stringstream& ss);
		static Word readBigEndian(std::stringstream& ss);
		bool operator==(const Word& rhs) const;
		bool operator!=(const Word& rhs) const;

		operator uint16_t() const { return value; }

	private:
		uint16_t value;
	};
}

