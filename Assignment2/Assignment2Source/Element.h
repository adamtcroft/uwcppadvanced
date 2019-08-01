#pragma once
#include <list>
#include <map>
#include <string>

namespace Xml
{
	class Element
	{
	public:
		Element() = default;
		~Element() = default;

		void setAttribute(const std::string& name, const std::string& value);

		std::string const& getAttribute(const std::string& name);
		std::string const& getName();

	private:
		std::list<Element> childElements;
		std::map<std::string, std::string> attributes;
	};
}
