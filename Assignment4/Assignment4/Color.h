#pragma once
#include <cstdint>
#include <sstream>
#include "SizedWord.h"

namespace BitmapGraphics
{
	class Color
	{
	public:
		explicit Color(
			const Binary::Byte& redInput = Binary::Byte(0),
			const Binary::Byte& greenInput = Binary::Byte(0),
			const Binary::Byte& blueInput = Binary::Byte(0)) noexcept;

		Color(const Color&) noexcept = default;
		Color(Color &&) noexcept  = default;

		Color& operator=(const Color&) = default;
		Color& operator=(Color&&) = default;

		~Color() noexcept = default;

		static Color read(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;

		Binary::Byte getRed() const noexcept { return red; };
		Binary::Byte getGreen() const noexcept { return green; };
		Binary::Byte getBlue() const noexcept { return blue; };

		bool operator==(const Color& rhs) const;
		bool operator!=(const Color& rhs) const;

	private:
		Binary::Byte red{ 0 };
		Binary::Byte green{ 0 };
		Binary::Byte blue{ 0 };
	};
	std::ostream& operator<<(std::ostream& os, const Color& color);
}
