#pragma once
#include <list>
#include <map>
#include <string>

namespace Xml
{
	using AttributeMap = std::map<std::string, std::string>;

	class Element
	{
	using ElementList = std::list<Element>;
	public:
		Element() = default;
		~Element() = default;

		void setName(const std::string& initialName);
		void setAttribute(const std::string& key, const std::string& value);

		std::string const& getAttribute(const std::string& key);
		AttributeMap const& getAttributes() const;
		ElementList getChildElements();
		std::string const& getName() const;

	private:
		std::string name;
		ElementList childElements;
		AttributeMap attributes;
	};
}
