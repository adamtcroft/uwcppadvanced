#pragma once
#include "CodecInterfaces.h"
#include <fstream>

namespace BitmapGraphics
{
	class CodecLibrary
	{
	public:
		CodecLibrary() = default;

		CodecLibrary(const CodecLibrary& other) = default;
		CodecLibrary(CodecLibrary&& other) noexcept = default;

		CodecLibrary& operator=(const CodecLibrary& other) = default;
		CodecLibrary& operator=(CodecLibrary&& other) = default;

		~CodecLibrary() noexcept = default;

		void registerEncoder(HBitmapEncoder const& encoder);
		void registerDecoder(HBitmapDecoder const& decoder);

		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType, std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType, HBitmapIterator const& bitmapIterator);
	};
}

