#include "Element.h"
#include "tinyxml2.h"
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

	void Element::addChild(std::unique_ptr<Element>& child)
	{
		std::cout << "in add child" << std::endl;
		//childElements.push_back(child);
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

	std::list<std::unique_ptr<Element>> const Element::getChildElements() const
	{
		std::list<std::unique_ptr<Element>> list;
		return list;
	}

	std::string const& Element::getName() const
	{
		return name;
	}

// Get the element
// Ge the element's name
// Get the element's attributes
// Check for child element
	// if child element, go to step one
	// else check for siblings
		// if siblings, go to step one
	// go back up
		
}
