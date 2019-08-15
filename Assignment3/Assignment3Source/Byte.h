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

		Byte& operator=(const Byte& other)
		{
			this->value = other.value;
			return *this;
		}
		Byte& operator=(Byte&& other)
		{
			this->value = value;
			return *this;
		}

		explicit operator uint8_t() const { return value; }

		~Byte() = default;

		static Byte read(std::istream& ss);
		void write(std::stringstream& ss);

		bool operator==(const char& rhs);
		bool operator!=(const char& rhs);

	private:
		uint8_t value;
	};

}

