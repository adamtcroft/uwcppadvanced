#include "XmlFactories.h"

using namespace Xml;

HElement ElementFactory::createElement(const std::string& name)
{
	//HElement hElem{ dynamic_cast<IElement*>(new Element(name)) };
	HElement hElem = std::make_shared<Element>(name);
	return std::move(hElem);
}

//std::shared_ptr<IXmlReader> ReaderFactory::theReader{ new TinyReader() };

//const IXmlReader& ReaderFactory::getReader()
//{
//	return *theReader;
//}
