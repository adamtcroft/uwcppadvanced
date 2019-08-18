#pragma once
#include <fstream>

namespace Binary
{
	template<class type> class SizedWord
	{
	public:
		SizedWord() = default;
		SizedWord(type input);
		
		SizedWord(const SizedWord& other) = default;
		SizedWord(SizedWord&& other) = default;

		SizedWord& operator=(const SizedWord& other) = default;
		SizedWord& operator=(SizedWord&& other) = default;

		~SizedWord() = default;

		static SizedWord readLittleEndian(std::istream& is);
		static SizedWord readBigEndian(std::istream& is);

		static SizedWord writeLittleEndian(std::ostream& os);
		static SizedWord writeBigEndian(std::ostream& os);

		bool operator==(const SizedWord& rhs) const;
		bool operator!=(const SizedWord& rhs) const;

		const type& getValue() const
		{
			return value;
		}

		explicit operator type() const { return value; }

	private:
		type value;
	};
}

