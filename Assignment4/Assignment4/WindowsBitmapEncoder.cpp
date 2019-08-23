#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics
{
	HBitmapEncoder WindowsBitmapEncoder::clone()
	{
		HBitmapEncoder temp;
		return temp;
	}
	
	void WindowsBitmapEncoder::encodeToStream()
	{

	}

	std::string WindowsBitmapEncoder::getMimeType()
	{
		return "Mime Type";
	}
}
