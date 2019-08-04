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

		Writer(const Writer& other) = delete;
		Writer(Writer&& other) = delete;

		Writer& operator=(const Writer& other) = delete;
		Writer& operator=(Writer&& other) = delete;

		~Writer() = delete;

		static void writeXml(Xml::HElement& root, std::ostream& os);

	private:
		static void writeAttributes(Xml::HElement& root, tinyxml2::XMLElement* element);
		static void buildChildrenRecursively(Xml::HElement& root, tinyxml2::XMLElement* tinyxmlElement);
	};
}

