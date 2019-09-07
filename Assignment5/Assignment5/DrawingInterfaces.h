#pragma once
#include "CodecInterfaces.h"
#include "Point.h"

namespace BitmapGraphics
{
	class ICanvas;
	class IPen;

	using HCanvas = std::shared_ptr<ICanvas>;
	using HPen = std::shared_ptr<IPen>;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;

		virtual void setPixelColor(VG::Point const& location, Color const& color) = 0;
		virtual BitmapGraphics::Color getPixelColor(VG::Point const& location) const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual BitmapGraphics::HBitmapIterator createBitmapIterator() const = 0;
	};

	class IProjector
	{
	public:
		virtual ~IProjector() = default;
		
		virtual void projectCanvas(HCanvas const & canvas) = 0;
	};

	class IPen
	{
	public:
		virtual ~IPen() = default;

		// decide which one of these to keep
		virtual void drawPoint(const HCanvas&, const VG::Point&) = 0;
		virtual void drawPoint(VG::Point const& point) = 0;
	};

	class IStroke
	{
	public:
		virtual ~IStroke() = default;

		virtual void setSize(int size) = 0;
		virtual int getSize() const = 0;
		virtual void setColor(BitmapGraphics::Color const& color) = 0;
		virtual BitmapGraphics::Color getColor() const = 0;
		virtual HPen createPen(HCanvas const& canvas) = 0;
	};
}
