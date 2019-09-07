#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class BasicCanvasBitmapIterator : public IBitmapIterator
	{
	public:
		BasicCanvasBitmapIterator() = default;
		BasicCanvasBitmapIterator(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator(BasicCanvasBitmapIterator&& other) = default;

		BasicCanvasBitmapIterator& operator=(const BasicCanvasBitmapIterator& other) = default;
		BasicCanvasBitmapIterator& operator=(BasicCanvasBitmapIterator&& other) = default;
		~BasicCanvasBitmapIterator() = default;
	};

}

