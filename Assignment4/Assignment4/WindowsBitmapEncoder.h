#pragma once
#include "WindowsBitmapHeader.h"
#include "Color.h"
#include "CodecInterfaces.h"

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder() = default;
		WindowsBitmapEncoder(HBitmapIterator& iterator);

		WindowsBitmapEncoder(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder(WindowsBitmapEncoder&& other) = default;

		WindowsBitmapEncoder& operator=(const WindowsBitmapEncoder& other) = default;
		WindowsBitmapEncoder& operator=(WindowsBitmapEncoder&& other) = default;

		~WindowsBitmapEncoder() noexcept = default;

		HBitmapEncoder clone(HBitmapIterator& iterator) override;
		void encodeToStream(std::ostream& destinationStream) override;
		std::string getMimeType() const override;
		uint32_t calculatePadBytes() override;

	private:
		HBitmapIterator myIterator;

		void writeHeader(std::ostream& destinationStream);
		void writeScanlines(std::ostream& destinationStream);
	};
}

