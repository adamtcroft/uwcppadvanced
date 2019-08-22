#pragma once
#include "SizedWord.h"
//#include "Byte.h"
//#include "DoubleWord.h"
#include "Color.h"
#include <fstream>
#include <vector>
#include <iostream>

namespace BitmapGraphics
{
	class Bitmap
	{
	public:
		using ScanLine = std::vector<Color>;
	private:
		using ScanLineCollection = std::vector<ScanLine>;
	public:
		using ScanLineIterator = ScanLineCollection::iterator;

		Bitmap() = default;
		Bitmap(const uint32_t& width, const uint32_t& height, std::ifstream& bitmapStream);

		Bitmap(const Bitmap& other) = default;
		Bitmap(Bitmap&& other) = default;

		Bitmap& operator=(const Bitmap& other) = default;
		Bitmap& operator=(Bitmap&& other) = default;

		~Bitmap() = default;

		ScanLineIterator begin();
		ScanLineIterator end();

		void write(std::ofstream& bitmapStream);

		const uint32_t& getWidth() const;
		const uint32_t& getHeight() const;

	private:
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		ScanLineCollection slCollection;
	};
}

