#pragma once
#include <cstdint>
#include <sstream>
#include "Byte.h"

namespace BitmapGraphics
{
	class Color
	{
	public:
		Color() = default;
		Color(uint8_t redInput, uint8_t greenInput, uint8_t blueInput);
		~Color() = default;

		static Color read(std::istream& ss);
		const uint8_t& getRed() const;
		const uint8_t& getGreen() const;
		const uint8_t& getBlue() const;

		bool operator==(const Color& rhs) const;
		bool operator!=(const Color& rhs) const;

	private:
		Binary::Byte red, green, blue;
	};
}
