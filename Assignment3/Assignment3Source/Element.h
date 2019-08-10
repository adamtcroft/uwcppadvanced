//#pragma once
//#include <list>
//#include <vector>
//#include <map>
//#include <cstring>
//#include "XmlInterfaces.h"
//#include "../tinyxml2-master/tinyxml2.h"
//
//namespace Xml
//{
//	class Element : public IElement
//	{
//	public:
//		Element();
//		Element(const std::string& name);
//		Element(tinyxml2::XMLElement* node);
//
//		void createFromXml(std::string& xmlStr);
//		
//		Element(const Element& other) = delete;
//		Element(Element&& other) = delete;
//
//		Element& operator=(const Element& other) = delete;
//		Element& operator=(Element&& other) = delete;
//
//		~Element() = default;
//
//		void setName(const std::string& initialName);
//		void setAttribute(const std::string& name, const std::string& value);
//		void addChild(HElement& child);
//		HElement appendChild(const std::string& name) noexcept;
//
//		std::string const& getAttribute(const std::string& name) noexcept override;
//		AttributeMap const& getAttributes() const noexcept override;
//		ElementCollection const& getChildElements() const noexcept override;
//		std::string const& getName() const noexcept override;
//
//		//HElement operator[](int i);
//
//	private:
//		Element(tinyxml2::XMLElement* node);
//		std::shared_ptr<tinyxml2::XMLDocument> myXMLDocument;
//		tinyxml2::XMLElement* myElement;
//
//		//Remove???
//		std::string name;
//		//ElementCollection childElements;
//		//AttributeMap attributes;
//	};
//
//}
