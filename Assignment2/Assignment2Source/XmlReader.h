#pragma once
#include <memory>
#include <sstream>
#include <memory>
#include <tinyxml2.h>
#include <iostream>
#include <vector>
#include "Element.h"

namespace Xml
{
	using HElement = std::shared_ptr<Element>;
	using ElementList = std::vector<HElement>;

	class Reader
	{
	public:
		Reader() = delete;
		~Reader() = delete;

		static HElement loadXml(std::stringstream& xmlStream);
		static void loadElements(tinyxml2::XMLElement& tinyXMLElement, HElement& currentElement, HElement parentElement = nullptr);
	};
}

