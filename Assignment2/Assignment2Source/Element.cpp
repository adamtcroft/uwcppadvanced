#include "Element.h"

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

	std::string const& Element::getAttribute(const std::string& key)
	{
		return attributes[key];
	}

	AttributeMap const& Element::getAttributes() const
	{
		return attributes;
	}

	Element::ElementList Element::getChildElements()
	{

	}

	std::string const& Element::getName() const
	{
		return name;
	}
}
