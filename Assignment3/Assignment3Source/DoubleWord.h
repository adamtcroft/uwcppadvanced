#pragma once
#include <cstdint>
#include <sstream>
#include "Word.h"

namespace Binary
{
	class DoubleWord
	{
	public:
		DoubleWord() = default;
		DoubleWord(uint32_t input);

		DoubleWord(const DoubleWord& other) = default;
		DoubleWord(DoubleWord&& other) = default;

		DoubleWord& operator=(const DoubleWord& other) = default;
		DoubleWord& operator=(DoubleWord&& other) = default;

		~DoubleWord() = default;

		static DoubleWord readLittleEndian(std::istream& ss);
		static DoubleWord readBigEndian(std::istream& ss);
		bool operator==(const DoubleWord& rhs) const;
		bool operator!=(const DoubleWord& rhs) const;

		const uint32_t& getValue() const
		{
			return value;
		}

		explicit operator uint32_t() const { return value; }

	private:
		uint32_t value;
	};

	std::ostream& operator<<(std::ostream& output, const DoubleWord& rhs);
}

