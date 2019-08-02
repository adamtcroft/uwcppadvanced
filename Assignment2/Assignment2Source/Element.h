#pragma once
#include <list>
#include <map>
#include <string>

namespace Xml
{
	using AttributeMap = std::map<std::string, std::string>;

	class Element
	{
	public:
		Element() = default;
		~Element() = default;

		void setName(const std::string& initialName);
		void setAttribute(const std::string& key, const std::string& value);
		void addChild(std::unique_ptr<Element>& child);

		std::string const getAttribute(const std::string& key);
		AttributeMap const& getAttributes() const;
		std::list<std::unique_ptr<Element>> const getChildElements() const;
		std::string const& getName() const;

	private:
		std::string name;
		std::list<std::unique_ptr<Element>> childElements;
		AttributeMap attributes;
	};

}
