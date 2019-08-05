#include "Element.h"
#include <iostream>

namespace Xml
{
	void Element::setName(const std::string& initialName)
	{
		name = initialName;
	}

	void Element::setAttribute(const std::string& key, const std::string& value)
	{
		attributes[key] = value;
	}

	void Element::addChild(std::shared_ptr<Element>& child)
	{
		childElements.push_back(child);
	}

	std::string const Element::getAttribute(const std::string& key)
	{
		auto result = attributes.find(key);
		if (result != attributes.end())
			return attributes[key];
		else
			return "";
	}

	AttributeMap const& Element::getAttributes() const
	{
		return attributes;
	}

	std::vector<std::shared_ptr<Element>> Element::getChildElements()
	{
		return childElements;
	}

	std::string const& Element::getName() const
	{
		return name;
	}

	std::shared_ptr<Element> Element::operator[](int i)
	{
		return childElements[i];
	}
}
