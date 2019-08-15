#pragma once
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
		//Binary::DoubleWord const& getFileSize() const;
		size_t getBitmapWidth() const;
		size_t getBitmapHeight() const;

	private:
		static Binary::Byte firstIdentifier;
		static Binary::Byte secondIdentifier;
		//Binary::DoubleWord fileSize;
		//Binary::DoubleWord reserved = 0;
		//Binary::DoubleWord rawImageByteOffset;

		//Binary::DoubleWord infoHeaderBytes = 40;
		//Binary::DoubleWord bitmapWidth;
		//Binary::DoubleWord bitmapHeight;
		//Binary::Word numberOfPlanes = 1;
		//Binary::Word bitsPerPixel;
		//Binary::DoubleWord compressionType;
		//Binary::DoubleWord compressedImageSize;
		//Binary::DoubleWord horizontalPixelsPerMeter;
		//Binary::DoubleWord numberOfColors;
		//Binary::DoubleWord numberOfImportantColors;
	};
}

