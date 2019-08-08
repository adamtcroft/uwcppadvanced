#include "Element.h"
#include <iostream>

namespace Xml
{
	Element::Element() :
		myXMLDocument{ std::make_shared <tinyxml2::XMLDocument>() },
		myElement { myXMLDocument->RootElement()}
	{
	}

	Element::Element(const std::string& name) : 
		myXMLDocument{ std::make_shared <tinyxml2::XMLDocument>() },
		myElement { myXMLDocument->RootElement()}
	{
		myElement = myXMLDocument->NewElement(name.c_str());
		myElement->SetName(name.c_str());
	}

	Element::Element(tinyxml2::XMLElement* node) :
		myXMLDocument{ nullptr },
		myElement { node }
	{
	}

	void Element::createFromXml(std::string& xmlStr)
	{
		if (myXMLDocument->Parse(xmlStr.c_str()) != tinyxml2::XML_SUCCESS)
		{
			throw std::runtime_error("Error Parsing XML Stream");
		}

		myElement = myXMLDocument->RootElement();
	}

	void Element::setName(const std::string& initialName)
	{
		name = initialName;
	}

	void Element::setAttribute(const std::string& key, const std::string& value)
	{
		attributes[key] = value;
	}

	void Element::addChild(HElement& child)
	{
		childElements.push_back(child);
	}

	std::string const& Element::getAttribute(const std::string& key) noexcept
	{
		auto result = attributes.find(key);
		if (result != attributes.end())
			return attributes[key];
		else
			return "";
	}

	AttributeMap const& Element::getAttributes() const noexcept
	{
		return attributes;
	}

	ElementCollection const& Element::getChildElements() const noexcept
	{
		return childElements;
	}

	std::string const& Element::getName() const noexcept
	{
		return name;
	}

	HElement Element::operator[](int i)
	{
		return childElements[i];
	}
}
