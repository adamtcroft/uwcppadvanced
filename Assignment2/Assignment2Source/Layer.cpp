#include "Layer.h"

Framework::Layer::Layer(std::string&& initialAlias)
	:alias(initialAlias)
{

}

void Framework::Layer::setAlias(std::string& referenceAlias)
{
	alias = referenceAlias;
}

 std::string const& Framework::Layer::getAlias() const
{
	return alias;
}
