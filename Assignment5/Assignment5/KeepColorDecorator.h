#pragma once
#include "BitmapDecorator.h"

namespace BitmapGraphics
{
	class KeepColorDecorator : public BitmapDecorator
	{
	public:
		KeepColorDecorator(HBitmapIterator const& iterator, int adjustment);
		~KeepColorDecorator() = default;

		Color getColor() const override;

	private:
		int colorChoice{ 0 };
	};
}

