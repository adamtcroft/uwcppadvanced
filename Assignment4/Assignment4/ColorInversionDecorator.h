#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class ColorInversionDecorator : public IBitmapIterator
	{
	public:
		ColorInversionDecorator(HBitmapIterator const& iterator);
		~ColorInversionDecorator() = default;

		void nextScanLine() override;
		bool isEndOfImage() override;
		void nextPixel() override;
		bool isEndOfScanLine() override;
		Color getColor() const override;
		int getBitmapWidth() const override;
		int getBitmapHeight() const override;
		int getBitmapFileSize() const override;

	private:
		HBitmapIterator originalIterator;
	};
}

