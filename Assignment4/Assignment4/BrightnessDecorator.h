#pragma once
#include "BitmapDecorator.h"
#include <algorithm>

namespace BitmapGraphics
{
	class BrightnessDecorator : public BitmapDecorator
	{
	public:
		BrightnessDecorator(HBitmapIterator const& iterator, int adjustment);
		~BrightnessDecorator() = default;

		Color getColor() const override;

	private:
		int brightnessAdjustment{ 0 };
	};
}

