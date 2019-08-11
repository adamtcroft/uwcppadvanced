#pragma once
#include <cstdint>
#include <sstream>

namespace Binary
{
	class Byte
	{
	public:
		Byte();
		Byte(uint8_t c);

		Byte(const Byte& other) = default;
		Byte(Byte&& other) = default;

		Byte& operator=(const Byte& other) = default;
		Byte& operator=(Byte&& other) = default;

		operator uint8_t() const { return character; }

		~Byte();

		static uint8_t read(std::stringstream& ss);
		void write(std::stringstream& ss);

	private:
		uint8_t character;
	};
}

