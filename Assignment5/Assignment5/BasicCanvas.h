#pragma once
#include "DrawingInterfaces.h"

namespace VG
{
	class BasicCanvas : public ICanvas
	{
	public:
		BasicCanvas() = default;
		BasicCanvas(const BasicCanvas& other) = default;
		BasicCanvas(BasicCanvas&& other) = default;

		BasicCanvas& operator=(const BasicCanvas& other) = default;
		BasicCanvas& operator=(BasicCanvas&& other) = default;
		~BasicCanvas() = default;
	};
}

