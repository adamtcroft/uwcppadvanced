#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class ColorSwapDecorator : public BitmapDecorator
	{
	public:
		ColorSwapDecorator(HBitmapIterator const& iterator, int adjustment);
		~ColorSwapDecorator() = default;

		Color getColor() const override;

	private:
		int swapChoice{ 0 };
	};

}
