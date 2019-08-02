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

	namespace Reader
	{
		static void loadElements(tinyxml2::XMLElement& docRoot, HElement& rootElement)
		{
			rootElement->setName(docRoot.Value());
			std::cout << rootElement->getName() << std::endl;

			auto attribute = docRoot.FirstAttribute();
			while (attribute != nullptr)
			{
				rootElement->setAttribute(attribute->Name(), attribute->Value());
				std::cout << "Added attribute " << attribute->Name() << " " << attribute->Value() << std::endl;
				attribute = attribute->Next();
			}
				std::cout << std::endl;

			auto child = docRoot.FirstChildElement();
			while (child != nullptr)
			{
				HElement childElement = std::make_unique<Element>();
				rootElement->addChild(childElement);
				std::cout << "Adding Child Element" << std::endl;
				loadElements(*child, childElement);
				break;
			}

			auto sibling = docRoot.NextSiblingElement();
			while (sibling != nullptr)
			{
				HElement siblingElement = std::make_unique<Element>();
				rootElement->addChild(siblingElement);
				std::cout << "Adding Sibling Element" << std::endl;
				loadElements(*sibling, rootElement);
				break;
			}
		}

		static HElement loadXml(std::stringstream& xmlStream)
		{
			tinyxml2::XMLDocument document;
			auto result = document.Parse(xmlStream.str().c_str());
			auto docRoot = document.RootElement();

			HElement rootElement = std::make_unique<Element>();

			loadElements(*docRoot, rootElement);

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
