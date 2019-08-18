#pragma once
#include <cstdint>
#include <sstream>

namespace Binary
{
	class Byte
	{
	public:
		Byte() = default;
		Byte(uint8_t input);

		Byte(const Byte& other) = default;
		Byte(Byte&& other) = default;

		Byte& operator=(const Byte& other) = default;
		Byte& operator=(Byte&& other) = default;

		explicit operator uint8_t() const { return value; }

		~Byte() = default;

		const static Byte read(std::istream& ss);
		void write(std::ostream& ss) const;
		const uint8_t& getValue() const
		{
			return value;
		}

		//bool operator==(const char& rhs);
		//bool operator!=(const char& rhs);

	private:
		uint8_t value;
	};

	bool operator==(const Byte& lhs, const Byte& rhs);
	bool operator!=(const Byte& lhs, const Byte& rhs);
	std::ostream& operator<<(std::ostream& output, const Byte& rhs);
}

