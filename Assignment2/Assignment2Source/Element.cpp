#include "Element.h"

namespace Xml
{
	void Element::setAttribute(const std::string& name, const std::string& value)
	{
		attributes[name] = value;
	}

	std::string const& Element::getAttribute(const std::string& name)
	{
		return attributes[name];
	}

	std::string const& Element::getName() 
	{
		return attributes["name"];
	}
}
