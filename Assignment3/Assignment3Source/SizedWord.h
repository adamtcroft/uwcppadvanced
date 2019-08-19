#pragma once
#include <fstream>
#include "Byte.h"

namespace Binary
{
	template<class WordClass> class SizedWord
	{
	public:
		static WordClass readBigEndian(std::istream& sourceStream)
		{
			auto word = readLittleEndian(sourceStream);

			if (std::is_same<typename WordClass::datatype, uint16_t>::value)
				word.value = _byteswap_ushort(word.value);

			if (std::is_same<typename WordClass::datatype, uint32_t>::value)
				word.value = _byteswap_ulong(word.value);

			return word;
		}

		static WordClass readLittleEndian(std::istream& sourceStream)
		{
			typename WordClass::datatype word = 0;

			for (auto byte = 0; byte != sizeof(WordClass::datatype); ++byte) {
				char c = 0;
				if (!sourceStream.get(c)) {
					throw(std::runtime_error("Attempt to read failed."));
				}

				typename WordClass::datatype tmp = static_cast<unsigned char>(c); // Otherwise sign extension occurs.
				word |= tmp << (8 * byte);
			}

			return word;
		}

		//static void write(std::ostream& ss) const
		//{
		//	auto nonConst = const_cast<uint32_t*>(&value);
		//	auto valuePtr = reinterpret_cast<char*>(nonConst);
		//	ss.write(valuePtr, sizeof(uint32_t));
		//}
	};
}

