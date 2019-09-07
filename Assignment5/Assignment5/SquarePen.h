#pragma once
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class SquarePen final : public IPen
	{
	public:
		SquarePen() = default;
		SquarePen(const SquarePen& other) = default;
		SquarePen(SquarePen&& other) = default;

		SquarePen& operator=(const SquarePen& other) = default;
		SquarePen& operator=(SquarePen&& other) = default;
		~SquarePen() = default;

		virtual void drawPoint(const HCanvas&, const VG::Point&) override final;
		virtual void drawPoint(VG::Point const& point) override final;
	};
}

