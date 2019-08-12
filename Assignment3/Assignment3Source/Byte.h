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

		operator uint8_t() const { return value; }

		~Byte() = default;

		static unsigned char read(std::istream& ss);
		void write(std::stringstream& ss);

	private:
		uint8_t value;
	};
}

