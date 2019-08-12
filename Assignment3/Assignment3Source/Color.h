#pragma once
#include <cstdint>
#include <sstream>
#include "Byte.h";

namespace BitmapGraphics
{
	class Color
	{
	public:
		Color() = default;
		Color(uint8_t redInput, uint8_t greenInput, uint8_t blueInput);
		~Color() = default;

		static Color read(const std::istringstream& ss);
		uint8_t const& getRed() const;
		uint8_t const& getGreen() const;
		uint8_t const& getBlue() const;


	private:
		uint8_t red, green, blue;
	};
}

