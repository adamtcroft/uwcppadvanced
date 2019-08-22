#include "XmlWriter.h"

void Xml::Writer::writeXml(Xml::HElement& element, std::ostream& os)
{
	return writeElement(element, os);
}

void Xml::Writer::writeElement(const HElement& element, std::ostream& os)
{
	os << "<" << element->getName();
	writeAttributes(element, os);

	ElementCollection childElements{ element->getChildElements() };

	if (childElements.size() > 0)
	{
		os << ">" << std::endl;
	}
	else
	{
		os << "/>" << std::endl;
		return;
	}

	std::for_each(std::begin(childElements), std::end(childElements), [&os](const auto& elem) { writeElement(elem, os); });

	os << "</" << element->getName() << ">" << std::endl;
}

void Xml::Writer::writeAttributes(const HElement& element, std::ostream& os)
{
	AttributeMap attributes = element->getAttributes();

	std::for_each(std::begin(attributes), std::end(attributes), [&os](const auto& attr) { os << " " << attr.first << "=\"" << attr.second << "\""; });
}

//	tinyxml2::XMLDocument xmlDoc;
//
//	auto scene = xmlDoc.NewElement(root->getName().c_str());
//
//	writeAttributes(root, scene);
//	xmlDoc.LinkEndChild(scene);
//
//	buildChildrenRecursively(root, scene);
//
//	xmlDoc.SaveFile("myXml.xml");
//
//void Xml::Writer::writeAttributes(Xml::HElement& root, tinyxml2::XMLElement* element)
//{
//	for (auto attribute : root->getAttributes())
//	{
//		element->SetAttribute(attribute.first.c_str(), attribute.second.c_str());
//	}
//}
//
//void Xml::Writer::buildChildrenRecursively(Xml::HElement& root, tinyxml2::XMLElement* tinyxmlParent)
//{
//
//	for (auto childOfRoot : root->getChildElements())
//	{
//		auto xmlDoc = tinyxmlParent->GetDocument();
//		auto grandchildOfRoot = xmlDoc->NewElement(childOfRoot->getName().c_str());
//		writeAttributes(childOfRoot, grandchildOfRoot);
//		tinyxmlParent->LinkEndChild(grandchildOfRoot);
//		buildChildrenRecursively(childOfRoot, grandchildOfRoot);
//	}
//}
