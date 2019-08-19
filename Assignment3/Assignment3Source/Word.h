#pragma once
#include <cstdint>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Byte.h"
#include "SizedWord.h"

namespace Binary
{
	class Word : public SizedWord<Word>
	{
	public:
		friend class SizedWord<Word>;
		Word() = default;
		Word(uint16_t input);

		Word(const Word& other) = default;
		Word(Word&& other) = default;

		Word& operator=(const Word& other) = default;
		Word& operator=(Word&& other) = default;

		~Word() = default;

		void write(std::ostream& ss) const;

		bool operator==(const Word& rhs) const;
		bool operator!=(const Word& rhs) const;

		const uint16_t& getValue() const
		{
			return value;
		}

		explicit operator uint16_t() const { return value; }

		using datatype = uint16_t;

	private:
		datatype value = 0;
	};

	std::ostream& operator<<(std::ostream& output, const Word& rhs);
}

