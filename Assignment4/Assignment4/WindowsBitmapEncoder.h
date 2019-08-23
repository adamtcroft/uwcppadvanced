#pragma once
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder() = default;

		WindowsBitmapEncoder(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder&& other) = default;

		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&& other) = default;

		~WindowsBitmapEncoder() noexcept = default;

		HBitmapEncoder clone() override;
		void encodeToStream() override;
		std::string getMimeType();

	private:
		//IBitmapIterator myIterator;
	};
}

