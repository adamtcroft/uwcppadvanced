#pragma once
#include "Color.h"
#include <string>

namespace BitmapGraphics
{
	class IBitmapDecoder;
	class IBitmapEncoder;
	class IBitmapIterator;

	using HBitmapDecoder = std::unique_ptr<IBitmapDecoder>;
	using HBitmapEncoder = std::unique_ptr<IBitmapEncoder>;
	using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

	class IBitmapDecoder
	{
	public:
		virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;
		virtual HBitmapIterator createIterator() = 0;
		virtual std::string getMimeType() const noexcept = 0;
		virtual bool isSupported(std::istream& sourceStream) = 0;
	};

	class IBitmapEncoder
	{
	public: 
		virtual HBitmapEncoder clone() = 0;
		virtual void encodeToStream() = 0;
		virtual std::string getMimeType() const = 0;
	};

	class IBitmapIterator
	{
	public:
		virtual void nextScanLine() = 0;
		virtual bool isEndOfImage() const = 0;
		virtual void nextPixel() = 0;
		virtual bool isEndOfScanLine() = 0;
		virtual BitmapGraphics::Color getColor() const = 0;
		virtual int getBitmapWidth() const = 0;
		virtual int getBitmapHeight() const = 0;
	};
}
