#pragma once
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class SlashPen final : public IPen
	{
	public:
		SlashPen() = default;
		SlashPen(const SlashPen& other) = default;
		SlashPen(SlashPen&& other) = default;
		SlashPen& operator=(const SlashPen& other) = default;
		SlashPen& operator=(SlashPen&& other) = default;
		~SlashPen() = default;

		void drawPoint(const HCanvas&, const VG::Point&) override final;
		void drawPoint(VG::Point const& point) override final;

		void setSize(int size) { mySize = size; }

		HPen clone() override;

	private:
		int mySize;
	};
}

