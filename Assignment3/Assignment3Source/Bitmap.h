#pragma once
#include "DoubleWord.h"
#include <fstream>

namespace BitmapGraphics
{
	class Bitmap
	{
	public:
		Bitmap() = default;
		Bitmap(const uint32_t& width, const uint32_t& height, std::ifstream& bitmapStream);
		~Bitmap() = default;

		const uint32_t& getWidth() const;
		const uint32_t& getHeight() const;

	private:
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
	};
}

