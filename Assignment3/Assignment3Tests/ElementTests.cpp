#include "TestHarness.h"
#include "Element.cpp"
#include "XmlReader.h"

//TEST(getSetName, Element)
//{
//	Xml::Element element;
//	element.setName("test");
//
//	CHECK_EQUAL("test", element.getName());
//}

//TEST(getSetAttribute, Element)
//{
//	Xml::Element element;
//	element.setAttribute("key", "value");
//
//	CHECK_EQUAL("value", element.getAttribute("key"));
//}

//TEST(addGetChild, Element)
//{
//	Xml::Element parent;
//	parent.setName("parent");
//
//	Xml::HElement child = std::make_shared<Xml::Element>();
//	child->setName("child");
//
//	parent.addChild(child);
//
//	for (auto children : parent.getChildElements())
//	{
//		CHECK_EQUAL(child, children);
//	}
//}

//TEST(attributeMap, Element)
//{
//	Xml::Element element;
//	element.setName("test");
//	element.setAttribute("x", "0");
//	
//	auto attributes = element.getAttributes();
//
//	auto x = attributes.find("x");
//
//	CHECK_EQUAL("x", x->first);
//	CHECK_EQUAL("0", x->second);
//}

//TEST(bracketOperator, Element)
//{
//	Xml::Element parent;
//	parent.setName("parent");
//
//	Xml::HElement child = std::make_shared<Xml::Element>();
//	child->setName("child");
//
//	parent.addChild(child);
//
//	CHECK_EQUAL(child, parent[0]);
//}
