#include <memory>
#include <sstream>
#include <memory>
#include <tinyxml2.h>
#include "Element.h"

namespace Xml
{
	using HElement = std::unique_ptr<Element>;
	namespace Reader
	{
		static HElement loadXml(std::stringstream& xmlStream)
		{
			tinyxml2::XMLDocument document;
			auto result = document.Parse(xmlStream.str().c_str());
			auto docRoot = document.RootElement();

			HElement rootElement = std::make_unique<Element>();
			rootElement->setAttribute("name", docRoot->Value());
			auto attribute = docRoot->FirstAttribute();
			while (attribute != nullptr)
			{
				rootElement->setAttribute(attribute->Name(), attribute->Value());
				attribute = attribute->Next();
			}
			return rootElement;
		}
	}
}
