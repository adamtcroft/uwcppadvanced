#pragma once
#include <list>
#include <vector>
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
		void addChild(std::shared_ptr<Element>& child);

		std::string const getAttribute(const std::string& key);
		AttributeMap const& getAttributes() const;
		std::vector<std::shared_ptr<Element>> getChildElements();
		std::string const& getName() const;

		std::shared_ptr<Element> operator[](int i);

	private:
		std::string name;
		std::vector<std::shared_ptr<Element>> childElements;
		AttributeMap attributes;
	};

}
