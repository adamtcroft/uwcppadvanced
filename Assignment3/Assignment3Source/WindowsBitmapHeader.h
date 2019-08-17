#pragma once
#include <iostream>
#include <fstream>
#include "Byte.h"
#include "Word.h"
#include "DoubleWord.h"

namespace BitmapGraphics
{
	class WindowsBitmapHeader
	{
	public:
		WindowsBitmapHeader() = delete;
		WindowsBitmapHeader(std::ifstream& bitmapStream);

		WindowsBitmapHeader(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader(WindowsBitmapHeader&& other) = default;

		WindowsBitmapHeader& operator=(const WindowsBitmapHeader& other) = default;
		WindowsBitmapHeader& operator=(WindowsBitmapHeader&& other) = default;

		~WindowsBitmapHeader() = default;

		void readFileHeader(std::istream& bitmapStream);
		void readInfoHeader(std::ifstream& bitmapStream);
		Binary::DoubleWord const& getFileSize() const;
		size_t getBitmapWidth() const;
		size_t getBitmapHeight() const;

	private:
		const static Binary::Byte firstIdentifier;
		const static Binary::Byte secondIdentifier;
		Binary::DoubleWord fileSize;
		const static Binary::DoubleWord reserved;
		const static Binary::DoubleWord rawImageByteOffset;

		const static Binary::DoubleWord infoHeaderBytes;
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		const static Binary::Word numberOfPlanes;
		const static Binary::Word bitsPerPixel;
		const static Binary::DoubleWord compressionType;
		const static Binary::DoubleWord compressedImageSize;
		const static Binary::DoubleWord horizontalPixelsPerMeter;
		const static Binary::DoubleWord numberOfColors;
		const static Binary::DoubleWord numberOfImportantColors;
	};
}

