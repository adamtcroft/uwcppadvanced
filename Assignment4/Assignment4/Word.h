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
		using datatype = uint16_t;

		Word() = default;
		Word(datatype input);

		Word(const Word& other) = default;
		Word(Word&& other) = default;

		Word& operator=(const Word& other) = default;
		Word& operator=(Word&& other) = default;

		~Word() = default;

		void write(std::ostream& ss) const;

		bool operator==(const Word& rhs) const;
		bool operator!=(const Word& rhs) const;

		const datatype& getValue() const
		{
			return value;
		}

		explicit operator datatype() const { return value; }

	private:
		datatype value = 0;
	};

	std::ostream& operator<<(std::ostream& output, const Word& rhs);
}

