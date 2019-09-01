#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class GrayscaleDecorator : public BitmapDecorator
	{
	public:
		GrayscaleDecorator(HBitmapIterator const& iterator);
		~GrayscaleDecorator() = default;

		Color getColor() const override;
	};
}
