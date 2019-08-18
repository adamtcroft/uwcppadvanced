#pragma once

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

		static SizedWord readLittleEndian(std::istream& ss);
		static SizedWord readBigEndian(std::istream& ss);

	private:
		type value;
	};
}

