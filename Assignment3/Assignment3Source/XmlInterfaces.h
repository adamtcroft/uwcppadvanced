#pragma once
#include <memory>
#include <vector>
#include <map>

namespace Xml
{
	class IElement;
	using HElement = std::shared_ptr<IElement>;
	using ElementCollection = std::vector<HElement>;
	using AttributeMap = std::map<std::string, std::string>;

	class IElement
	{
	public:
		virtual void createFromXml(std::string& xmlStr) = 0;
		
		virtual std::string const& getName() const noexcept = 0;
		virtual void addChild(HElement& child) = 0; // REMOVE THIS??  

		virtual void setName(const std::string& initialName) = 0; // REMOVE THIS??

		virtual void setAttribute(const std::string& name, const std::string& value) = 0;
		virtual std::string const& getAttribute(const std::string& key) noexcept = 0; //REMOVE THIS??
		virtual AttributeMap const& getAttributes() const noexcept = 0;

		virtual ElementCollection const& getChildElements() const noexcept = 0;

		virtual HElement appendChild(const std::string& name) noexcept = 0;
	};

	class IXmlReader
	{
	public:
		virtual HElement loadXml(std::istream& in) const = 0;
	};
}
