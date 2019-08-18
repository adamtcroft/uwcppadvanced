#include "SizedWord.h"

//template<typename type>
//Binary::SizedWord<type> Binary::SizedWord<type>::SizedWord::readLittleEndian(std::istream& is)
//{
//	return _byteswap_ushort(static_cast<type>(readBigEndian(is)));
//}
//
//const auto readByte = Binary::Byte::read;
//template<typename WordClass>
//Binary::SizedWord<WordClass> Binary::SizedWord<WordClass>::SizedWord::readBigEndian(std::istream& is)
//{
////	Binary::Word word;
////
////	for (auto byte = 0; byte != sizeof(Binary::Word); ++byte) {
////		char c = 0;
////		if (!ss.get(c)) {
////			throw(std::runtime_error("Attempt to read failed."));
////		}
////
////		typename Binary::Word tmp = static_cast<unsigned char>(c); // Otherwise sign extension occurs.
////		word |= tmp << (8 * byte);
////	}
//	return static_cast<uint8_t>(readByte(is)) << 8 | static_cast<uint8_t>(readByte(is));
//}

//template<typename type>
//Binary::SizedWord<type> Binary::SizedWord<type>::SizedWord::writeLittleEndian(std::ostream& os)
//{
//}
//
//template<typename type>
//Binary::SizedWord<type> Binary::SizedWord<type>::SizedWord::writeBigEndian(std::ostream& os)
//{
//}
//
//template<typename type>
//bool Binary::SizedWord<type>::operator==(const SizedWord& rhs) const
//{
//	return (value == rhs.value);
//}
//
//template<typename type>
//bool Binary::SizedWord<type>::operator!=(const SizedWord& rhs) const
//{
//	return !(*this == rhs);
//}
