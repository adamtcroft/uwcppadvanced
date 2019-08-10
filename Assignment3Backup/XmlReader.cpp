//#include "XmlReader.h"
//
//Xml::HElement Xml::Reader::loadXml(std::stringstream& xmlStream)
//{
//	tinyxml2::XMLDocument document;
//
//	auto result = document.Parse(xmlStream.str().c_str());
//	auto docRoot = document.RootElement();
//
//	HElement rootElement = std::make_unique<Element>();
//
//	loadElements(*docRoot, rootElement);
//
//	return rootElement;
//}
//
//void Xml::Reader::loadElements(tinyxml2::XMLElement& tinyXMLElement, HElement& currentElement, HElement parentElement)
//{
//	currentElement->setName(tinyXMLElement.Value());
//
//	auto tinyXMLAttribute = tinyXMLElement.FirstAttribute();
//	while (tinyXMLAttribute != nullptr)
//	{
//		currentElement->setAttribute(tinyXMLAttribute->Name(), tinyXMLAttribute->Value());
//		tinyXMLAttribute = tinyXMLAttribute->Next();
//	}
//
//	auto tinyXMLChild = tinyXMLElement.FirstChildElement();
//	while (tinyXMLChild != nullptr)
//	{
//		HElement childElement = std::make_unique<Element>();
//		currentElement->addChild(childElement);
//		loadElements(*tinyXMLChild, childElement, currentElement);
//		break;
//	}
//
//	auto tinyXMLSibling = tinyXMLElement.NextSiblingElement();
//	while (tinyXMLSibling != nullptr)
//	{
//		HElement siblingElement = std::make_unique<Element>();
//		parentElement->addChild(siblingElement);
//		loadElements(*tinyXMLSibling, siblingElement, parentElement);
//		break;
//	}
//}
