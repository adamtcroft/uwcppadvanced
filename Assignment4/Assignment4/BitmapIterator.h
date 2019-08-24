#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BitmapIterator : public IBitmapIterator
	{
	public:
		BitmapIterator() = delete;
		BitmapIterator(uint32_t width, uint32_t height);

		BitmapIterator(const BitmapIterator& other) = default;
		BitmapIterator(BitmapIterator&& other) noexcept = default;

		BitmapIterator& operator=(const BitmapIterator& other) = default;
		BitmapIterator& operator=(BitmapIterator&& other) = default;

		~BitmapIterator() noexcept = default;

		void nextScanLine() override;
		bool isEndOfImage() const override;
		void nextPixel() override;
		bool isEndOfScanLine() override;
		BitmapGraphics::Color getColor() const override;
		int getBitmapWidth() const noexcept override { return myWidth; }
		int getBitmapHeight() const noexcept override { return myHeight; }

	private:
		uint32_t myWidth{ 0 };
		uint32_t myHeight{ 0 };
	};
}

