#include "Element.h"

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

	void Element::setAttribute(const std::string& name, const std::string& value)
	{
		myElement->SetAttribute(name.c_str(), value.c_str());
	}

	void Element::addChild(HElement& child)
	{
		childElements.push_back(child);
	}

	HElement Element::appendChild(const std::string& name) noexcept
	{
		auto newElement = new Element(myElement->GetDocument()->NewElement(name.c_str()));
		
		myElement->InsertEndChild(newElement->myElement);

		HElement handleToElement{ dynamic_cast<IElement*>(newElement) };
		return std::move(handleToElement);
	}

	std::string const& Element::getAttribute(const std::string& name) noexcept
	{
		auto result = myElement->Attribute(name.c_str());
		return (result == nullptr) ? "" : result;
	}

	AttributeMap const& Element::getAttributes() const noexcept
	{
		AttributeMap attributes;

		auto attribute = myElement->FirstAttribute();

		while (attribute != nullptr)
		{
			attributes.emplace(attribute->Name, attribute->Value);
			attribute = attribute->Next();
		}

		return std::move(attributes);
	}

	ElementCollection const& Element::getChildElements() const noexcept
	{
		ElementCollection elements;

		if (!myElement->NoChildren())
		{
			for (tinyxml2::XMLElement* node = myElement->FirstChildElement(); node != nullptr; node->NextSiblingElement())
			{
				auto element = new Element(node);
				elements.emplace_back(dynamic_cast<IElement*>(element));
			}
		}
		
		return std::move(elements);
	}

	std::string const& Element::getName() const noexcept
	{
		return std::move(std::string(myElement->Name()));
	}

	//HElement Element::operator[](int i)
	//{
	//	return childElements[i];
	//}
}
