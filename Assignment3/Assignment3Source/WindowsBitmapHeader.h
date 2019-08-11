#pragma once
#include <fstream>

namespace BitmapGraphics
{
	class WindowsBitmapHeader
	{
	public:
		WindowsBitmapHeader();
		WindowsBitmapHeader(std::ifstream& bitmapStream);

		WindowsBitmapHeader(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader(WindowsBitmapHeader&& other) = default;

		WindowsBitmapHeader& operator=(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader& operator=(WindowsBitmapHeader&& other) = default;

		~WindowsBitmapHeader();

		void readFileHeader(std::ifstream& bitmapStream);
		void readInfoHeader(std::ifstream& bitmapStream);
		size_t getFileSize() const;
		size_t getBitmapWidth() const;
		size_t getBitmapHeight() const;
	};
}

