#pragma once
#include <cstdint>
#include <sstream>
#include "Word.h"

namespace Binary
{
	class DoubleWord : public SizedWord<DoubleWord>
	{
	public:
		friend class SizedWord<DoubleWord>;
		using datatype = uint32_t;

		DoubleWord() = default;
		DoubleWord(datatype input);

		DoubleWord(const DoubleWord& other) = default;
		DoubleWord(DoubleWord&& other) = default;

		DoubleWord& operator=(const DoubleWord& other) = default;
		DoubleWord& operator=(DoubleWord&& other) = default;

		~DoubleWord() = default;

		void write(std::ostream& ss) const;

		bool operator==(const DoubleWord& rhs) const;
		bool operator!=(const DoubleWord& rhs) const;

		const unsigned long& getValue() const
		{
			return value;
		}

		explicit operator datatype() const { return value; }

	private:
		datatype value = 0;
	};

	std::ostream& operator<<(std::ostream& output, const DoubleWord& rhs);
}

