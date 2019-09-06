#pragma once
#include "BitmapDecorator.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

namespace BitmapGraphics
{
	class RandomDecorator : public BitmapDecorator
	{
	public:
		RandomDecorator(HBitmapIterator const& iterator);
		~RandomDecorator() = default;

		Color getColor() const override;

	private:
		unsigned seed{ 0 };
	};
}

