#pragma once
#include "DrawingInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapFileProjector final : public IProjector
	{
	public:
		WindowsBitmapFileProjector() = default;
		WindowsBitmapFileProjector(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&& other) = default;

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&& other) = default;
		~WindowsBitmapFileProjector() = default;

		void projectCanvas(HCanvas const & canvas) override final;
	};
}

