#pragma once
#include "DrawingInterfaces.h"

namespace VG
{
	class WindowsBitmapFileProjector : public IProjector
	{
	public:
		WindowsBitmapFileProjector() = default;
		WindowsBitmapFileProjector(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector(WindowsBitmapFileProjector&& other) = default;

		WindowsBitmapFileProjector& operator=(const WindowsBitmapFileProjector& other) = default;
		WindowsBitmapFileProjector& operator=(WindowsBitmapFileProjector&& other) = default;
		~WindowsBitmapFileProjector() = default;
	};
}

