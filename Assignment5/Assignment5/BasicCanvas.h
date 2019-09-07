#pragma once
#include "DrawingInterfaces.h"
#include <vector>

namespace BitmapGraphics
{
	class BasicCanvas final : public ICanvas
	{
	public:
		using ScanLine = std::vector<Color>;
	private:
		using ScanLineCollection = std::vector<ScanLine>;
	public:
		using ScanLineCollectionIterator = ScanLineCollection::iterator;
	public:
		BasicCanvas() = default;
		BasicCanvas(int width, int height, Color const& background);
		BasicCanvas(const BasicCanvas& other) = default;
		BasicCanvas(BasicCanvas&& other) = default;

		BasicCanvas& operator=(const BasicCanvas& other) = default;
		BasicCanvas& operator=(BasicCanvas&& other) = default;
		~BasicCanvas() = default;

		void setPixelColor(VG::Point const& location, Color const& color) override final;
		BitmapGraphics::Color getPixelColor(VG::Point const& location) const override final;
		int getWidth() const override final;
		int getHeight() const override final;
		BitmapGraphics::HBitmapIterator createBitmapIterator() const override final;

	private:
		int myWidth{ 10 };
		int myHeight{ 10 };
		Color myBackground{ Binary::Byte(255), Binary::Byte(255), Binary::Byte(255) };
		ScanLineCollection myCollection;

		void initializeCanvas();
	};
}

