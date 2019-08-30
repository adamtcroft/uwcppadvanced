#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BrightnessDecorator : public IBitmapIterator
	{
	public:
		BrightnessDecorator(HBitmapIterator const& iterator);
		~BrightnessDecorator() = default;

		void setBrightnessAdjustment(int adjustment);
		int getBrightnessAdjustment();

		void nextScanLine() override;
		bool isEndOfImage() override;
		void nextPixel() override;
		bool isEndOfScanLine() override;
		Color getColor() const override;
		int getBitmapWidth() const override;
		int getBitmapHeight() const override;
		int getBitmapFileSize() const override;

	private:
		int brightnessAdjustment{ 0 };
		HBitmapIterator originalIterator;
	};
}

