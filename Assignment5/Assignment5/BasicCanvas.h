#pragma once
#include "DrawingInterfaces.h"

namespace VG
{
	class BasicCanvas final : public ICanvas
	{
	public:
		BasicCanvas() = default;
		BasicCanvas(const BasicCanvas& other) = default;
		BasicCanvas(BasicCanvas&& other) = default;

		BasicCanvas& operator=(const BasicCanvas& other) = default;
		BasicCanvas& operator=(BasicCanvas&& other) = default;
		~BasicCanvas() = default;

		void setPixelColor(Point const& location, BitmapGraphics::Color const& color) override final;
		BitmapGraphics::Color getPixelColor(Point const& location) const override final;
		int getWidth() const override final;
		int getHeight() const override final;
		BitmapGraphics::HBitmapIterator createBitmapIterator() const override final;
	};
}

