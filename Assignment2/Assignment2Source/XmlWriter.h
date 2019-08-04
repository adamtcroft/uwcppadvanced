#pragma once
#include "XmlReader.h"
#include <tinyxml2.h>
#include <fstream>

namespace Xml
{
	class Writer
	{
	public:
		Writer() = delete;
		~Writer() = delete;

		static void writeXml(Xml::HElement& root, std::ostream& os);
		static void setAttributes(Xml::HElement& root, tinyxml2::XMLElement* element);
		static void buildChildrenRecursively(Xml::HElement& root, tinyxml2::XMLElement* tinyxmlElement);
	};
}

