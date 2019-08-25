#pragma once
#include "Bitmap.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BitmapIterator : public IBitmapIterator
	{
	public:
		BitmapIterator(Bitmap& bitmap);

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) = default;

		BitmapIterator& operator=(const BitmapIterator& other) = default;
		BitmapIterator& operator=(BitmapIterator&& other) = default;

		~BitmapIterator() = default;

		void nextScanLine() override;
		bool isEndOfImage() override;
		void nextPixel() override;
		bool isEndOfScanLine() override;
		BitmapGraphics::Color getColor() const override;
		int getBitmapWidth() const noexcept override { return myWidth; }
		int getBitmapHeight() const noexcept override { return myHeight; }

	private:
		uint32_t myWidth{ 0 };
		uint32_t myHeight{ 0 };
		Bitmap* myBitmap;
		BitmapGraphics::Bitmap::ScanLineCollectionIterator rowIterator;
		BitmapGraphics::Bitmap::ScanLine::iterator columnIterator;
	};
}

