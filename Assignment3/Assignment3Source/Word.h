#pragma once
#include <cstdint>
#include <sstream>
#include "Byte.h"

namespace Binary
{
	class Word
	{
	public:
		Word() = default;
		Word(uint16_t input);

		Word(const Word& other) = default;
		Word(Word&& other) = default;

		Word& operator=(const Word& other) = default;
		Word& operator=(Word&& other) = default;

		~Word() = default;

		static Word readLittleEndian(std::istream& ss);
		static Word readBigEndian(std::istream& ss);
		bool operator==(const Word& rhs) const;
		bool operator!=(const Word& rhs) const;

		explicit operator uint16_t() const { return value; }

	private:
		uint16_t value;
	};
}

