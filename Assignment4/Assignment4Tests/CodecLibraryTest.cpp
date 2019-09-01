#include "TestHarness.h"

#include "CodecLibrary.h"
#include "BrightnessDecorator.h"
#include "ColorInversionDecorator.h"
#include "GrayscaleDecorator.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "BitmapIterator.h"
#include <fstream>
#include <memory>

using namespace BitmapGraphics;

namespace
{
	const std::string msBmp{ "image/x-ms-bmp" };

	std::shared_ptr<CodecLibrary> theCodecLibrary{};

	void setUp()
	{
		theCodecLibrary.reset(new CodecLibrary);
		theCodecLibrary->registerEncoder(HBitmapEncoder(std::make_shared<WindowsBitmapEncoder>()));
		theCodecLibrary->registerDecoder(HBitmapDecoder(std::make_shared<WindowsBitmapDecoder>()));
	}

	void tearDown()
	{
		theCodecLibrary.reset();
	}

	// algorithm from StackOverflow
	bool equal(const std::string& expected, const std::string& actual) {
		std::ifstream expectedFile(expected, std::ios::binary);
		std::ifstream actualFile(actual, std::ios::binary);

		if (expectedFile.fail() || actualFile.fail()) {
			return false; //file problem
		}

		if (expectedFile.tellg() != actualFile.tellg()) {
			return false; //size mismatch
		}

		//seek back to beginning and use std::equal to compare contents
		expectedFile.seekg(0, std::ifstream::beg);
		actualFile.seekg(0, std::ifstream::beg);

		std::vector<int> eVector;
		std::vector<int> aVector;

		while (!expectedFile.eof())
		{
			eVector.push_back(expectedFile.get());
			aVector.push_back(actualFile.get());

			if (*(eVector.end() - 1) != *(aVector.end() - 1))
			{
				std::cout << "Expected: " << *(eVector.end() - 1) << " Actual: " << *(aVector.end() - 1) << std::endl;
				return false;
			}
		}

		return true;
	}
}

TEST(invalidDecoder, CodecLibrary)
{
	HBitmapDecoder decoder{ std::make_shared<WindowsBitmapDecoder>() };

	try
	{
		decoder->createIterator();
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}
}

TEST(invalidEncoder, CodecLibrary)
{
	HBitmapEncoder encoder{ std::make_shared<WindowsBitmapEncoder>() };

	try
	{
		std::ostringstream os{ std::ios::binary };
		encoder->encodeToStream(os);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}
}

TEST(createEncoderViaMimeType, CodecLibrary)
{
	setUp();

	Bitmap nullBitmap{ 0, 0 };
	HBitmapIterator iterator{ nullBitmap.createIterator() };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, iterator) };

	CHECK(dynamic_cast<WindowsBitmapEncoder*>(encoder.get()));

	tearDown();
}

TEST(failedCreateEncoderViaMimeType, CodecLibrary)
{
	setUp();

	Bitmap nullBitmap{ 0, 0 };
	HBitmapIterator iterator{ nullBitmap.createIterator() };

	try
	{
		HBitmapEncoder encoder{ theCodecLibrary->createEncoder("image/unsupported-type", iterator) };
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}

	tearDown();
}

TEST(createDecoderViaMimeType, CodecLibrary)
{
	setUp();

	std::stringstream ss;
	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(msBmp, ss) };

	CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

	tearDown();
}

TEST(createFailedDecoderViaMimeType, CodecLibrary)
{
	setUp();

	std::stringstream ss;

	try
	{
		HBitmapDecoder decoder{ theCodecLibrary->createDecoder("image/unsupported-type", ss) };
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}

	tearDown();
}

TEST(createDecoderAutoDetermine, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);
	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };

	CHECK(decoder.get());
	CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

	tearDown();
}

TEST(windowsBitmapDecodeEncode, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, iterator) };

	std::ofstream outFile{ "output_basicCopy.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../basicCopy.bmp", "output_basicCopy.bmp"));

	tearDown();
}

TEST(brightnessDecoratorIterator, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator brightnessIterator{ new BrightnessDecorator(iterator, 80) };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, brightnessIterator) };

	std::ofstream outFile{ "output_basicBrightnessAdjusted.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../basicBrightnessAdjusted.bmp", "output_basicBrightnessAdjusted.bmp"));

	tearDown();
}

TEST(brightnessValueOutofBoundsMax, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator brightnessIterator{ new BrightnessDecorator(iterator, 1000) };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, brightnessIterator) };

	std::ofstream outFile{ "output_brightnessOutOfBoundsMax.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../brightnessOutOfBoundsMax.bmp", "output_brightnessOutOfBoundsMax.bmp"));

	tearDown();
}

TEST(brightnessValueOutofBoundsMin, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator brightnessIterator{ new BrightnessDecorator(iterator, -1000) };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, brightnessIterator) };

	std::ofstream outFile{ "output_brightnessOutOfBoundsMin.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../brightnessOutOfBoundsMin.bmp", "output_brightnessOutOfBoundsMin.bmp"));

	tearDown();
}

TEST(colorInvertDecoratorIterator, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator colorInvertIterator{ new ColorInversionDecorator{iterator} };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, colorInvertIterator) };

	std::ofstream outFile{ "output_basicColorInvert.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../basicColorInvert.bmp", "output_basicColorInvert.bmp"));

	tearDown();
}

TEST(grayscaleDecoratorIterator, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator colorInvertIterator{ new GrayscaleDecorator{iterator} };
	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, colorInvertIterator) };

	std::ofstream outFile{ "output_Grayscale.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../Grayscale.bmp", "output_Grayscale.bmp"));

	tearDown();
}

TEST(doubleDecorator, CodecLibrary)
{
	setUp();

	std::ifstream inFile{ "../basic.bmp", std::ios::binary };
	CHECK_EQUAL(0, !inFile);

	HBitmapDecoder decoder{ theCodecLibrary->createDecoder(inFile) };
	HBitmapIterator iterator{ decoder->createIterator() };

	CHECK(iterator.get());
	CHECK_EQUAL(100, iterator->getBitmapHeight());
	CHECK_EQUAL(100, iterator->getBitmapWidth());

	HBitmapIterator colorInvertIterator{ new ColorInversionDecorator{iterator} };
	HBitmapIterator darkenColorInvertIterator{ new BrightnessDecorator{colorInvertIterator, -50} };

	HBitmapEncoder encoder{ theCodecLibrary->createEncoder(msBmp, darkenColorInvertIterator) };

	std::ofstream outFile{ "output_darkInverted.bmp", std::ios::binary };
	encoder->encodeToStream(outFile);
	outFile.close();

	CHECK(equal("../darkInverted.bmp", "output_darkInverted.bmp"));

	tearDown();
}
