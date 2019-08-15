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
		Color(Binary::Byte& redInput, Binary::Byte& greenInput, Binary::Byte& blueInput);
		~Color() = default;

		static Color read(std::istream& ss);
		Binary::Byte const& getRed() const;
		Binary::Byte const& getGreen() const;
		Binary::Byte const& getBlue() const;

		bool operator==(const Color& rhs) const;
		bool operator!=(const Color& rhs) const;

	private:
		Binary::Byte red, green, blue;
	};
}

