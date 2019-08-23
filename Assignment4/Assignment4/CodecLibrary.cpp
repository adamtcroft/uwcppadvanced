#include "CodecLibrary.h"

namespace BitmapGraphics
{
	void CodecLibrary::registerEncoder(HBitmapEncoder const& encoder)
	{

	}

	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{

	}

	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		HBitmapDecoder temp;
		return temp;
	}
	
	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		HBitmapDecoder temp;
		return temp;
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator)
	{
		HBitmapEncoder temp;
		return temp;
	}
}
