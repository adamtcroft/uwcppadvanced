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

bool Framework::operator==(const Framework::Layer& lhs, const Framework::Layer& rhs)
{
	return lhs.graphics == rhs.graphics && lhs.alias == rhs.alias;
}

bool Framework::operator!=(const Framework::Layer& lhs, const Framework::Layer& rhs)
{
	return !(lhs == rhs);
}
