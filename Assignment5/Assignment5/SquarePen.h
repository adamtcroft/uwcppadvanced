#pragma once
#include "DrawingInterfaces.h"

namespace VG
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

		virtual void drawPoint(const HCanvas&, const Point&) override final;
		virtual void drawPoint(Point const& point) override final;
	};
}

