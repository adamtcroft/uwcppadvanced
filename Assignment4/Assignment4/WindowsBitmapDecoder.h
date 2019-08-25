#pragma once
#include "WindowsBitmapHeader.h"
#include "Bitmap.h"
#include "BitmapIterator.h"
#include "Color.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapDecoder : public IBitmapDecoder
	{
	public:
		WindowsBitmapDecoder() = default;
		WindowsBitmapDecoder(std::istream& sourceStream);

		WindowsBitmapDecoder(const WindowsBitmapDecoder& other) = default;
		WindowsBitmapDecoder(WindowsBitmapDecoder&& other) = default;

		WindowsBitmapDecoder& operator=(const WindowsBitmapDecoder& other) = default;
		WindowsBitmapDecoder& operator=(WindowsBitmapDecoder&& other) = default;

		~WindowsBitmapDecoder() noexcept = default;

		HBitmapDecoder clone(std::istream& sourceStream) override;
		HBitmapIterator createIterator() override;
		std::string getMimeType() const noexcept override { return myMimeType; };
		bool isSupported(std::istream& sourceStream) override;
		uint32_t calculatePadBytes() override;

	private:
		Bitmap myBitmap;
		std::string myMimeType;
	};
}