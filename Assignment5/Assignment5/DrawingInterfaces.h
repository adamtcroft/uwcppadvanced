#pragma once
#include "CodecInterfaces.h"
#include "Point.h"

namespace VG
{
	class ICanvas;
	class IPen;

	using HCanvas = std::shared_ptr<ICanvas>;
	using HPen = std::shared_ptr<IPen>;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;

		virtual void setPixelColor() = 0;
		virtual BitmapGraphics::HBitmapIterator createBitmapIterator() = 0;
	};

	class IProjector
	{
	public:
		virtual ~IProjector() = default;
		
		virtual void projectCanvas(HCanvas const & canvas) = 0;
	};

	class IPen
	{
		virtual ~IPen() = default;

		virtual void drawPoint(const HCanvas&, const Point&) = 0;
	};

	class IStroke
	{
		virtual ~IStroke() = default;

		virtual HPen createPen() = 0;
	};
}
