#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator& iterator) :
		myIterator(iterator)
	{
	}

	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& iterator)
	{
		return std::make_unique<WindowsBitmapEncoder>(iterator);
	}

	void WindowsBitmapEncoder::encodeToStream(std::ostream& destinationStream)
	{
		WindowsBitmapHeader header;

		uint32_t fileSize = (myIterator->getBitmapHeight() * myIterator->getBitmapWidth()) * 3 + 54;
		header.setFileSize(fileSize);
		uint32_t width = myIterator->getBitmapWidth();
		header.setBitmapWidth(width);
		uint32_t height = myIterator->getBitmapHeight();
		header.setBitmapHeight(height);

		header.writeFileHeader(destinationStream);
		header.writeInfoHeader(destinationStream);
	
		while (!myIterator->isEndOfImage())
		{
			while (!myIterator->isEndOfScanLine())
			{
				auto color = myIterator->getColor();
				destinationStream << color.getBlue();
				destinationStream << color.getGreen();
				destinationStream << color.getRed();
				myIterator->nextPixel();
			}
			myIterator->nextScanLine();
		}

		//for (auto& scanline : slCollection)
		//{
		//	for (auto& color : scanline)
		//	{
		//		// Write row of pixels
		//		std::copy(scanline.begin(), scanline.end(), binary_ostream_iterator<Color>(destinationStream));

		//		// Write pad bytes
		//		for (auto pad = 0; pad < getNumberOfPadBytes(); ++pad)
		//		{
		//			Binary::Byte(0).write(destinationStream);
		//		}
		//	}
		//}
	}

	std::string WindowsBitmapEncoder::getMimeType() const
	{
		return "Mime Type";
	}
}
