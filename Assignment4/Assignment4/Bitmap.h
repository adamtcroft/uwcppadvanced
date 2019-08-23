#pragma once
#include "SizedWord.h"
#include "Color.h"
#include "binary_ostream_iterator.h"
#include "CodecInterfaces.h"
#include <fstream>
#include <vector>
#include <iostream>

namespace BitmapGraphics
{
	class Bitmap
	{
	public:
		using ScanLine = std::vector<Color>;
	private:
		using ScanLineCollection = std::vector<ScanLine>;
	public:
		using ScanLineIterator = ScanLineCollection::iterator;

		Bitmap() = default;
		
		Bitmap(const Bitmap& other) = default;
		Bitmap(Bitmap&& other) noexcept = default;

		Bitmap& operator=(const Bitmap& other) = default;
		Bitmap& operator=(Bitmap&& other) = default;

		~Bitmap() noexcept = default;

		ScanLineIterator begin() noexcept { return slCollection.begin(); }
		ScanLineIterator end() noexcept { return slCollection.end(); }
		uint32_t getWidth() const noexcept { return bitmapWidth; }
		uint32_t getHeight() const noexcept { return bitmapHeight; }

		HBitmapIterator createIterator();
		
	private:
		uint32_t bitmapWidth{ 0 };
		uint32_t bitmapHeight{ 0 };
		ScanLineCollection slCollection;

	};


	//class Bitmap
	//{
	//public:
	//	using ScanLine = std::vector<Color>;
	//private:
	//	using ScanLineCollection = std::vector<ScanLine>;
	//public:
	//	using ScanLineIterator = ScanLineCollection::iterator;

	//	Bitmap() = delete;
	//	Bitmap(const uint32_t& width, const uint32_t& height, std::istream& bitmapStream);

	//	Bitmap(const Bitmap& other) = default;
	//	Bitmap(Bitmap&& other) noexcept = default;

	//	Bitmap& operator=(const Bitmap& other) = default;
	//	Bitmap& operator=(Bitmap&& other) = default;

	//	~Bitmap() noexcept = default;

	//	ScanLineIterator begin() noexcept { return slCollection.begin(); }
	//	ScanLineIterator end() noexcept { return slCollection.end(); }

	//	uint32_t getWidth() const noexcept { return bitmapWidth; }
	//	uint32_t getHeight() const noexcept { return bitmapHeight; }
	//	uint32_t getNumberOfPadBytes() const;

	//	void read(std::istream& sourceStream);
	//	void write(std::ostream& destinationStream);

	//private:
	//	uint32_t bitmapWidth{ 0 };
	//	uint32_t bitmapHeight{ 0 };
	//	ScanLineCollection slCollection;
	//};
}

