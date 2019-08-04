#include "XmlWriter.h"

void Xml::Writer::writeXml(Xml::HElement& root, std::ostream& os)
{
	tinyxml2::XMLDocument xmlDoc;

	auto scene = xmlDoc.NewElement(root->getName().c_str());

	setAttributes(root, scene);
	xmlDoc.LinkEndChild(scene);

	buildChildrenRecursively(root, scene);

	xmlDoc.SaveFile("myXml.xml");
}

void Xml::Writer::setAttributes(Xml::HElement& root, tinyxml2::XMLElement* element)
{
	for (auto attribute : root->getAttributes())
	{
		element->SetAttribute(attribute.first.c_str(), attribute.second.c_str());
	}
}


void Xml::Writer::buildChildrenRecursively(Xml::HElement& root, tinyxml2::XMLElement* tinyxmlParent)
{

	for (auto childOfRoot : root->getChildElements())
	{
		auto xmlDoc = tinyxmlParent->GetDocument();
		auto grandchildOfRoot = xmlDoc->NewElement(childOfRoot->getName().c_str());
		setAttributes(childOfRoot, grandchildOfRoot);
		tinyxmlParent->LinkEndChild(grandchildOfRoot);
		buildChildrenRecursively(childOfRoot, grandchildOfRoot);
	}
}
