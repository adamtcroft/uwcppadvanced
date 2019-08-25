#include "CodecLibrary.h"

namespace BitmapGraphics
{
	void CodecLibrary::registerEncoder(HBitmapEncoder const& encoder)
	{
		myEncoders.push_back(encoder);
	}

	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{
		myDecoders.push_back(decoder);
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		// this should probably send a string to the decoder to see if it's the correct type or something
		return myDecoders[0]->clone(sourceStream);
	}

	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType, std::istream& sourceStream)
	{
		HBitmapDecoder decoder;

		for (auto decoderProto : myDecoders)
		{
			if (decoderProto->getMimeType() == mimeType)
				decoder = decoderProto->clone(sourceStream);
		}

		if (!decoder)
			throw std::runtime_error("Error: Mime type is unsupported.");
		else
			return decoder;
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType, HBitmapIterator& bitmapIterator)
	{
		HBitmapEncoder encoder;

		for (auto encoderProto : myEncoders)
		{
			if (encoderProto->getMimeType() == mimeType)
				encoder = encoderProto->clone(bitmapIterator);
		}

		if (!encoder)
			throw std::runtime_error("Error: Mime type is unsupported.");
		else
			return encoder;
	}
}
