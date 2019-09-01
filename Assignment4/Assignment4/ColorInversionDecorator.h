#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class ColorInversionDecorator : public BitmapDecorator
	{
	public:
		ColorInversionDecorator(HBitmapIterator const& iterator);
		~ColorInversionDecorator() = default;

		Color getColor() const override;
	};
}

