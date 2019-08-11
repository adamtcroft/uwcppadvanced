#pragma once
//#include <memory>
#include <sstream>
//#include <memory>
#include <iostream>
//#include <vector>
#include "Element.h"
//#include "../tinyxml2-master/tinyxml2.h"

namespace Xml
{
//	using ElementList = std::vector<HElement>;

	class Reader : public IXmlReader
	{
	public:
		Reader() = delete;

		Reader(const Reader& other) = delete;
		Reader(Reader&& other) = delete;

		Reader& operator=(const Reader& other) = delete;
		Reader& operator=(Reader&& other) = delete;

		~Reader() = delete;

		static HElement loadXml(std::stringstream& xmlStream);

//	private:
//		static void loadElements(tinyxml2::XMLElement& tinyXMLElement, HElement& currentElement, HElement parentElement = nullptr);
	};
}

