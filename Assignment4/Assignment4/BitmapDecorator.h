#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BitmapDecorator :	public IBitmapIterator
	{
	public:
		BitmapDecorator() = default;
		BitmapDecorator(HBitmapIterator const& iterator);
		virtual ~BitmapDecorator() = default;

		void nextScanLine() override;
		bool isEndOfImage() override;
		void nextPixel() override;
		bool isEndOfScanLine() override;
		int getBitmapWidth() const override;
		int getBitmapHeight() const override;
		int getBitmapFileSize() const override;

	protected:
		HBitmapIterator originalIterator;
	};

}

