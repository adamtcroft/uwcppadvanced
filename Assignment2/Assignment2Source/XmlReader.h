#pragma once
#include <memory>
#include <sstream>
#include <memory>
#include <tinyxml2.h>
#include "Element.h"

namespace Xml
{
	using HElement = std::unique_ptr<Element>;
	using ElementList = std::list<HElement>;

	namespace Reader
	{
		static void recurse(tinyxml2::XMLElement& docRoot, HElement& rootElement)
		{
			rootElement->setName(docRoot.Value());

			auto attribute = docRoot.FirstAttribute();
			while (attribute != nullptr)
			{
				rootElement->setAttribute(attribute->Name(), attribute->Value());
				attribute = attribute->Next();
			}

			//auto child = docRoot.FirstChildElement();
			//while (child != nullptr)
			//{
			//	HElement childElement = std::make_unique<Element>();
			//	rootElement->addChild(childElement);
			//	recurse(*child, childElement);
			//	child = child->FirstChildElement();
			//}

			//auto sibling = docRoot.NextSiblingElement();
			//while (sibling != nullptr)
			//{
			//	HElement siblingElement = std::make_unique<Element>();
			//	rootElement->addChild(siblingElement);
			//	recurse(*sibling, rootElement);
			//	sibling = sibling->NextSiblingElement();
			//}
		}

		static HElement loadXml(std::stringstream& xmlStream)
		{
			tinyxml2::XMLDocument document;
			auto result = document.Parse(xmlStream.str().c_str());
			auto docRoot = document.RootElement();

			HElement rootElement = std::make_unique<Element>();

			recurse(*docRoot, rootElement);

			return rootElement;
		}
	}
}

// Get the element
// Ge the element's name
// Get the element's attributes
// Check for child element
	// if child element, go to step one
	// else check for siblings
		// if siblings, go to step one
	// go back up
